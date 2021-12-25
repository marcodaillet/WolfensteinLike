/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:36:50 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/08 13:47:00 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_player(char *line)
{
	int player;
	int	i;

	player = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			player++;
		i++;
	}
	return (player);
}

int	ft_check_player(t_check *check)
{
	if (!check->player)
		return (ft_error2("The map doesn't have any player"));
	else if (check->player >= 2)
		return (ft_error2("The map has too many players"));
	return (SUCCESS);
}
	
int	ft_not_empty(char *s)
{
	char	*line;

	line = ft_strtrim(s, " \t");
	if (!line)
		return (ft_error2("Malloc error"));
	if (ft_strlen(line) == 0)
	{
		ft_free(line);
		return (ft_error2("There is an empty line in the map"));
	}
	ft_free(line);
	return (SUCCESS);
}

int	ft_check_exter(char	*s)
{
	char	*line;
	int		i;

	line = ft_strtrim(s, " \t");
	ft_free(s);
	if (!line)
		return (ft_error2("Malloc error."));
	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			ft_free(line);
			return (ft_error2("Player cannot be on the border of the map."));
		}
		if (line[i] != '1' && line[i] != ' ')
		{
			ft_free(line);
			return (ft_error2("The map isn't closed."));
		}
		i++;
	}
	ft_free(line);
	return (SUCCESS);
}

int ft_check_content(char *line, char *last, t_check *check)
{
	if (ft_wrong_char2(line) == ERROR
		|| ft_check_walls(line) == ERROR
		|| ft_not_empty(line) == ERROR)
	{
		ft_free(last);
		return (ERROR);
	}
	check->player += ft_player(line);
	return (SUCCESS);
}
