#include "../includes/wolf3d.h"

int	exitb(int button)
{
	if (button == 53)
		exit(0);
	return (0);
}

int	exitfun(void *data)
{
	(void)data;
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	env;
	int		fd;

	env.mlx = mlx_init();
	env.window = mlx_new_window(env.mlx, SCREEN_W, SCREEN_H, "Wold3d");
	if (ac != 2)
		error_check(2);
	else
	{
		if (fd == -1)
			error_check(0);
		init_image(&env, &env.img, SCREEN_W, SCREEN_H);
		position(&env, av[1]);
		mlx_hook(env.window, 17, 0L, exitfun, &env);
		mlx_key_hook(env.window, exitb, 0);
		mlx_loop(env.mlx);
	}
	return (0);
}