/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_fc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:50:43 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/12 17:13:42 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static int	ft_check_values(char **splitted)
{
	int i1;
	int i2;
	int i3;

	i1 = ft_atoi(splitted[1]);
	i2 = ft_atoi(splitted[2]);
	i3 = ft_atoi(splitted[3]);
	if ((i1 >= 0 && i1 <= 255) && (i2 >= 0 && i2 <= 255)
		&& (i3 >= 0 && i3 <= 255))
		return (SUCCESS);
	return (ERROR);
}

int	ft_treat_fc(char *line)
{
	char	**splitted;
	int		len;

	splitted = ft_split(line, ", \t");
	len = ft_strlen2(splitted);
	if (!splitted)
	{
		free(line);
		return (ft_error2("Malloc error."));
	}
	if (len != 4 || ft_check_values(splitted) == ERROR)
	{
		ft_freen(splitted, len);
		return (ft_error2("Wrong color definition."));
	}
	ft_freen(splitted, len);
	free(line);
	return (SUCCESS);
}
