/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:51:14 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/17 18:02:30 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_press(int keycode, t_info *info)
{
	if (keycode == 65307)
		ft_exit(info);
	else if (keycode == FRONT)
		info->mov.front = 1;
	else if (keycode == BACK)
		info->mov.back = 1;
	else if (keycode == LEFT)
		 info->mov.left = 1;
	else if (keycode == RIGHT)
		 info->mov.right = 1;
	else if (keycode == ROTATE_LEFT)
		 info->mov.r_left = 1;
	else if (keycode == ROTATE_RIGHT)
		 info->mov.r_right = 1;
	return (1);
}

int	ft_release(int keycode, t_info *info)
{
	if (keycode == FRONT)
		info->mov.front = 0;
	else if (keycode == BACK)
		info->mov.back = 0;
	else if (keycode == LEFT)
		info->mov.left = 0;
	else if (keycode == RIGHT)
		info->mov.right = 0;
	else if (keycode == ROTATE_LEFT)
		info->mov.r_left = 0;
	else if (keycode == ROTATE_RIGHT)
		info->mov.r_right = 0;
	return (1);
}
