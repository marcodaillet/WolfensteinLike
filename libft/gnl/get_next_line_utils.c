/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:09:55 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/04 15:36:16 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	fill_buffer(int fd, char *buffer, int *n)
{
	*n = read(fd, buffer, BUFFER_SIZE);
	if (*n == -1)
		return (-1);
	buffer[*n] = 0;
	return (0);
}

int	ft_contains_gnl(const char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}
