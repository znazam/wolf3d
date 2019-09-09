/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:03:33 by juboyer           #+#    #+#             */
/*   Updated: 2019/09/09 10:59:32 by juboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    initialize_dda(t_mlx *s)
{
    //length of ray from one x or y-side to next x or y-side
    s->ray.dist.x = abs(1 / s->ray.raydir.x);
    s->ray.dist.y = abs(1 / s->ray.raydir.y);
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