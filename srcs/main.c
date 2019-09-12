#include "../includes/wolf3d.h"

int	exitb(int button)
{
	if (button == 53)
		exit(0);
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	ray_cast(mlx);

	return (0);
}

int	exitfun(void *data)
{
	(void)data;
	exit(0);
	return (0);
}

void	wolf3d_init(t_mlx *d)
{
	d->player.pos.x = 2;
	d->player.pos.y = 2;
	d->view.planex = 0;
	d->view.planey = 0.05f;
	d->view.diry = -1;
	d->view.dirx = 0;
}

int	main(int ac, char **av)
{
	t_mlx	*env;
	int		fd;

	if (!(env = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, SCREEN_W, SCREEN_H, "Wolf3d");
	if (ac != 2)
		error_check(2);
	else
	{
		if (!(read_map(env, av)))
			return (0);
		if (fd == -1)
			error_check(0);
		wolf3d_init(env);
		init_image(env, &env->img, SCREEN_W, SCREEN_H);
		//position(&env, av[1]);
		ray_cast(env);
		mlx_loop_hook(env->mlx, expose_hook, env);
		mlx_hook(env->window, 17, 0L, exitfun, env);
		mlx_key_hook(env->window, exitb, 0);
		mlx_loop(env->mlx);
	}
	return (0);
}