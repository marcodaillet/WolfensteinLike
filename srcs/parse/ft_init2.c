/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:43:21 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/24 10:55:16 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_dir2(t_info *info)
{
	t_mov	mov;

	mov.front = 0;
	mov.back = 0;
	mov.left = 0;
	mov.right = 0;
	mov.r_left = 0;
	mov.r_right = 0;
	info->mov = mov;
}

void	ft_init_dir(t_info *info)
{
	if (info->direction =='N')
		info->ray.dirx = -1;
	if (info->direction =='S')
		info->ray.dirx = 1;
	if (info->direction =='E')
		info->ray.diry = 1;
	if (info->direction =='W')
		info->ray.diry = -1;
	if (info->direction =='N')
		info->ray.viewy = 0.66;
	if (info->direction =='S')
		info->ray.viewy = -0.66;
	if (info->direction =='E')
		info->ray.viewx = 0.66;
	if (info->direction =='W')
		info->ray.viewx = -0.66;
	info->ray.posx = (double)info->dx + 0.5;
	info->ray.posy = (double)info->dy + 0.5;
	ft_init_dir2(info);
}
