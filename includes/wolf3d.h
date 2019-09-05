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
# define map_W 24
# define map_H 24

typedef struct  s_read
{
	int			cols;
	int			rows;	
	
}               t_read;

// typedef struct  s_vector
// {
// 	double		x;
// 	double		y;
// 	double		z;
// }               t_vector;

typedef struct  s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	
}               t_image;

typedef struct  s_player
{
	t_vector	*pos;
	
	
}               t_player;

typedef struct	s_mlx_image
{
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	char		*raw_data;
	int			width;
	int			height;
	t_read		pos;
}				t_mlx_image;

typedef struct  s_mlx
{
	void*		mlx;
	void*		window;
	t_read		read_info;
	int			**map;
	t_mlx_image	img;
}               t_mlx;




void			put_image(t_mlx *env, t_mlx_image *img);
void			init_image(t_mlx *env, t_mlx_image *img, int width, int height);
void			clear_image(t_mlx_image *img, int colour);
void			pixel_put_image(t_mlx_image *img, int colour, int x, int y);
void			line_delete(void *content, size_t size);
int				exitfun(void *data);
int				exitb(int button);
void			error_check(int error);
int 			read_map(t_mlx *mlx, char **file);
int     		check_map(char *line, t_mlx *env);
int     		count_rows(char *str);
int    		 	count_cols(char *str);
#endif

