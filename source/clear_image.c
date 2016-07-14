#include "../include/lib3dsft.h"

void	clear_image(u8 *fb)
{
	memset(fb, 0, 240*400*3);
}
