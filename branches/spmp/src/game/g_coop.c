// g_coop.c
/*
===========================================================================

Return to Castle Wolfenstein single player GPL Source Code
Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company. 

This file is part of the Return to Castle Wolfenstein single player GPL Source Code (<93>RTCW SP Source Code<94>).  

RTCW SP Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

RTCW SP Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RTCW SP Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the RTCW SP Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the RTCW SP Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#include "g_local.h"
#include "g_coop.h"

#define SPAWNPOINT_ENABLED 1

// fretn - set weapons when player spawns in coop
// in the map dam, the player gets all the weapons, bug !
void SetCoopSpawnWeapons( gclient_t *client ) {

        int pc = client->sess.playerType;

        if ( !(client->ps.eFlags & EF_FROZEN) )
                client->ps.powerups[PW_INVULNERABLE] = level.time + 5000; // some time to find cover

        // zero out all ammo counts
#ifdef MONEY
        if (!client->pers.initialSpawn && g_gametype.integer == GT_COOP_BATTLE) {
                memset( client->ps.ammo,MAX_WEAPONS,sizeof( int ) ); 
        }
#endif

        // Communicate it to cgame
        client->ps.stats[STAT_PLAYER_CLASS] = pc;

        // Abuse teamNum to store player class as well (can't see stats for all clients in cgame)
        //client->ps.teamNum = pc;

        // All players start with a knife (not OR-ing so that it clears previous weapons)
        //client->ps.weapons[0] = 0; 
        //client->ps.weapons[1] = 0; 

        // COM_BitSet( client->ps.weapons, WP_KNIFE );
        // client->ps.ammo[BG_FindAmmoForWeapon( WP_KNIFE )] = 1; 
        //client->ps.weapon = WP_KNIFE;
     
        client->ps.weaponstate = WEAPON_READY;

        // give all the players a binocular
        client->ps.stats[STAT_KEYS] |= ( 1 << INV_BINOCS );

#ifdef MONEY
        // start with mp40 and knife
        if (!client->pers.initialSpawn && g_gametype.integer == GT_COOP_BATTLE) {

                COM_BitSet( client->ps.weapons, WP_KNIFE );
                client->ps.ammo[BG_FindAmmoForWeapon( WP_KNIFE )] = 1; 
                client->ps.weapon = WP_KNIFE;

                COM_BitSet( client->ps.weapons, WP_MP40 );
                client->ps.ammoclip[BG_FindClipForWeapon( WP_MP40 )] += 0;
                client->ps.ammo[BG_FindAmmoForWeapon( WP_MP40 )] += 12;
                client->ps.weapon = WP_MP40;

        }
#endif
        client->pers.initialSpawn = qtrue;
}


void CoopInfoMessage( gentity_t *ent ) {
        char entry[1024];
        char string[1400];
        int stringlength;
        int i, j;
        gentity_t   *player;
        int cnt; 
        int h, a;

        // send the latest information on all clients
        string[0] = 0; 
        stringlength = 0; 

        for ( i = 0, cnt = 0; i < level.numConnectedClients && cnt < TEAM_MAXOVERLAY; i++ ) {
                player = g_entities + level.sortedClients[i];
                if ( player->inuse && player->client->sess.sessionTeam ==
                         ent->client->sess.sessionTeam && !(player->r.svFlags & SVF_CASTAI)) {

                        h = player->client->ps.stats[STAT_HEALTH];
                        a = player->client->ps.stats[STAT_ARMOR];
                        if ( h < 0 ) {
                                h = 0; 
                        }    

                        if ( a < 0 ) {
                                a = 0; 
                        }    
                        // what do we want: clientnum, health, weapon, current amount of ammo
                        Com_sprintf( entry, sizeof( entry ),
                                                 " %i %i %i %i %i %i %i",
                                                 level.sortedClients[i], player->client->pers.teamState.location, h, a,
                                                 player->client->ps.weapon, player->client->ps.ammoclip[BG_FindClipForWeapon( player->client->ps.weapon )], player->client->ps.ammo[BG_FindAmmoForWeapon( player->client->ps.weapon )]);
                        j = strlen( entry );
                        if ( stringlength + j > sizeof( string ) ) {
                                break;
                        }    
                        strcpy( string + stringlength, entry );
                        stringlength += j;
                        cnt++;
                }    
        }    

        trap_SendServerCommand( ent - g_entities, va( "coopinfo %i%s", cnt, string ) );
}

/*
===========
Coop_GetLocation

Report a location for the player. Uses placed nearby target_location entities
============
*/
gentity_t *Coop_GetLocation( gentity_t *ent ) {
        gentity_t       *eloc, *best;
        float bestlen, len;
        vec3_t origin;

        best = NULL;
        bestlen = 3 * 8192.0 * 8192.0;

        VectorCopy( ent->r.currentOrigin, origin );

        for ( eloc = level.locationHead; eloc; eloc = eloc->nextTrain ) {
                len = ( origin[0] - eloc->r.currentOrigin[0] ) * ( origin[0] - eloc->r.currentOrigin[0] )
                          + ( origin[1] - eloc->r.currentOrigin[1] ) * ( origin[1] - eloc->r.currentOrigin[1] )
                          + ( origin[2] - eloc->r.currentOrigin[2] ) * ( origin[2] - eloc->r.currentOrigin[2] );

                if ( len > bestlen ) {
                        continue;
                }

                if ( !trap_InPVS( origin, eloc->r.currentOrigin ) ) {
                        continue;
                }

                bestlen = len;
                best = eloc;
        }

        return best;
}

void CheckCoopStatus( void ) {
        int i;
        gentity_t *loc, *ent;

        if ( level.time - level.lastTeamLocationTime > TEAM_LOCATION_UPDATE_TIME ) {

                level.lastTeamLocationTime = level.time;

                for ( i = 0; i < g_maxclients.integer; i++ ) {
                        ent = g_entities + i;
                        if ( ent->inuse && !(ent->r.svFlags & SVF_CASTAI) ) {
                                loc = Coop_GetLocation( ent );
                                if ( loc ) {
                                        ent->client->pers.teamState.location = loc->health;
                                } else {
                                        ent->client->pers.teamState.location = 0; 
                                }
                                CoopInfoMessage( ent );
                        }
                }
        }
}

/*
================
SelectRandomCoopSpawnPoint

go to a random point that doesn't telefrag
================
*/
#define MAX_SPAWN_POINTS    128
gentity_t *SelectRandomCoopSpawnPoint( vec3_t origin, vec3_t angles ) {
        gentity_t   *spot;
        int count;
        int selection;
        gentity_t   *spots[MAX_SPAWN_POINTS];

        count = 0; 
        spot = NULL;

        while ( ( spot = G_Find( spot, FOFS( classname ), "coop_spawnpoint" ) ) != NULL ) {
                if ( SpotWouldTelefrag( spot ) ) {
                        continue;
                }    

                if (spot->spawnflags & SPAWNPOINT_ENABLED) {
                    spots[ count ] = spot;
                    count++;
                }
        }    

        if ( !count ) { // no spots that won't telefrag
                spot = G_Find( NULL, FOFS( classname ), "coop_spawnpoint" );

                if (spot)
                {
                        if ( !(spot->spawnflags & SPAWNPOINT_ENABLED)) {
                                return NULL;
                        } else {
                                VectorCopy( spot->s.origin, origin );
                                origin[2] += 9;
                                VectorCopy( spot->s.angles, angles );

                                return spot;
                        }
                }
                else
                {
                        return NULL;
                }
        }    

        selection = rand() % count;
        spot = spots[ selection ];

        VectorCopy( spot->s.origin, origin );
        origin[2] += 9;
        VectorCopy( spot->s.angles, angles );

        return spot;
}

// Resets player's current stats
void Coop_DeleteStats( int clientnum ) { 
        gclient_t *cl = &level.clients[clientnum];

	cl->sess.prop_damage = 0;
	cl->sess.airtime = 0;
	cl->sess.pickups = 0;
        cl->sess.damage_given = 0;
        cl->sess.damage_received = 0;
        cl->sess.deaths = 0;
        cl->sess.kills = 0;
        cl->sess.suicides = 0;

        cl->sess.lastBonusLifeScore = 0;
}

// Records accuracy, damage, and kill/death stats.
void Coop_AddStats( gentity_t *targ, gentity_t *attacker, int dmg_ref, int mod ) { 
        int dmg;


	if ( !targ->client && attacker && attacker->client) {
		attacker->client->sess.prop_damage += dmg_ref;	
		return;
	}

        // Keep track of only active player-to-player interactions in a real game
        if ( !targ || !targ->client ||
                 ( g_gametype.integer >= GT_SINGLE_PLAYER && ( targ->s.eFlags == EF_DEAD || targ->client->ps.pm_type == PM_DEAD ) ) ) { 
                return;
        }   

        // Suicides only affect the player specifically
        if ( targ == attacker || !attacker || !attacker->client ) { 
                if ( targ->health <= 0 ) { 
                        targ->client->sess.suicides++;
                }   
                return;
        }   

        // Telefrags only add 100 points.. not 100k!!
        if ( mod == MOD_TELEFRAG ) {
                dmg = 100;
        } else { dmg = dmg_ref;}

        // General player stats
        //if ( mod != MOD_SYRINGE ) {
                if  ( !(targ->r.svFlags & SVF_CASTAI) ) {
                        /*if ( g_friendlyFire.integer == 3 ) {
                                attacker->client->sess.damage_given -= (dmg*2);
                                if (g_gametype.integer != GT_COOP_BATTLE)
                                        attacker->client->ps.persistant[PERS_SCORE] -= (dmg*2);
                        } else {*/
                                attacker->client->sess.damage_given -= dmg;
#ifndef MONEY
                                if (g_gametype.integer != GT_COOP_BATTLE)
                                        attacker->client->ps.persistant[PERS_SCORE] -= dmg;
#else
                                attacker->client->ps.persistant[PERS_SCORE] -= dmg;
#endif
                                targ->client->sess.damage_received += dmg;
                        //}
                } else {
                        attacker->client->sess.damage_given += dmg;
#ifndef MONEY
                        if (g_gametype.integer != GT_COOP_BATTLE)
                                attacker->client->ps.persistant[PERS_SCORE] += dmg;
#else
                        attacker->client->ps.persistant[PERS_SCORE] += dmg;
#endif
                        targ->client->sess.damage_received += dmg;
                }

                if ( targ->health <= 0 ) {
                        attacker->client->sess.kills++;
                        targ->client->sess.deaths++;
                }
        CalculateRanks();
        //}

}

void spawnpoint_trigger_touch( gentity_t *self, gentity_t *other, trace_t *trace );

#define WCP_ANIM_NOFLAG             0
#define WCP_ANIM_RAISE_NAZI         1
#define WCP_ANIM_RAISE_AMERICAN     2
#define WCP_ANIM_NAZI_RAISED        3
#define WCP_ANIM_AMERICAN_RAISED    4
#define WCP_ANIM_NAZI_TO_AMERICAN   5
#define WCP_ANIM_AMERICAN_TO_NAZI   6

void spawnpoint_trigger_use( gentity_t *ent, gentity_t *other, gentity_t *activator ) {
        spawnpoint_trigger_touch( ent, activator, NULL );
}

void spawnpoint_trigger_think( gentity_t *self ) {

        switch ( self->s.frame ) {

        case WCP_ANIM_NOFLAG:
                break;
        case WCP_ANIM_RAISE_NAZI:
                self->s.frame = WCP_ANIM_NAZI_RAISED;
                break;
        case WCP_ANIM_RAISE_AMERICAN:
                self->s.frame = WCP_ANIM_AMERICAN_RAISED;
                break;
        case WCP_ANIM_NAZI_RAISED:
                break;
        case WCP_ANIM_AMERICAN_RAISED:
                break;
        case WCP_ANIM_NAZI_TO_AMERICAN:
                self->s.frame = WCP_ANIM_AMERICAN_RAISED;
                break;
        case WCP_ANIM_AMERICAN_TO_NAZI:
                self->s.frame = WCP_ANIM_NAZI_RAISED;
                break;
        default:
                break;

        }

        self->touch = spawnpoint_trigger_touch;
        self->nextthink = 0;
}


void spawnpoint_trigger_touch( gentity_t *self, gentity_t *other, trace_t *trace ) {
        gentity_t *ent = NULL;
        qboolean named = qfalse;

        /*if ( self->count == other->client->sess.sessionTeam ) {
                return;
        }*/

        // TODO: AI's should be able to recapture the flags
        if (other->r.svFlags & SVF_CASTAI)
                return;

        // Set controlling team
        self->count = other->client->sess.sessionTeam;

        if ( self->s.frame == WCP_ANIM_NOFLAG ) {
                self->s.frame = WCP_ANIM_RAISE_AMERICAN;
                // Play a sound
                G_AddEvent( self, EV_GENERAL_SOUND, self->soundPos1 );
                while ( ( ent = G_Find( ent, FOFS( classname ), "target_location" ) ) != NULL ) { 

                        if ( !ent ) { 
                                break;
                        }    

                        if (!strcmp(ent->targetname, self->target)) {
                                trap_SendServerCommand( -1, va("cp \"%s ^7has secured \nthe %s spawnzone.\n\"", other->client->pers.netname, ent->message) );    
                                named = qtrue;
                                break;
                        }
                } 
            
                if (!named) 
                        trap_SendServerCommand( -1, va("cp \"%s ^7has secured \na new spawnzone.\n\"", other->client->pers.netname) );    

        } else if ( self->s.frame == WCP_ANIM_NAZI_RAISED ) {
                self->s.frame = WCP_ANIM_NAZI_TO_AMERICAN;
                // Play a sound
                G_AddEvent( self, EV_GENERAL_SOUND, self->soundPos1 );
        } else {
                self->s.frame = WCP_ANIM_AMERICAN_RAISED;
        }    


        // Don't allow touch again until animation is finished
        self->touch = NULL;

        self->think = spawnpoint_trigger_think;
        self->nextthink = level.time + 1000;



        // activate all targets
        if ( self->target ) {
                // if you touch a pole, all spawnpoints connected to it are enabled, others are disabled
                // so we first have to disable all of them, and then enable the ones we are targetting
                // we also have to get the other flags down

                // disable all the spawnpoints
                while ( ( ent = G_Find( ent, FOFS( classname ), "coop_spawnpoint" ) ) != NULL ) {
                        if ( !ent ) {
                                break;
                        }    
                        
                        ent->spawnflags &= ~SPAWNPOINT_ENABLED;
                } 

                // now disable all the other flags
                while ( ( ent = G_Find( ent, FOFS( classname ), "coop_spawnpoint_trigger" ) ) != NULL ) {
                        if ( !ent ) {
                                break;
                        }    

                        if ( ent == self)
                                continue;

                        ent->s.frame = WCP_ANIM_NOFLAG;
                }

                // now enable the spawnpoints where targetname == coop_spawnpoint_trigger->target
                while ( 1 ) {
                        ent = G_Find( ent, FOFS( targetname ), self->target );
                        if ( !ent ) {
                                break;
                        }    

                        if ( !strcmp( ent->classname,"coop_spawnpoint" ) ) {
                                ent->spawnflags |= SPAWNPOINT_ENABLED;
                        }    

                }    
        }    


}


/*QUAKED coop_spawnpoint_trigger (.6 .9 .6) (-16 -16 0) (16 16 128) spawnpoint
This is the flagpole players touch enable spawnpoints which are set with with
the same 'targetname' as the 'target' of this entity


It will call specific trigger funtions in the map script for this object.
When allies capture, it will call "allied_capture".
When axis capture, it will call "axis_capture".

*/
void SP_coop_spawnpoint_trigger( gentity_t *ent ) {
        char *capture_sound;

        if (g_spawnpoints.integer != 2)
                return;

        /*if ( !ent->scriptName ) {
                G_Error( "team_WOLF_checkpoint must have a \"scriptname\"\n" );
        }*/

        // Make sure the ET_TRAP entity type stays valid
        ent->s.eType        = ET_TRAP;

        // Model is user assignable, but it will always try and use the animations for flagpole.md3
        if ( ent->model ) {
                ent->s.modelindex   = G_ModelIndex( ent->model );
        } else {
                ent->s.modelindex   = G_ModelIndex( "models/multiplayer/flagpole/flagpole.md3" );
        }

        G_SpawnString( "noise", "sound/movers/doors/door6_open.wav", &capture_sound );
        ent->soundPos1  = G_SoundIndex( capture_sound );

        ent->clipmask   = CONTENTS_SOLID;
        ent->r.contents = CONTENTS_SOLID;

        VectorSet( ent->r.mins, -8, -8, 0 );
        VectorSet( ent->r.maxs, 8, 8, 128 );

        G_SetOrigin( ent, ent->s.origin );
        G_SetAngle( ent, ent->s.angles );

        // s.frame is the animation number
        ent->s.frame    = WCP_ANIM_NOFLAG;

        // s.teamNum is which set of animations to use ( only 1 right now )
        ent->s.teamNum  = 1;

        // Used later to set animations (and delay between captures)
        ent->nextthink = 0;

        // 'count' signifies which team holds the checkpoint
        ent->count = -1;

        ent->touch      = spawnpoint_trigger_touch;
        ent->use        = spawnpoint_trigger_use;       // allow 'capture' from trigger

        trap_LinkEntity( ent );
}
