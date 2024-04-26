#include "../lib/fractol.h"

t_uint	rgba_to_hex(t_color c)
{
	t_uint	hex;

	hex = ((t_uint)c.r << 24) | ((t_uint)c.g << 16) | \
	((t_uint)c.b << 8) | (t_uint)c.a;
	return (hex);
}

t_color	hex_to_rgba(t_uint hex)
{
	t_color	c;

	c.r = (hex >> 24) & 0xFF;
	c.g = (hex >> 16) & 0xFF;
	c.b = (hex >> 8) & 0xFF;
	c.a = hex & 0xFF;
	return (c);
}

t_uint	round_to_uint(double n)
{
	return ((t_uint)(n + 0.5));
}
