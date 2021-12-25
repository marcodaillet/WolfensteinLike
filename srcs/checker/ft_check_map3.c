/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:36:12 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/07 13:34:03 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_wrong_char2(char *s)
{
	int	i;
	char	*line;

	line = ft_strtrim(s, "\t ");
	i = 0;
	if (!line)
		return (ft_error2("Malloc error."));
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
		{
			ft_free(line);
			return (ft_error2("Wrong char in the map definition"));
		}
		i++;
	}
	ft_free(line);
	return (SUCCESS);
}
