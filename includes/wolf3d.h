#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../libvec/includes/libvec.h"
# include "../GNL/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define SCREEN_W 1000
# define SCREEN_H 1000

typedef struct	s_pixel
{
	int x;
	int y;
}				t_pixel;

typedef struct	s_mlx_image
{
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	char		*raw_data;
	int			width;
	int			height;
	t_pixel		pos;
}				t_mlx_image;

typedef struct	s_coord
{
	float x;
	float y;
	float z;
}				t_coord;

typedef struct	s_env
{
	t_mlx_image	img;
	void		*mlx_ptr;
	void		*win_ptr;
	t_coord		*map;
	int			sizex;
	int			sizey;
	int			sizet;
}				t_env;

void			put_image(t_env *env, t_mlx_image *img);
void			init_image(t_env *env, t_mlx_image *img, int width, int height);
void			clear_image(t_mlx_image *img, int colour);
void			pixel_put_image(t_mlx_image *img, int colour, int x, int y);
void			line_delete(void *content, size_t size);
int				exitfun(void *data);
int				exitb(int button);
void			error_check(int error);
#endif

