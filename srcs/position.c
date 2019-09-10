#include "../includes/wolf3d.h"

void		position(t_mlx *env, const char *filename)
{
	t_view	*pos;
	double time;
	double oldTime;

	pos->posx = 22;
	pos->posy = 12;
	pos->dirx = -1;
	pos->diry = 0;
	pos->planex = 0;
	pos->planey = 0.66;
	time = 0;
	oldTime = 0;
}

void		draw(t_mlx *s)
{
	int x;
	double cameraX;
	double rayDirX;

	x = 0;
	s->ray.ray_map.x = s->pos.x;
	s->ray.ray_map.y = s->pos.y;

	while (x < SCREEN_W)
	{
		cameraX = 2 * x / (SCREEN_W) - 1;
		s->ray.raydir.x = s->view.dirx + s->view.planex * cameraX;
		s->ray.raydir.y = s->view.diry + s->view.planey * cameraX;
		s->view.dirx = green;
		s->view.diry = red;
		x++;
	}
}