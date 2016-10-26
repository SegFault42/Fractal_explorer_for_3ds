#include "../include/lib3dsft.h"
#include <limits.h>
#include <stdlib.h>

int main(void)
{
	PrintConsole	top_screen;
	t_fractal		fractal;
	u32				kHeld;
	u32				kDown;
	int				color = 50;
	double			speed_move = 0.01;

	sf2d_init_advanced(SF2D_GPUCMD_DEFAULT_SIZE * 6, SF2D_TEMPPOOL_DEFAULT_SIZE * 6);
	sf2d_set_3D(0);
	//=================================n3DS clock==============================
	/*if ((getModel() == 2) || (getModel() == 4))*/
		/*osSetSpeedupEnable(true);*/
	//=========================================================================
	consoleInit(GFX_BOTTOM, &top_screen); // Initialisation de la console sur lecran inferieur
	init_mandelbrot(&fractal);
	//========================================================================//
	while (aptMainLoop())
	{
		hidScanInput(); // scan des touches de la console
		kHeld = hidKeysHeld(); // hidKeysHeld fonction de key repeat
		kDown = hidKeysDown(); // hidKeysHeld fonction de key repeat

		sf2d_start_frame(GFX_TOP, GFX_LEFT);
			draw_mandelbrot1(&fractal, color);
		sf2d_end_frame();

		if (kHeld & KEY_START)
			break;
		if (kHeld & KEY_R)
			fractal.i_max++;
		if (kHeld & KEY_L)
			fractal.i_max--;
		if (kDown & KEY_Y)
			speed_move += 0.01;
		if (kDown & KEY_X)
			speed_move -= 0.01;
		//================================Key_Held=============================
		if (kHeld & KEY_CPAD_LEFT)
			fractal.x1 += speed_move;
		if (kHeld & KEY_CPAD_RIGHT)
			fractal.x1 -= speed_move;
		if (kHeld & KEY_CPAD_UP)
			fractal.y1 += speed_move;
		if (kHeld & KEY_CPAD_DOWN)
			fractal.y1 -= speed_move;
		//=====================================================================
		if (kHeld & KEY_B)
			fractal.zoom /= 1.1;
		if (kHeld & KEY_A)
			fractal.zoom *= 1.1;
		//================================Key_Down=============================
		if (kDown & KEY_DLEFT)
			fractal.x1 += speed_move;
		if (kDown & KEY_DRIGHT)
			fractal.x1 -= speed_move;
		if (kDown & KEY_DUP)
			fractal.y1 += speed_move;
		if (kDown & KEY_DDOWN)
			fractal.y1 -= speed_move;
		//=====================================================================
		sf2d_swapbuffers();
		printf("fps = %2.f\r", sf2d_get_fps());
	}
	sf2d_fini();
	return 0;
}
