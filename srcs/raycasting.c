/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:03:33 by juboyer           #+#    #+#             */
/*   Updated: 2019/09/10 14:36:02 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    initialize_dda(t_mlx *s)
{
    //length of ray from one x or y-side to next x or y-side
    s->ray.dist.x = ABS(1 / s->ray.raydir.x);
    s->ray.dist.y = ABS(1 / s->ray.raydir.y);
    //calculate step and initial side_Dist
    if (s->ray.raydir.x < 0)
    {
        s->ray.steps.x = -1;
        s->ray.side_dist.x = (s->ray.raypos.x - s->ray.ray_map.x) * s->ray.dist.x;
    }
    else
    {
        s->ray.steps.x = 1;
        s->ray.side_dist.x = (s->ray.ray_map.x + 1.0 - s->ray.raypos.x) * s->ray.dist.x;
    }
    if (s->ray.raydir.y < 0)
    {
        s->ray.steps.y = -1;
        s->ray.side_dist.y = (s->ray.raypos.y - s->ray.ray_map.y) * s->ray.dist.y;
    }
    else
    {
        s->ray.steps.y = 1;
        s->ray.side_dist.y = (s->ray.ray_map.y + 1.0 - s->ray.raypos.y) * s->ray.dist.y;
    }
}

void    dda(t_mlx *s)
{
    s->ray.hit = 0;
    //jump to next map square, OR in x-direction, OR in y-direction
    while (s->ray.hit == 0)
    {
        if (s->ray.side_dist.x < s->ray.side_dist.y)
        {
            s->ray.side_dist.x += s->ray.dist.x;
            s->ray.ray_map.x = s->ray.steps.x;
            s->ray.side = 0;
        }
        else
        {
            s->ray.side_dist.y += s->ray.dist.y;
            s->ray.ray_map.y = s->ray.steps.y;
            s->ray.side = 1;
        }
        //Check if ray has hit a wall
        if (s->map[(int)s->ray.ray_map.x][(int)s->ray.ray_map.y] > 0) 
            s->ray.hit = 1;
    }
}

void    initialize_ray(t_mlx *d)
{
	double perpWallDist;

	if (side == 0)
		perpWallDist = (d->ray.ray_map.x - d->pos.x + (1 - d->ray.steps.x) / 2) / d->ray.raydir.x;
    else
		perpWallDist = (d->ray.ray_map.y - d->pos.x + (1 - d->ray.steps.y) / 2) / d->ray.raydir.y;
}