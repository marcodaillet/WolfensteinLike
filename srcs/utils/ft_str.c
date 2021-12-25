/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:43:50 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/03 15:56:00 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strlen2(char **av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	ft_startw(const char *str, const char *pattern)
{
	int ret;
	ret = ft_strncmp(str, pattern, ft_strlen(pattern));
	if (!ret)
		return (SUCCESS);
	return (ERROR);
}

int	ft_endw(const char *str, const char *pattern)
{
	int diff;
	int ret;
	diff = ft_strlen(str) - ft_strlen(pattern);
	ret = ft_strncmp(str + diff, pattern, ft_strlen(pattern));
	if (!ret)
		return (SUCCESS);
	return (ERROR);
}
