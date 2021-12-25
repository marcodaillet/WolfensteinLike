/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:57:31 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/24 10:42:38 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_tex(t_info *info)
{
	t_tex	tex;

	tex.dir = 0;
	tex.wallx = 0;
	tex.texx = 0;
	tex.texy = 0;
	tex.step = 0;
	tex.texpos = 0;
	info->tex = tex;
}

void	ft_init_ray2(t_info *info, t_ray ray)
{
	ray.stepx = 0;
	ray.stepy = 0;
	ray.hit = 0;
	ray.side = 0;
	ray.lheight = 0;
	ray.dstart = 0;
	ray.dend = 0;
	ray.x = 0;
	ray.tex = 0;
	ray.mapx = 0;
	ray.mapy = 0;
	ray.speed = 0;
	ray.turn_speed = 0;
	info->ray = ray;
	ft_init_tex(info);
}

void	ft_init_ray(t_info *info)
{
	t_ray	ray;

	ray.dirx = 0;
	ray.diry = 0;
	ray.raydirx = 0;
	ray.raydiry = 0;
	ray.viewx = 0;
	ray.viewy = 0;
	ray.sidedistx = 0;
	ray.sidedisty = 0;
	ray.deltadistx = 0;
	ray.deltadisty = 0;
	ray.perpwalldist = 0;
	ray.camerax = 0;
	ray.posx = 0;
	ray.posy = 0;
	ft_init_ray2(info, ray);
}

void	ft_init(t_info *info)
{
	info->map = NULL;
	info->NO = NULL;
	info->SO = NULL;
	info->EA = NULL;
	info->WE = NULL;
	info->nb_lines = 0;
	info->max_length = 0;
	info->f = -1;
	info->c = -1;
	info->dx = 0;
	info->dy = 0;
	info->side = 0;
	info->direction = 0;
	ft_memset(info->F, 0, sizeof(int) * 3);
	ft_memset(info->C, 0, sizeof(int) * 3);
	ft_init_ray(info);
}
