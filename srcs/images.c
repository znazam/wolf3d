/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:39:57 by znazam            #+#    #+#             */
/*   Updated: 2019/09/05 09:57:13 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	pixel_put_image(t_mlx_image *img, int colour, int x, int y)
{
	int *data;

	if (x >= img->width || x < 0)
		return ;
	if (y >= img->height || y < 0)
		return ;
	data = (int*)&img->raw_data[x * 4 + y * img->size_line];
	*data = colour;
}

void	clear_image(t_mlx_image *img, int colour)
{
	int *data;
	int i;

	data = (int*)img->raw_data;
	i = 0;
	while (i < (img->width * img->height))
	{
		data[i] = colour;
		i++;
	}
}

void	init_image(t_mlx *env, t_mlx_image *img, int width, int height)
{
	img->img_ptr = mlx_new_image(env->mlx, width, height);
	img->raw_data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
	&img->endian);
	img->width = width;
	img->height = height;
	img->pos.cols = 0;
	img->pos.rows = 0;
	clear_image(img, 0x000000);
}

void	put_image(t_mlx *env, t_mlx_image *img)
{
	mlx_put_image_to_window(env->mlx, env->window, img->img_ptr,
	img->pos.cols, img->pos.rows);
}
