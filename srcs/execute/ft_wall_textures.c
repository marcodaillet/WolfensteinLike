/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:56:54 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/24 14:05:10 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_wall_addr(t_info *info)
{
	info->t[0].addr= (int *)mlx_get_data_addr(info->t[0].img, &info->t[0].bpp,
		&info->t[0].line_length, &info->t[0].endian);
	info->t[1].addr= (int *)mlx_get_data_addr(info->t[1].img, &info->t[1].bpp,
		&info->t[1].line_length, &info->t[1].endian);
	info->t[2].addr= (int *)mlx_get_data_addr(info->t[2].img, &info->t[2].bpp,
		&info->t[2].line_length, &info->t[2].endian);
	info->t[3].addr= (int *)mlx_get_data_addr(info->t[3].img, &info->t[3].bpp,
		&info->t[3].line_length, &info->t[3].endian);
}

void	ft_wall_textures(t_info *info)
{
	info->t[0].img = mlx_xpm_file_to_image(info->img.mlx, info->NO,
		&(info->t[0].width), &(info->t[0].height));
	if (!info->t[0].img)
		ft_error(info, "Cannot convert the texture file for the North walls");
	info->t[1].img = mlx_xpm_file_to_image(info->img.mlx, info->SO,
		&(info->t[1].width), &(info->t[1].height));
	if (!info->t[1].img)
		ft_error(info, "Cannot convert the texture file for the South walls");
	info->t[2].img = mlx_xpm_file_to_image(info->img.mlx, info->WE,
		&(info->t[2].width), &(info->t[2].height));
	if (!info->t[2].img)
		ft_error(info, "Cannot convert the texture file for the West walls");
	info->t[3].img = mlx_xpm_file_to_image(info->img.mlx, info->EA,
		&(info->t[3].width), &(info->t[3].height));
	if (!info->t[3].img)
		ft_error(info, "Cannot convert the texture file for the East walls");
	ft_wall_addr(info);
}
