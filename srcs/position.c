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

void		direction_ray(t_vector width, t_view view)
{
	int x;
	int mapx;
	int mapy;
	double sideDistx;
	double sideDisty;


	x = 0;
	mapx = view.posx;
	mapy = view.posy;

	while (x < width.w)
	{
		double cameraX = 2 * x / (width.w) - 1;
		double rayDirX = view.dirx + view.planex * cameraX;
		double rayDirY = view.diry + view.planey * cameraX;
	}
	x++;
}