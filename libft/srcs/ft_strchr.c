/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:46:31 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/01 09:58:28 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return (0);
	while (*s != c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_strchr1(const char *s, char c)
{
	while (*s != c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}
