/* GIMP RGBA C-Source image dump (rtcwcoop.c) */

static const struct {
	unsigned int width;
	unsigned int height;
	unsigned int bytes_per_pixel; /* 3:RGB, 4:RGBA */
	unsigned char pixel_data[32 * 32 * 4 + 1];
} CLIENT_WINDOW_ICON = {
	32, 32, 4,
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
	"\377\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377"
	"\0\0\377\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\0\0\0\0\377\377\377\377\377\0\0\377\377\0\0\377\377\377\377\377\377\377"
	"\377\377\377\0\0\377\377\0\0\377\377\377\377\377\0\0\0\0\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\0\0\0\0\377\377\377\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377"
	"\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377"
	"\377\377\377\377\377\377\377\377\377\0\0\377\377\0\0\377\377\377\377\377"
	"\377\377\377\377\377\0\0\377\377\0\0\377\377\377\377\377\377\377\377\377"
	"\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377"
	"\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\377\377\377\0\0\0\0"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\377\377"
	"\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\377\377\377"
	"\377\377\377\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0"
	"\377\377\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\0\0\377\377\0\0\377\377\0\0"
	"\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0"
	"\377\377\0\0\377\377\0\0\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377"
	"\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0"
	"\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\377"
	"\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\377\377\377\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0"
	"\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\377\377\377\377"
	"\0\0\377\377\0\0\377\377\377\377\377\377\0\0\377\377\0\0\377\377\0\0\377"
	"\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377\377\0\0\377"
	"\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\377\377"
	"\0\0\377\377\377\377\377\377\0\0\377\377\0\0\377\377\377\377\377\377\0\0"
	"\377\377\0\0\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\0\0\377\377"
	"\0\0\377\377\377\377\377\377\0\0\377\377\0\0\377\377\377\377\377\377\0\0"
	"\377\377\0\0\377\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
	"\377\377\377\0\0\377\377\0\0\377\377\377\377\377\377\0\0\377\377\0\0\377"
	"\377\377\377\377\377\0\0\377\377\0\0\377\377\377\377\377\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\377\377\377\377\377\0\0\377\377\0\0\377\377\377\377\377"
	"\377\0\0\377\377\0\0\377\377\377\377\377\377\0\0\377\377\0\0\377\377\377"
	"\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\0\0\377\377"
	"\0\0\377\377\377\377\377\377\0\0\377\377\0\0\377\377\377\377\377\377\0\0"
	"\377\377\0\0\377\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377"
	"\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0"
	"\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0"
	"\0\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377"
	"\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0"
	"\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\0\0\0"
	"\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\0\0\0\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\377\377\377\377"
	"\0\0\0\377\377\377\377\377\0\0\0\377\377\377\377\377\0\0\0\377\377\377\377"
	"\377\0\0\0\377\377\377\377\377\0\0\0\377\377\377\377\377\0\0\0\377\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\0\0\0\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\0\0\0\377\377\377\377\377\0\0\0\377"
	"\377\377\377\377\0\0\0\377\377\377\377\377\0\0\0\377\377\377\377\377\0\0"
	"\0\377\0\0\0\377\0\0\0\377\377\377\377\377\0\0\0\377\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\377\377\377\377\377\0\0\0\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\0\0\0\377\377\377\377\377\0\0\0\377\377\377\377"
	"\377\0\0\0\377\377\377\377\377\0\0\0\377\377\377\377\377\0\0\0\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\377\377\377\377\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377"
	"\377\377\0\0\0\377\0\0\0\377\0\0\0\377\377\377\377\377\0\0\0\377\0\0\0\377"
	"\0\0\0\377\377\377\377\377\0\0\0\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\0\0\0\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
	"\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\377\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0"
	"\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0"
	"\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\377\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
};
