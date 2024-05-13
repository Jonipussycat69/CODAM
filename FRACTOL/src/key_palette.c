/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_palette.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 16:45:11 by jdobos        #+#    #+#                 */
/*   Updated: 2024/05/13 16:54:51 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

// FIX LENGTH
void	ft_color_switch_multi(t_fractal *f)
{
	const unsigned int	a_i[] = {BLACK, BLACK, BLACK, C_ANTIQUE_WHITE, C_CORNSILK, WATER, BLACK};
	const unsigned int	a_a[] = {BLACK, C_WHEAT, C_BLANCHED_ALMOND, C_BEIGE, C_BISQUE, C_LIGHT_SKY_BLUE, BLACK};
	const unsigned int	a_b[] = {ORANGE, C_BROWN, C_BROWN, ORANGE, ORANGE, SHORE, BLACK};
	const unsigned int	a_c[] = {C_GOLD, C_BLUE, C_DARK_SLATE_BLUE, WATER, C_CRIMSON, C_CRIMSON, ORANGE};
	const unsigned int	a_d[] = {C_LIGHT_STEEL_BLUE, C_PLUM, C_ANTIQUE_WHITE, C_ANTIQUE_WHITE, C_CORNSILK, WATER, C_LIGHT_STEEL_BLUE};
	static int			i = 0;

	i++;
	if (i == 7)
		i = 0;
	f->c_inf_m = a_i[i];
	f->c_a = hex_to_rgba(a_a[i]);
	f->c_b = hex_to_rgba(a_b[i]);
	f->c_c = hex_to_rgba(a_c[i]);
	f->c_d = hex_to_rgba(a_d[i]);
	re_init_palette(f, mandel);
	f->draw = true;
	if (f->split == true)
	{
		re_init_palette(f, julia);
		f->draw_j = true;
	}
}

void	ft_color_switch(t_fractal *f)
{
	const unsigned int	arr_i[5] = {BLACK, WHITE, LAND, BLACK, WHITE};
	const unsigned int	arr_h[5] = {WHITE, PINK, SHORE, ORANGE, WHITE};
	const unsigned int	arr_l[5] = {BLACK, CYAN, WATER, WHITE, BLACK};
	static int			i = 0;

	if (f->palette == multi)
		return (ft_color_switch_multi(f));
	i++;
	if (i == 5)
		i = 0;
	f->c_inf_n = arr_i[i];
	f->c_high = hex_to_rgba(arr_h[i]);
	f->c_low = hex_to_rgba(arr_l[i]);
	re_init_palette(f, mandel);
	f->draw = true;
	if (f->split == true)
	{
		re_init_palette(f, julia);
		f->draw_j = true;
	}
}

void	palette_switch(t_fractal *f)
{
	if (f->palette == normal)
		f->palette = inverse;
	else if (f->palette == inverse)
		f->palette = zebra;
	else if (f->palette == zebra)
		f->palette = multi;
	else if (f->palette == multi)
		f->palette = normal;
	re_init_palette(f, mandel);
	f->draw = true;
	if (f->split == true)
	{
		re_init_palette(f, julia);
		f->draw_j = true;
	}
}

void	ft_retina_switch(t_fractal *f)
{
	static int	tmp_iterations = 0;

	if (f->retina_mode)
	{
		f->iterations = tmp_iterations;
		re_init_palette(f, mandel);
		f->retina_mode = false;
	}
	else
	{
		f->lock_j = true;
		f->retina_mode = true;
		tmp_iterations = f->iterations;
		f->iterations = RETINA_ITER;
		re_init_palette(f, mandel);
	}
	f->draw = true;
}

void	re_init_palette(t_fractal *f, short set)
{
	if (f->palette == multi)
		f->color_inf = f->c_inf_m;
	else
		f->color_inf = f->c_inf_n;
	if (set == mandel)
	{
		free(f->palette_m);
		if (f->palette == zebra)
			return (z_init_color_palette_m(f, f->iterations));
		if (f->palette == multi)
			return (multi_init_color_palette_m(f, f->iterations));
		init_color_palette_m(f, f->iterations);
		return ;
	}
	if (set == julia)
	{
		free(f->palette_j);
		if (f->palette == zebra)
			return (z_init_color_palette_j(f, f->iterations_j));
		if (f->palette == multi)
			return (multi_init_color_palette_j(f, f->iterations_j));
		init_color_palette_j(f, f->iterations_j);
		return ;
	}
}
