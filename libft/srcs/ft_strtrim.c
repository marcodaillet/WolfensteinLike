/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:02:15 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/04 17:38:58 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_contains(const char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;
	size_t	start;
	size_t	len;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (!str || !str_len)
		return (ft_strdup(""));
	i = 0;
	while (str[i] && ft_contains(set, str[i]))
		i++;
	start = i;
	i = str_len - 1;
	while (ft_contains(set, str[i]) && i >= 0)
		i--;
	len = (i - start) + 1;
	if (len > str_len)
		return (ft_strdup(""));
	return (ft_substr(str, start, len));
}
