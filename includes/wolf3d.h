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

# define green 0xFF0000
# define red 0x7CFC00
# define Blue 0x0000FF
# define Yellow	0xFFFF00
# define white 0xFFFFFF
# define exit_b 53
# define D_LEFT 37
# define D_UP 38
# define D_RIGHT 39
# define D_DOWN 40
# define rotSpeed 0.2
# define moveSpeed 1.0
# define green 0xFF0000
# define red 0x7CFC00
# define SCREEN_W 1024
# define SCREEN_H 768
# define map_W 24
# define map_H 24
# define ABS(X) (X < 0 ? -X : X)
//# define posX 22.0
//# define posY 12.0
//# define dirX -1.0
//# define dirY 0.0
//# define planeX 0
//# define planeY 0.66

typedef struct	s_wall
{
	int lineHeight;
	int h;
	int drawStart;
	int drawEnd;
} 				t_wall;

typedef struct	s_read
{
	int			cols;
	int			rows;	
	
}				t_read;

typedef struct	s_view
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_view;

typedef struct	s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	
}				t_image;

typedef struct  s_player
{
	t_vector	pos;
	
	
}				t_player;


typedef struct  s_ray
{
	t_vector	ray_map;
	t_vector	dist;
	t_vector	steps;
	t_vector	raydir;
	t_vector	side_dist;
	t_vector	raypos;
	int			hit;
	int			side;
	int			start;
	int			end;
	float		perpWallDist;
	
	
}				t_ray;

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
	t_player	player;
	t_ray		ray;
	void*		window;
	t_read		read_info;
	int			lineheight;
	int			**map;
	int 		map_width;
	int 		map_height;
	t_mlx_image	img;
	t_view		view;
	t_vector	pos;
	int			fd_test;
}				t_mlx;

void			position(t_mlx *env, const char *filename);
void			draw(t_mlx *s);
void			put_image(t_mlx *env, t_mlx_image *img);
void			init_image(t_mlx *env, t_mlx_image *img, int width, int height);
void			clear_image(t_mlx_image *img, int colour);
void			pixel_put_image(t_mlx_image *img, int colour, int x, int y);
void			line_delete(void *content, size_t size);
int				exitfun(void *data);
void    		initialize_dda(t_mlx *s);
void    		dda(t_mlx *s);
int				exitb(int button);
int				keys(int button);
int				kup(int button);
int				kdown(int button);
int				kright(int button);
int				kleft(int button);
void			error_check(int error);
int				read_map(t_mlx *mlx, char **file);
int				check_map(char *line, t_mlx *env);
int				count_rows(char *str);
int				count_cols(char *str);
void 			ray_cast(t_mlx *d);
void   			initialize_ray(t_mlx *d, int x);
void			draw_ground(t_mlx *t, int x, int ground_colour);

#endif

