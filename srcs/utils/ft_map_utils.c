/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:22:10 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/07 16:54:10 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_map(char *line)
{
	int	i;
	char	*s;

	s = ft_strtrim(line, " \t");
	i = 0;
	if (!line || ft_strlen(s) == 0)
	{
		ft_free(s);
		return (ERROR);
	}
	ft_free(s);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != ' ' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' )
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	ft_bun(void *s, size_t n)
{
	size_t			i;
	unsigned char	*suc;

	i = 0;
	suc = (unsigned char *)s;
	while (i < n)
	{
		suc[i] = 49;
		i++;
	}
	s = suc;
}
