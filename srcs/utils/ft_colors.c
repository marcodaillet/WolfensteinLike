/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:37:02 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/24 10:37:34 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	ft_colors(t_info *info)
{
	info->f = create_rgb(info->F[0], info->F[1], info->F[2]);
	info->c = create_rgb(info->C[0], info->C[1], info->C[2]);
}
