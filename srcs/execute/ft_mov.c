/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:25:34 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/24 10:39:22 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_mov4(t_info *info);

void	ft_mov1(t_info *info)
{
	if (info->mov.front == 1)
	{
		if (info->map[(int)(info->ray.posx + (info->ray.dirx * info->ray.speed
			* 2))][(int)info->ray.posy] == '0')
			info->ray.posx += info->ray.dirx * info->ray.speed;
		if (info->map[(int)(info->ray.posx)][(int)(info->ray.posy + (info->ray.diry
			* info->ray.speed * 2))] == '0')
			info->ray.posy += info->ray.diry * info->ray.speed;
	}
	if (info->mov.back == 1)
	{
		if (info->map[(int)(info->ray.posx - (info->ray.dirx * info->ray.speed
			* 2))][(int)info->ray.posy] == '0')
			info->ray.posx -= info->ray.dirx * info->ray.speed;
		if (info->map[(int)(info->ray.posx)][(int)(info->ray.posy - (info->ray.diry
			* info->ray.speed * 2))] == '0')
			info->ray.posy -= info->ray.diry * info->ray.speed;
	}
}

void    ft_mov2(t_info *info)
{
	if (info->mov.right == 1)
	{
		if (info->map[(int)(info->ray.posx + (info->ray.diry * info->ray.speed
			* 2))][(int)info->ray.posy] == '0')
			info->ray.posx += info->ray.diry * info->ray.speed;
		if (info->map[(int)(info->ray.posx)][(int)(info->ray.posy - (info->ray.dirx
			* info->ray.speed * 2))] == '0')
			info->ray.posy -= info->ray.dirx * info->ray.speed;
	}
	if (info->mov.left == 1)
	{
		if (info->map[(int)(info->ray.posx - (info->ray.diry * info->ray.speed
			* 2))][(int)info->ray.posy] == '0')
			info->ray.posx -= info->ray.diry * info->ray.speed;
		if (info->map[(int)(info->ray.posx)][(int)(info->ray.posy + (info->ray.dirx
			* info->ray.speed * 2))] == '0')
			info->ray.posy += info->ray.dirx * info->ray.speed;
	}
}
void    ft_mov3(t_info *info)
{
	double	i;
	double	j;

	j = info->ray.viewx;
	i = info->ray.dirx;
	if (info->mov.r_right == 1)
	{
		info->ray.dirx = info->ray.dirx * cos(-info->ray.turn_speed / 2) - info->ray.diry * sin(-info->ray.turn_speed / 2);
		info->ray.diry = i * sin(-info->ray.turn_speed / 2) + info->ray.diry * cos(-info->ray.turn_speed / 2);
		info->ray.viewx = info->ray.viewx * cos(-info->ray.turn_speed / 2) - info->ray.viewy * sin(-info->ray.turn_speed / 2);
		info->ray.viewy = j * sin(-info->ray.turn_speed / 2) + info->ray.viewy * cos(-info->ray.turn_speed / 2);
	}
	ft_mov4(info);
}

void	ft_mov4(t_info *info)
{
	double	i;
	double	j;

	j = info->ray.viewx;
	i = info->ray.dirx;
	if (info->mov.r_left == 1)
	{
		info->ray.dirx = info->ray.dirx * cos(info->ray.turn_speed / 2) - info->ray.diry * sin(info->ray.turn_speed / 2);
		info->ray.diry = i * sin(info->ray.turn_speed / 2) + info->ray.diry * cos(info->ray.turn_speed / 2);
		info->ray.viewx = info->ray.viewx * cos(info->ray.turn_speed / 2) - info->ray.viewy * sin(info->ray.turn_speed / 2);
		info->ray.viewy = j * sin(info->ray.turn_speed / 2) + info->ray.viewy * cos(info->ray.turn_speed / 2);
	}
}
