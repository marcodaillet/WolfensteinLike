/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:27:02 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/05 16:26:03 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_config_error(int id, int index)
{
	if (id == 0 && index == 0)
		return(ft_error2("North walls textures has not be defined"));
	else if (id == 1 && index == 0)
		return(ft_error2("South walls textures has not be defined"));
	else if (id == 2 && index == 0)
		return(ft_error2("West walls textures has not be defined"));
	else if (id == 3 && index == 0)
		return(ft_error2("East wall textures color has not be defined"));
	else if (id == 4 && index == 0)
		return(ft_error2("Ceiling color has not be defined"));
	else if (id == 5 && index == 0)
		return(ft_error2("Floor color has not be defined"));
	else if (id == 0 && index == 1)
		return(ft_error2("North walls textures defined multiple times"));
	else if (id == 1 && index == 1)
		return(ft_error2("South walls textures defined multiple times"));
	else if (id == 2 && index == 1)
		return(ft_error2("West walls textures defined multiple times"));
	else if (id == 3 && index == 1)
		return(ft_error2("East wall textures defined multiple times"));
	else if (id == 4 && index == 1)
		return(ft_error2("Ceiling color has been defined multiple times"));
	else
		return(ft_error2("Floor color has been defined multiple times"));
}

int	ft_check_ids(t_check *check, char *filename)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (check->params[i] != 1)
		{
			if (check->params[i] == 0)
				return (ft_config_error(i, 0));
			else
				return (ft_config_error(i, 1));
		}
		i++;
	}
	check->player = 0;
	return (ft_check_map(filename, check));
}

int	ft_check_param(char *s)
{
	char	*line;

	line = ft_strtrim(s, " \t");
	ft_free(s);
	if (!line)
		ft_error2("Malloc error");
	else if (ft_startw(line, "F") == SUCCESS || ft_startw(line, "C") == SUCCESS)
		return (ft_treat_fc(line));
	else if (ft_startw(line, "NO") == SUCCESS || ft_startw(line, "SO") == SUCCESS
		|| ft_startw(line, "WE") == SUCCESS || ft_startw(line, "EA") == SUCCESS)
		return (ft_treat_walls(line));
	ft_free(line);
	return (SUCCESS);
}

static void	ft_check_input(char *s, t_check *check)
{
	char *line;

	line = ft_strtrim(s, "\t ");
	if (!line)
		return ;
	if (ft_startw(line, "NO") == SUCCESS)
		check->params[0]++;
	else if (ft_startw(line, "SO") == SUCCESS)
		check->params[1]++;
	else if (ft_startw(line, "WE") == SUCCESS)
		check->params[2]++;
	else if (ft_startw(line, "EA") == SUCCESS)
		check->params[3]++;
	else if (ft_startw(line, "C") == SUCCESS)
		check->params[4]++;
	else if (ft_startw(line, "F") == SUCCESS)
		check->params[5]++;
	ft_free(line);
}

int	ft_check_file(char *filename, t_check *check)
{
	int		fd;
	char	*line;
	
	if (ft_endw(filename, ".cub") == ERROR)
		return(ft_error2("The map file must be at .cub format."));
	ft_memset(check->params, 0, sizeof(int) * 6);
	fd = open(filename, O_RDONLY);
	line = NULL;
	if (fd < 0)
		return(ft_error2("Cub3d met a problem while opening the file"));
	while (get_next_line(fd, &line) > 0)
	{
		ft_check_input(line, check);
		if (ft_check_param(line) == ERROR)
		{
			close(fd);
			get_next_line(fd, &line);
			return (ERROR);
		}
	}
	ft_free(line);
	close(fd);
	return (ft_check_ids(check, filename));
}
