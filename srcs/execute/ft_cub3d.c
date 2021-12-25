/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:55:00 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/24 10:39:54 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_loop(t_info *info)
{
	while (info->ray.hit == 0)
	{
		if (info->ray.sidedistx < info->ray.sidedisty)
		{
			info->ray.sidedistx += info->ray.deltadistx;
			info->ray.mapx += info->ray.stepx;
			info->ray.side = 0;
		}
		else
		{
			info->ray.sidedisty += info->ray.deltadisty;
			info->ray.mapy += info->ray.stepy;
			info->ray.side = 1;
		}
		if (info->map[info->ray.mapx][info->ray.mapy] == '1')
			info->ray.hit = 1;
	}
	ft_draw(info);
}

void	ft_sidedist(t_info *info)
{
	if (info->ray.raydirx < 0)
	{
		info->ray.stepx = -1;
		info->ray.sidedistx = (info->ray.posx - info->ray.mapx) \
							* info->ray.deltadistx;
	}
	else
	{
		info->ray.stepx = 1;
		info->ray.sidedistx = (info->ray.mapx + 1.0 - info->ray.posx) \
							* info->ray.deltadistx;
	}
	if (info->ray.raydiry < 0)
	{
		info->ray.stepy = -1;
		info->ray.sidedisty = (info->ray.posy - info->ray.mapy) \
							* info->ray.deltadisty;
	}
	else
	{
		info->ray.stepy = 1;
		info->ray.sidedisty = (info->ray.mapy + 1.0 - info->ray.posy) \
							* info->ray.deltadisty;
	}
	ft_loop(info);
}

void	ft_init_raycast(t_info *info)
{
	info->ray.hit = 0;
	info->ray.perpwalldist = 0;
	info->ray.camerax = 2 * info->ray.x / (double)info->rx - 1;
	info->ray.raydirx = info->ray.dirx + info->ray.viewx * info->ray.camerax;
	info->ray.raydiry = info->ray.diry + info->ray.viewy * info->ray.camerax;
	info->ray.mapx = (int)info->ray.posx;
	info->ray.mapy = (int)info->ray.posy;
	info->ray.speed = 0.2;
	info->ray.turn_speed = 0.043 * 1.8;
	if (info->ray.raydiry == 0)
		info->ray.deltadistx = 0;
	else if (info->ray.raydirx == 0)
		info->ray.deltadistx = 1;
	else
		info->ray.deltadistx = sqrt(1 + (info->ray.raydiry * info->ray.raydiry)
			/ (info->ray.raydirx * info->ray.raydirx));
	if (info->ray.raydirx == 0)
		info->ray.deltadisty = 0;
	else if (info->ray.raydiry == 0)
		info->ray.deltadisty = 1;
	else
		info->ray.deltadisty = sqrt(1 + (info->ray.raydirx * info->ray.raydirx)
			/ (info->ray.raydiry * info->ray.raydiry));
}

int		ft_raycasting(t_info *info)
{
	info->ray.x = 0;
	while (info->ray.x < info->rx)
	{
		ft_init_raycast(info);
		ft_sidedist(info);
		ft_pxl_columns(info);
		info->ray.x++;
	}
	mlx_put_image_to_window(info->img.mlx, info->img.win, info->img.img, 0, 0);
	ft_draw_map(info);
	ft_mov1(info);
	ft_mov2(info);
	ft_mov3(info);
//	ft_rotate(info);
	return (0);
}

void	ft_cub3d(t_info *info)
{
	info->img.mlx = mlx_init();
	ft_wall_textures(info);
	mlx_get_screen_size(info->img.mlx, &info->rx, &info->ry);
	info->img.img = mlx_new_image(info->img.mlx, info->rx, info->ry);
	info->img.addr = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,
		&info->img.line_length, &info->img.endian);
	info->img.win = mlx_new_window(info->img.mlx, info->rx, info->ry, "Cub3d");
	info->img.img2 = mlx_new_image(info->img.mlx, info->rx, info->ry);
	info->img.addr2 = (int *)mlx_get_data_addr(info->img.img2, &info->img.bpp,
		&info->img.line_length, &info->img.endian);
	mlx_hook(info->img.win, 33, 1L << 17, ft_exit, info);
	mlx_hook(info->img.win, 2, 1L << 0, ft_press, info);
	mlx_loop_hook(info->img.mlx, ft_raycasting, info);
	mlx_hook(info->img.win, 3, 1L << 1, ft_release, info);
	mlx_loop(info->img.mlx);
}
