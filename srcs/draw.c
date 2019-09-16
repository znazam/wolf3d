/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 09:28:36 by juboyer           #+#    #+#             */
/*   Updated: 2019/09/16 09:33:54 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"


void	draw_ground(t_mlx *t, int x, int ground_colour)
{
	int y;

	if (t->ray.end > 0)
	{
		y = t->ray.end - 1;
		if (x < SCREEN_W && y < SCREEN_H)
			while (++y < SCREEN_H)
				ft_memcpy(t->img.raw_data + 4 * SCREEN_W * y + x * 4,
						&ground_colour, sizeof(int));
	}
}

