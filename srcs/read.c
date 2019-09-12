/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 07:55:31 by juboyer           #+#    #+#             */
/*   Updated: 2019/09/11 14:15:18 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		count_cols(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		count_rows(char *str)
{
	int i;
	int rows;

	i = 0;
	rows = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			rows++;
		i++;
	}
	return (rows);
}

int		check_map(char *line, t_mlx *env)
{
	int i;
	int len;
	i = 0;
	len  = 0;
	env->read_info.rows = count_rows(line);
	env->read_info.cols = count_cols(line);
	while(line[i] && line[i] != '\0')
	{
		if((line[i] < 47 || line[i] > 57) && line[i] != ' ' && line[i] != '\n')
			return 0;
		len++;
		if(line[i] == '\n')
		{
			if(len - 1 != env->read_info.cols)
				return (0);
			len = 0;
		}
		i++;
	}
	return (1);
}


int		read_map(t_mlx *mlx, char **av)
{
	int fd;
	int i;
	char *line;

	line = ft_strnew(10000);
	fd = open(av[1], O_RDONLY);
	mlx->fd_test = fd;
	if(fd < 0 || read(fd, line, 10000) < 1)
		return (0);
	if(!check_map(line, mlx))
		return 0;
	while(line[i] != '\n' && line[i] != '\0')
	{
		if(line[i] == ' ')
			mlx->read_info.cols--;
		i++;
	}
	close(fd);
	if(!(mlx->map = (int **)malloc(sizeof(int *) * mlx->read_info.rows)))
		return (0);
	return 1;
}
