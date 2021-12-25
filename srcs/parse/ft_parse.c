/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:06:16 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/24 10:50:27 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_parse_config(char *s, t_info *info)
{
	char	*line;

	line = ft_strtrim(s, " \t");
	if (ft_startw(line, "NO") == SUCCESS)
		ft_parse_NO(line, info);
	else if (ft_startw(line, "SO") == SUCCESS)
		ft_parse_SO(line, info);
	else if (ft_startw(line, "WE") == SUCCESS)
		ft_parse_WE(line, info);
	else if (ft_startw(line, "EA") == SUCCESS)
		ft_parse_EA(line, info);
	else if (ft_startw(line, "C") == SUCCESS
		|| ft_startw(line, "F") == SUCCESS)
		ft_parse_FC(line, info);
	else
		ft_free(line);
}

void	ft_max_len(char	*line, t_info *info)
{
	if (ft_strlen(line) > (size_t)info->max_length)
		info->max_length = (int)ft_strlen(line);
	info->nb_lines++;
}

void	ft_parse_map(t_info *info, char *filename, int ret)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && ft_is_map(line) == ERROR)
		ft_free(line);
	info->map = (char **)malloc(sizeof(char *) * (info->nb_lines + 1));
	while (ret > 0)
	{
		j = 0;
		info->map[i] =(char *)malloc(sizeof(char) * (info->max_length + 2));
		ft_bun(info->map[i], (size_t)info->max_length);
		while (line[j++])
			info->map[i][j] = line[j];
		i++;
		ft_free(line);
		ret = get_next_line(fd, &line);
	}
	ft_free(line);
	info->map[i] = 0;
}

void	ft_replace_space(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->nb_lines)
	{
		j = 0;
		while (j < info->max_length)
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'W' || info->map[i][j] == 'E')
			{
				info->direction = info->map[i][j];
				info->dx = i;
				info->dy = j;
				info->map[i][j] = '0';
			}
			else if (info->map[i][j] == ' ' || info->map[i][j] == '\0')
				info->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	ft_parse(t_info *info, char *filename)
{
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	fd = open(filename, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_start(line) == ERROR)
			ft_parse_config(line, info);
		else if (ft_is_map(line) == SUCCESS)
			ft_max_len(line, info);
		ft_free(line);
	}
	ret = 1;
	ft_parse_map(info, filename, ret);
	ft_replace_space(info);
}
