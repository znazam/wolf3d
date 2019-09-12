/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:19:08 by znazam            #+#    #+#             */
/*   Updated: 2019/09/11 13:47:20 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	texture(t_mlx *c)
 //choose wall color
    ColorRGB color;
    switch(worldMap[mapX][mapY])
    {
    case 1:  color = red;  break; //red
	case 2:  color = green;  break; //green
    case 3:  color = Blue;   break; //blue
    case 4:  color = white;  break; //white
    default: color = Yellow; break; //yellow
    }
	//give x and y sides different brightness
    if(c->ray.side == 1)
	{
		color = color / 2;
	}
    //draw the pixels of the stripe as a vertical line
    verLine(x, drawStart, drawEnd, color);
    }