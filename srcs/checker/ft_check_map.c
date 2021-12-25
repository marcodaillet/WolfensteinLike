/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:15:43 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/07 13:39:46 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_wrong_char(char *s)
{
	int	i;
	char	*line;

	line = ft_strtrim(s, "\t ");
	i = 0;
	if (!line)
		return (ERROR);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != ' ' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' )
		{
			ft_free(line);
			return (SUCCESS);
		}
		i++;
	}
	ft_free(line);
	return (ERROR);
}

int	ft_start(char *s)
{
	char	*line;

	if (!s || !ft_strlen(s))
		return (ERROR);
	line = ft_strtrim(s, " \t");
	if (!line)
		return (ERROR);
	if (ft_wrong_char(line) == SUCCESS)
	{
		ft_free(line);
		return (ERROR);
	}
	ft_free(line);
	return (SUCCESS);
}

int	ft_check_walls(char *s)
{
	char *line;

	if (ft_strlen(s) == 0)
		return (SUCCESS);
	line = ft_strtrim(s, " \t");
	if (!line)
		return (ft_error2("Malloc error"));
	if (ft_startw(line, "1") == ERROR || ft_endw(line, "1") == ERROR)
	{
		ft_free(line);
		return (ft_error2("The map is not closed"));
	}
	ft_free(line);
	return (SUCCESS);
}

void	ft_last(char **last, char *s)
{
	char	*line;

	ft_free(*last);
	line = ft_strtrim(s, " \t");
	if (!line)
		return ;
	if (ft_strlen(line))
		*last = ft_strdup(line);
	ft_free(line);
	ft_free(s);
}

int	ft_check_map(const char *filename, t_check *check)
{
	int		fd;
	char	*line;
	char	*last;
	
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && ft_start(line) == ERROR)
		free(line);
	last = ft_strdup(line);
	if (ft_check_exter(line) == ERROR)
		return (ERROR);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_content(line, last, check) == ERROR)
		{
			close(fd);
			free(line);
			return (ERROR);
		}
		ft_last(&last, line);
	}
	close(fd);
	ft_free(line);
	if (ft_check_exter(last) == SUCCESS && ft_check_player(check) == SUCCESS)
		return (SUCCESS);
	return (ERROR);
}
