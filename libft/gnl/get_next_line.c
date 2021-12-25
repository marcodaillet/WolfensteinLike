/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:00:35 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/04 17:26:02 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_clean(char *buffer, char **line)
{
	free(buffer);
	*line = NULL;
	return (-1);
}

static char	*ft_strmerge_gnl(char *tmp, const char *buffer)
{
	char	*join;
	size_t	tmp_len;
	int		i;

	if (tmp)
		tmp_len = ft_strlen(tmp);
	else
		tmp_len = 0;
	join = malloc(sizeof(char) * (tmp_len + ft_strlen(buffer) + 1));
	if (!join)
		return (NULL);
	if (tmp)
	{
		i = -1;
		while (tmp[++i])
			join[i] = tmp[i];
	}
	i = -1;
	while (buffer[++i])
		join[tmp_len + i] = buffer[i];
	join[tmp_len + i] = 0;
	free(tmp);
	return (join);
}

static char *get_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (ft_strdup2(s, i));
		i++;
	}
	return (ft_strdup(s));
}

static int	update_tmp(char *tmp)
{
	int	i;
	char	*sub;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			sub = ft_strdup(tmp + i + 1);
			if (!sub)
				return (-1);
			ft_strcpy(tmp, sub);
			free(sub);
			return (1);
		}
		i++;
	}
	free(tmp);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *tmp[256];
	char		buffer[BUFFER_SIZE + 1];
	int			n;
	int			ret;

	if (fd == -1 || fd > 255 || BUFFER_SIZE < 1 || !line)
		return (ft_clean(tmp[fd], line));
	n = 1;
	buffer[0] = 0;
	while (n && !ft_contains_gnl(buffer, '\n'))
	{
		if (fill_buffer(fd, buffer, &n) == -1)
			return (ft_clean(tmp[fd], line));
		tmp[fd] = ft_strmerge_gnl(tmp[fd], buffer);
		if (!tmp[fd])
			return (ft_clean(tmp[fd], line));
	}
	*line = get_newline(tmp[fd]);
	ret = update_tmp(tmp[fd]);
	if (!*line || ret == -1)
		return (ft_clean(tmp[fd], line));
	if (ret)
		return (1);
	tmp[fd] = NULL;
	return (0);
}
