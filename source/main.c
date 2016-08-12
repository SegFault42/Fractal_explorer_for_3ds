#include "../include/lib3dsft.h"
#include <limits.h>
#include <stdlib.h>

int main(void)
{
	PrintConsole	top_screen;
	t_fractal		fractal;
	int				color = 50;

	gfxInitDefault();
	gfxSet3D(false);
	consoleInit(GFX_BOTTOM, &top_screen); // Initialisation de la console sur lecran inferieur
	consoleSelect(&top_screen);
	gfxSetDoubleBuffering(GFX_TOP, false);

	init_mandelbrot(&fractal);
	//========================================================================//
	while (aptMainLoop())
	{
		hidScanInput(); // scan des touches de la console
		u32 kDown = hidKeysHeld(); // hidKeysHeld fonction de key repeat
		u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
		draw_mandelbrot1(&fractal, fb, color);
		gfxFlushBuffers();
		/*gfxSwapBuffersGpu();*/
		gspWaitForEvent(GSPGPU_EVENT_VBlank0, false);
		/*gspWaitForVBlank();*/
		/*clear_image(fb);*/
		if (kDown & KEY_START)
			break;
		if (kDown & KEY_R)
			fractal.i_max++;
		if (kDown & KEY_L)
			fractal.i_max--;
		if (kDown & KEY_LEFT)
			fractal.x1 += 0.2;
		if (kDown & KEY_RIGHT)
			fractal.x1 -= 0.2;
		if (kDown & KEY_UP)
			fractal.y1 += 0.2;
		if (kDown & KEY_DOWN)
			fractal.y1 -= 0.2;
		if (kDown & KEY_A)
			fractal.zoom *= 0.3;
		if (kDown & KEY_B)
			fractal.zoom /= 0.3;
		/*color = 1+(int) (255.0*rand()/(RAND_MAX+1.0));*/
		color +=10;
		if (color >= 190)
			color = 50;
	}
	//========================================================================//
	gfxExit();
	return 0;
}
