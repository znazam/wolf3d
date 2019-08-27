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
	t_env	env;
	int		fd;

	if (ac != 2)
		error_check(2);
	else
	{
		if (fd == -1)
			error_check(0);
		init_image(&env, &env.img, SCREEN_W, SCREEN_H);
		mlx_hook(env.win_ptr, 17, 0L, exitfun, &env);
		mlx_key_hook(env.win_ptr, exitb, 0);
		mlx_loop(env.mlx_ptr);
	}
	return (0);
}