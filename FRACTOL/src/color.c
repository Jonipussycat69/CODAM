#include "../lib/fractol.h"

unsigned int	rgba_to_hex(t_color c)
{
	unsigned int	hex;

	hex = ((unsigned int)c.r << 24) | ((unsigned int)c.g << 16) | \
	((unsigned int)c.b << 8) | (unsigned int)c.a;
	return (hex);
}

t_color	hex_to_rgba(unsigned int hex)
{
	t_color	c;

	c.r = (hex >> 24) & 0xFF;
	c.g = (hex >> 16) & 0xFF;
	c.b = (hex >> 8) & 0xFF;
	c.a = hex & 0xFF;
	return (c);
}

unsigned int	round_to_uint(double n)
{
	return ((unsigned int)(n + 0.5));
}
