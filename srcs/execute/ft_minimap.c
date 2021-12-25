/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:49:19 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/12 18:47:06 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_drawb(float x, float y, t_info *info)
{
	int i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			if (j == 0)
				my_mlx_pixel_put(&info->img, x + j, y + i, 0x00707070);
			else if (i == 19)
				my_mlx_pixel_put(&info->img, x + j, y + i, 0x00707070);
			else
				my_mlx_pixel_put(&info->img, x + j, y + i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	ft_draws(float x, float y, t_info *info)
{
		int i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			if (j == 0)
				my_mlx_pixel_put(&info->img, x + j, y + i, 0x00707070);
			else if (i == 19)
				my_mlx_pixel_put(&info->img, x + j, y + i, 0x00707070);
			else
				my_mlx_pixel_put(&info->img, x + j, y + i, 0x00505050);
			j++;
		}
		i++;
	}
}

int	ft_draw_player(t_info *info)
{
	int i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(&info->img, info->ray.posy * 20 + i - 2,
				info->ray.posx * 20 + j - 2, 0x00FF0000);
			j++;
		}
		i++;
	}
	i = 0;
	while (i++ < 10)
		my_mlx_pixel_put(&info->img, info->ray.posy * 20 + i * info->ray.diry,
			info->ray.posx * 20 + i * info->ray.dirx, 0x00FF0000);
	return (1);
}

int	ft_draw_map(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->nb_lines)
	{
		x = 0;
		while (x < info->max_length)
		{
			if (info->map[y][x] == '1' || info->map[y][x] == ' '
				|| info->map[y][x] == '\0')
				ft_draws(x * 20, y * 20, info);
			else
				ft_drawb(x * 20, y * 20, info);
			x++;
		}
		y++;
	}
	ft_draw_player(info);
	mlx_put_image_to_window(info->img.mlx, info->img.win, info->img.img, 0, 0);
	return (1);
}
