#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <limits.h>

# ifndef SIZE
#  define SIZE 10
# endif

# define X 10
# define Y 10
# define Z 10

# define WITH = X * SIZE
# define HEIGHT = Y * SIZE
# define DEPTH = Z * SIZE

# ifndef SPEED
#  define SPEED 10
# endif

# ifndef ROTATIONS
#  define ROTATIONS 10
# endif

# ifndef SPACING
#  define SPACING 10
# endif

#endif