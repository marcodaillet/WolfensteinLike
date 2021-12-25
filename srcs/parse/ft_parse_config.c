/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:38:16 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/07 15:09:47 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_parse_NO(char *line, t_info *info)
{
	char	**split;

	split = ft_split(line, " \t");
	info->NO = ft_strdup(split[1]);
	ft_free(line);
	ft_freen(split, ft_strlen2(split));
}

void	ft_parse_SO(char *line, t_info *info)
{
	char	**split;

	split = ft_split(line, " \t");
	info->SO = ft_strdup(split[1]);
	ft_free(line);
	ft_freen(split, ft_strlen2(split));
}

void	ft_parse_WE(char *line, t_info *info)
{
	char	**split;

	split = ft_split(line, " \t");
	info->WE = ft_strdup(split[1]);
	ft_free(line);
	ft_freen(split, ft_strlen2(split));
}

void	ft_parse_EA(char *line, t_info *info)
{
	char	**split;

	split = ft_split(line, " \t");
	info->EA = ft_strdup(split[1]);
	ft_free(line);
	ft_freen(split, ft_strlen2(split));
}

void	ft_parse_FC(char *line, t_info *info)
{
	char	**split;
	int		i;

	i = 1;
	split = ft_split(line, ", \t");
	if (ft_startw(line, "F") == SUCCESS)
	{
		while (i < 4)
		{
			info->F[i- 1] = ft_atoi(split[i]);
			i++;
		}
	}
	else
	{
		while (i < 4)
		{
			info->C[i - 1] = ft_atoi(split[i]);
			i++;
		}
	}
	ft_free(line);
	ft_freen(split, ft_strlen2(split));
}
