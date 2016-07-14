#include "../include/lib3dsft.h"

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->x1 = -2.1;
	fractal->x2 = 0.6;
	fractal->y1 = -1.2;
	fractal->y2 = 1.2;
	fractal->zoom = 100;
	fractal->i_max = 20;
}

void	draw_mandelbrot(t_fractal *fractal, u8 *fb)
{
	for (fractal->x = 0; fractal->x < W_UP; fractal->x++)
	{
		for (fractal->y = 0; fractal->y < H_UP; fractal->y++)
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
					put_pixel(fb, fractal->x, fractal->y, 0, 0, 0);
				else
					put_pixel(fb, fractal->x, fractal->y, fractal->i * 255 / fractal->i_max, 0, 0);
			}
		}
	}
}

int main(void)
{
	PrintConsole	top_screen;
	t_fractal		fractal;

	gfxInitDefault();
	gfxSet3D(false);
	consoleInit(GFX_BOTTOM, &top_screen); // Initialisation de la console sur lecran inferieur
	consoleSelect(&top_screen);
	gfxSetDoubleBuffering(GFX_TOP, false);
	//========================================================================//
	while (aptMainLoop())
	{
		hidScanInput(); // scan des touches de la console
		u32 kDown = hidKeysHeld(); // hidKeysHeld fonction de key repeat
		u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
		init_mandelbrot(&fractal);
		draw_mandelbrot(&fractal, fb);
		gfxFlushBuffers();
		/*gfxSwapBuffersGpu();*/
		gspWaitForEvent(GSPGPU_EVENT_VBlank0, false);
		/*gspWaitForVBlank();*/
		/*clear_image(fb);*/
		if (kDown & KEY_START)
			break;
	}
	//========================================================================//
	gfxExit();
	return 0;
}
