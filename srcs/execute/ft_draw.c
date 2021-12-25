/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:47:37 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/17 19:16:51 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_draw(t_info *info)
{
	if (info->ray.raydirx < 0 && info->ray.side == 0)
		info->tex.dir = 0;
	if (info->ray.raydirx >= 0 && info->ray.side == 0)
		info->tex.dir = 1;
	if (info->ray.raydiry < 0 && info->ray.side == 1)
		info->tex.dir = 2;
	if (info->ray.raydiry >= 0 && info->ray.side == 1)
		info->tex.dir = 3;
	if (info->ray.side == 0)
		info->tex.wallx = info->ray.posy + info->ray.perpwalldist * info->ray.raydiry;
	else
		info->tex.wallx = info->ray.posx + info->ray.perpwalldist * info->ray.raydirx;
	info->tex.wallx -= floor((info->tex.wallx));
}

void	ft_img(t_info *info, int x, int y)
{
	y = info->ray.dstart - 1;
	ft_init_draw(info);
	info->tex.step = 1.0 * info->t[0].height / info->ray.lheight;
	info->tex.texx = (int)(info->tex.wallx * (double)info->t[info->tex.dir].width);
	if ((info->ray.side == 0 && info->ray.raydirx > 0)
		|| (info->ray.side == 1 && info->ray.raydirx < 0))
		info->tex.texx = info->t[info->tex.dir].width - info->tex.texx - 1;
	info->tex.texpos = (info->ray.dstart - info->ry / 2 + info->ray.lheight / 2) * info->tex.step;
	while (++y <= info->ray.dend)
	{
		info->tex.texy = (int)info->tex.texpos & (info->t[info->tex.dir].height - 1);
		info->tex.texpos += info->tex.step;
		if (y < info->ry && x < info->rx)
			info->img.addr[y * info->img.line_length / 4 + x] =
				info->t[info->tex.dir].addr[info->tex.texy * info->t[info->tex.dir].line_length
					/ 4 + info->tex.texx];
	}
}

void	ft_pxl_columns(t_info *info)
{
	int	i;
	int	j;

	j = -1;
	info->ray.dend = info->ry - info->ray.dstart;
	i = info->ray.dend;
	while (++j < info->ray.dstart)
		info->img.addr[j * info->img.line_length / 4 + info->ray.x] = info->c;
	if (j <= info->ray.dend)
		ft_img(info, info->ray.x, j);
	j = i;
	while (++j < info->ry)
		info->img.addr[j * info->img.line_length / 4 + info->ray.x] = info->f;
}

void	ft_draw(t_info *info)
{
	if (info->ray.side == 0)
		info->ray.perpwalldist = ((double)info->ray.mapx - info->ray.posx +
			(1 - (double)info->ray.stepx) / 2) / info->ray.raydirx;
	else
		info->ray.perpwalldist = ((double)info->ray.mapy - info->ray.posy +
			(1 - (double)info->ray.stepy) / 2) / info->ray.raydiry;
	info->ray.lheight = (int)(info->ry / info->ray.perpwalldist);
	info->ray.dstart = -info->ray.lheight / 2 + info->ry / 2;
	if (info->ray.dstart < 0)
		info->ray.dstart = 0;
	info->ray.dend = info->ray.lheight / 2 + info->ry / 2;
	if (info->ray.dend < 0 || info->ray.dend >= info->ry)
		info->ray.dend = info->ry - 1;

}

void	ft_rotate(t_info *info)
{
	void *t;

	t = info->img.img;
	info->img.img = info->img.img2;
	info->img.img2 = t;
	t = info->img.addr;
	info->img.addr = info->img.addr2;
	info->img.addr2 = t;
}
