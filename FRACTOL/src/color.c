#include "../lib/fractol.h"

void	color_shift(t_fractal *f)// WHAT DOES THIS ACTUALLY DO?
{
	f->c_range -= 19;// Maybe create waves by changing these vals around? maybe make set green as an island?
	if (f->c_range <= 20)
		f->c_range = UINT32_MAX;
	f->draw = true;
}
