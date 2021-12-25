/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:46:17 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/04 16:59:29 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_count_words(char const *s, char *sep)
{
	int	i;
	int	is_word;
	int	nb_words;

	i = 0;
	is_word = 0;
	nb_words = 0;
	while (s[i])
	{
		if (!ft_sep(sep, s[i]))
			is_word = 1;
		else if (ft_sep(sep, s[i]) && is_word)
		{
			is_word = 0;
			nb_words++;
		}
		i++;
	}
	if (is_word)
		nb_words++;
	return (nb_words);
}

int		ft_word_len(const char *s, char *sep)
{
	int	i;

	i = 0;
	while (!ft_sep(sep, s[i]) && s[i])
		i++;
	return (i);
}

static int ft_check(char **tmp, int i)
{
	if (!tmp[i])
	{
		ft_free_s(tmp);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char *sep)
{
	char		**tmp;
	int			i;
	int			j;
	int			word_len;
	int			nb_words;

	nb_words = ft_count_words(s, sep);
	tmp = malloc(sizeof(char *) * (nb_words + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (j < nb_words && s[i])
	{
		word_len = ft_word_len(s + i, sep);
		if (word_len)
		{
			tmp[j++] = ft_substr(s, i, word_len);
			if (!ft_check(tmp, j - 1))
				return (NULL);
		}
		i += word_len + 1;
	}
	tmp[nb_words] = 0;
	return (tmp);
}
