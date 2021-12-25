/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:56:13 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/23 12:48:08 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free(void *s)
{
	if (s)
	{
		free(s);
		s = 0;
	}
}

void	ft_freen(char **s, int n)
{
	while (n--)
	{
		if (s[n])
			ft_free(s[n]);
	}
	ft_free(s);
}

void	ft_free_all(t_info *info)
{
	ft_free(info->NO);
	ft_free(info->SO);
	ft_free(info->EA);
	ft_free(info->WE);
	if (info->map)
		ft_freen(info->map, info->nb_lines + 1);
}
