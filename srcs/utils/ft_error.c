/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:12:58 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/11 14:37:21 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_error2(char *str)
{
	printf("Error\n%s\n", str);
	return (ERROR);
}

void	ft_error(t_info *info, char *str)
{
	if (str)
		printf("Error\n%s\n", str);
	ft_free_all(info);
	if (info->img.img)
		mlx_destroy_image(info->img.mlx, info->img.img);
	if (info->img.img2)
		mlx_destroy_image(info->img.mlx, info->img.img2);
	if (info->t[0].img)
		mlx_destroy_image(info->img.mlx, info->t[0].img);
	if (info->t[1].img)
		mlx_destroy_image(info->img.mlx, info->t[1].img);
	if (info->t[2].img)
		mlx_destroy_image(info->img.mlx, info->t[2].img);
	if (info->t[3].img)
		mlx_destroy_image(info->img.mlx, info->t[3].img);
	if (info->img.win)
		mlx_destroy_window(info->img.mlx, info->img.win);
	exit(0);
}

int	ft_exit(t_info *info)
{
	ft_free_all(info);
	if (info->img.img)
		mlx_destroy_image(info->img.mlx, info->img.img);
	if (info->img.img2)
		mlx_destroy_image(info->img.mlx, info->img.img2);
	if (info->t[0].img)
		mlx_destroy_image(info->img.mlx, info->t[0].img);
	if (info->t[1].img)
		mlx_destroy_image(info->img.mlx, info->t[1].img);
	if (info->t[2].img)
		mlx_destroy_image(info->img.mlx, info->t[2].img);
	if (info->t[3].img)
		mlx_destroy_image(info->img.mlx, info->t[3].img);
	if (info->img.win)
		mlx_destroy_window(info->img.mlx, info->img.win);
	exit(0);
	return (0);
}
