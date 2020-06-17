/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:20:00 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/18 22:55:08 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	wordcnt(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char		*word(char const *s, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	if (!(word = (char*)malloc((len * sizeof(char) + 1))))
		return (NULL);
	word[len] = '\0';
	while (len)
	{
		word[len - 1] = s[len - 1];
		len--;
	}
	return (word);
}

static void		ft_free(char ***split, size_t i)
{
	while (i)
	{
		free((*split)[i - 1]);
		(*split)[i - 1] = NULL;
		i--;
	}
	free(*split);
	*split = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	char		**st;

	i = 0;
	if (!s)
		return (NULL);
	if (!(st = (char**)malloc((wordcnt(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (*s)
		if (*s != c)
		{
			if (!word(s, c))
			{
				ft_free(&st, i);
				return (NULL);
			}
			st[i++] = word(s, c);
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	st[i] = 0;
	return (st);
}
