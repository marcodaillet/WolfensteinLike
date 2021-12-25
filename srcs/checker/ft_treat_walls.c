/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:03:22 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/05 16:37:31 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_file_error(char **splitted)
{
	if (ft_startw(splitted[0], "NO") == SUCCESS)
	{
		ft_freen(splitted, ft_strlen2(splitted));
		return(ft_error2("North walls : invalid texture file."));
	}
	else if (ft_startw(splitted[0], "SO") == SUCCESS)
	{
		ft_freen(splitted, ft_strlen2(splitted));
		return(ft_error2("South walls : invalid texture file."));
	}
	else if (ft_startw(splitted[0], "WE") == SUCCESS)
	{
		ft_freen(splitted, ft_strlen2(splitted));
		return(ft_error2("West walls : invalid texture file."));
	}
	else
	{
		ft_freen(splitted, ft_strlen2(splitted));
		return(ft_error2("East walls : invalid texture file."));
	}
}

static int ft_check_filename(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	close(fd);
	return (SUCCESS);
}

int	ft_treat_walls(char *line)
{
	char	**splitted;

	splitted = ft_split(line, " \t");
	if (!splitted)
	{
		ft_free(line);
		return (ft_error2("Malloc error."));
	}
	if (ft_strlen2(splitted) != 2 || ft_check_filename(splitted[1]) == ERROR)
	{
		ft_free(line);
		return (ft_file_error(splitted));
	}
	ft_freen(splitted, ft_strlen2(splitted));
	ft_free(line);
	return (SUCCESS);
}
