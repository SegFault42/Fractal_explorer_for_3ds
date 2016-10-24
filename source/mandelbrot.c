#include "../include/lib3dsft.h"
#include <stdlib.h>

int color = 10;

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->x1 = -2.1;
	fractal->x2 = 0.6;
	fractal->y1 = -1.2;
	fractal->y2 = 1.2;
	fractal->zoom = 100;
	fractal->i_max = 10;
}

void	draw_mandelbrot1(t_fractal *fractal, int color)
{
	for (fractal->x = 1; fractal->x < W_UP; fractal->x+=4)
	{
		for (fractal->y = 1; fractal->y < H_UP; fractal->y+=4)
		{
			fractal->c_r = fractal->x / fractal->zoom + fractal->x1;
			fractal->c_i = fractal->y / fractal->zoom + fractal->y1;
			fractal->z_r = 0;
			fractal->z_i = 0;
			fractal->i = 0;
			do
			{
				fractal->tmp = fractal->z_r;
				fractal->z_r = (ft_sqrt(fractal->z_r)) - ft_sqrt(fractal->z_i) + fractal->c_r;
				fractal->z_i = 2 * fractal->z_i * fractal->tmp + fractal->c_i;
				fractal->i++;
			}
			while (fractal->z_r * fractal->z_r + fractal->z_i * fractal->z_i < 4 && fractal->i < fractal->i_max);
			{
				if (fractal->i == fractal->i_max)
					sf2d_draw_rectangle(fractal->x, fractal->y, 1, 1, RGBA8(255, 0, 0, 255));
					/*drawPixel(fb, fractal->x, fractal->y, 0x0066ff);*/
				else
				{
					sf2d_draw_rectangle(fractal->x, fractal->y, 1, 1, fractal->i * color / fractal->i_max);
					/*drawPixel(fb, fractal->x, fractal->y, fractal->i * color / fractal->i_max);*/
				}
			}
		}
	}
}
