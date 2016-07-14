#include "../include/lib3dsft.h"

void	draw_rect(u8 *fb, int x1, int x2, int y1, int y2)
{
	int	save_x = x1;

	while (y1 < y2)
	{
		while (x1 < x2)
		{
			if (y1 >= 1 && y1 <= 240)
				if (x1 >= 1 && x1 <= 400)
					put_pixel(fb, x1, y1, 0xFF, 0x00, 0x00);
			x1++;
		}
		x1 = save_x;
		y1++;
	}
}
