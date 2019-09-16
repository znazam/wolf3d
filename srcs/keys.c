/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:41:23 by znazam            #+#    #+#             */
/*   Updated: 2019/09/16 13:50:19 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		keys(int button)
{
	//readKeys();
	if (button == D_UP)
		kup(button);
	if (button == D_DOWN)
		kdown(button);
	if (button == D_RIGHT)
		kright(button);
	if (button == D_LEFT)
		kleft(button);
	if (button == exit_b)
		exitb(button);
	return (0);
}

int		kup(int button)
{
	t_mlx *key;
	//move forward if no wall in front of you
	if (/*keyDown(D_UP)*/button == D_UP)
	{
		if (key->map[(int)(key->player.pos.x + key->view.dirx * moveSpeed)]
			[(int)(key->player.pos.y)] == 0)
			key->player.pos.x += key->view.dirx * moveSpeed;
		if (key->map[(int)(key->player.pos.x)][(int)(key->player.pos.y +
			key->view.diry * moveSpeed)] == 0)
			key->player.pos.y += key->view.diry * moveSpeed;
	}
	return (0);
}

int		kdown(int button)
{
	t_mlx *key;
	//move backwards if no wall behind you
	if (/*keyDown(D_DOWN)*/button == D_DOWN)
	{
		if (key->map[(int)(key->player.pos.x - key->view.dirx * moveSpeed)]
			[(int)(key->player.pos.y)] == 0)
			key->player.pos.x -= key->view.dirx * moveSpeed;
		if (key->map[(int)(key->player.pos.x)][(int)(key->player.pos.y -
			key->view.diry * moveSpeed)] == 0)
			key->player.pos.y -= key->view.diry * moveSpeed;
	}
	return (0);
}

int		kright(int button)
{
	t_mlx *key;
	double olddirx;
	double oldplanex;
	//rotate to the right
	if (/*keyDown(D_RIGHT)*/button == D_RIGHT)
	{
		//both camera direction and camera plane must be rotated
		olddirx = key->view.dirx;
		key->view.dirx = key->view.dirx * cos(-rotSpeed) - key->view.diry *
			sin(-rotSpeed);
		key->view.diry = olddirx * sin(-rotSpeed) + key->view.diry *
			cos(-rotSpeed);
		oldplanex = key->view.planex;
		key->view.planex = key->view.planex * cos(-rotSpeed) - key->view.planey 
			* sin(-rotSpeed);
		key->view.planey = oldplanex * sin(-rotSpeed) + key->view.planey *
			cos(-rotSpeed);
	}
	return (0);
}

int		kleft(int button)
{
	t_mlx *key;
	double olddirx;
	double oldplanex;
	//rotate to the left
	if (/*keyDown(D_LEFT)*/button == D_LEFT)
	{
		//both camera direction and camera plane must be rotated
		olddirx = key->view.dirx;
		key->view.dirx = key->view.dirx * cos(rotSpeed) - key->view.diry *
			sin(rotSpeed);
		key->view.diry = olddirx * sin(rotSpeed) + key->view.diry *
			cos(rotSpeed);
		oldplanex = key->view.planex;
		key->view.planex = key->view.planex * cos(rotSpeed) - key->view.planey *
			sin(rotSpeed);
		key->view.planey = oldplanex * sin(rotSpeed) + key->view.planey *
			cos(rotSpeed);
	}
	return (0);
}
