/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:03:33 by juboyer           #+#    #+#             */
/*   Updated: 2019/09/16 14:04:01 by znazam           ###   ########.fr       */
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
        int x, y;
        x = (int)s->ray.ray_map.x;
        y = (int)s->ray.ray_map.y;
        if (x < 0 || y < 0 || x > 100 || y > 100 || s->map[x][y] > 0) 
            s->ray.hit = 1;
    }
}

void    initialize_ray(t_mlx *d, int x)
{
    double cameraX;

    cameraX = 2 * x / (SCREEN_W) - 1;
    d->ray.raypos.x = d->player.pos.x;
	d->ray.raypos.y = d->player.pos.y;
	d->ray.raydir.x = d->view.dirx + d->view.planex * cameraX;
	d->ray.raydir.y = d->view.diry + d->view.planey * cameraX;
    d->ray.ray_map.x = (int)d->ray.raypos.x;
	d->ray.ray_map.y = (int)d->ray.raypos.y;
    initialize_dda(d);
    dda(d);
    if (d->ray.side == 0)
        d->ray.perpWallDist = (d->ray.ray_map.x - d->pos.x + (1 - d->ray.steps.x) / 2) / d->ray.raydir.x;
    else
        d->ray. perpWallDist = (d->ray.ray_map.y - d->pos.x + (1 - d->ray.steps.y) / 2) / d->ray.raydir.y;

}

void ray_cast(t_mlx *d)
{
    int x = 0;
    
    // d->img.img_ptr = mlx_new_image(d->mlx, SCREEN_W, SCREEN_H);
    // d->img.raw_data = mlx_get_data_addr(d->img.img_ptr,
    //     &d->img.bpp, &d->img.size_line, &d->img.endian);

    while(x < SCREEN_W)
    {   
        initialize_ray(d, x);
        //Calculate height of line to draw on screen
        if (d->ray.perpWallDist != 0)
            d->lineheight = (SCREEN_H / d->ray.perpWallDist);

        //calculate lowest and highest pixel
        d->ray.start = (-d->lineheight / 2) + (SCREEN_H  / 2);
        if( d->ray.start < 0)
             d->ray.start = 0;
        d->ray.end = (d->lineheight / 2) + (SCREEN_H  / 2);
        if( d->ray.end >= SCREEN_H)
             d->ray.end = SCREEN_H - 1;
        draw_ground(d, x, 0x3f3f3f);
        
        //pixel_put_image(&d->img, 0xffffff, x, 100);
        x++;
    }
    mlx_put_image_to_window(d->mlx, d->window, d->img.img_ptr, 0, 0);
	mlx_destroy_image(d->mlx, d->img.img_ptr);
}


