#include "../include/lib3dsft.h"

void	put_pixel(u8 *fb, u16 x, u16 y, u8 red, u8 green, u8 blue)
{
	fb[3 * (240 - y + (x - 1) * 240)] = blue;
	fb[3 * (240 - y + (x - 1) * 240) + 1] = green;
	fb[3 * (240 - y + (x - 1) * 240) + 2] = red;
}

void	drawPixel(u8 *screen, int x, int y, u32 color)
{
	int	idx = ((x)*240) + (239-(y));

	screen[idx*3+0] = (color);
	screen[idx*3+1] = (color) >> 8;
	screen[idx*3+2] = (color) >> 16;
}
