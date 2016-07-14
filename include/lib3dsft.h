#ifndef LIB3DSFT_H
#define LIB3DSFT_H

#include <string.h>
#include <stdio.h>
#include <3ds.h>
#include <math.h>

#define W_UP 400
#define H_UP 240
#define W_BOT 320
#define H_BOT 240

typedef struct	s_fractal
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		i;
	double		tmp;
	int			x;
	int			y;
	double		i_max;
}				t_fractal;

void	put_pixel(u8 *fb, u16 x, u16 y, u8 red, u8 green, u8 blue);
void	draw_rect(u8 *fb, int x1, int x2, int y1, int y2);
void	draw_ellipse(u8 *fb, int x, int y);
void	clear_image(u8 *fb);
double	ft_sqrt(double a);

#endif
