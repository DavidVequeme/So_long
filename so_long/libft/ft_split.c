/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:00:24 by dvidal            #+#    #+#             */
/*   Updated: 2025/05/01 14:51:40 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char c, char *s)
{
	size_t	wc;
	size_t	i;
	int		state;

	wc = 0;
	i = 0;
	while (s[i])
	{
		state = 1;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			if (state)
			{
				state = 0;
				wc++;
			}
			i++;
		}
	}
	return (wc);
}

static char	**iffree(char **av, size_t index)
{
	while (index-- > 0)
		free(av[index]);
	free(av);
	return (NULL);
}

static char	**arrct(char const *s, char c, char **final, size_t wc)
{
	size_t	leng;
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (wc > 0)
	{
		leng = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			leng++;
			i++;
		}
		final[index] = malloc(leng + 1);
		if (!final[index])
			return (iffree(final, index));
		ft_strlcpy(final[index], &s[i - leng], leng + 1);
		index++;
		wc--;
	}
	return (final);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	size_t	wc;

	if (s == NULL)
		return (NULL);
	wc = ft_count_words(c, (char *)s);
	final = malloc(sizeof (char *) * (wc + 1));
	if (!final)
		return (NULL);
	final[wc] = NULL;
	final = arrct(s, c, final, wc);
	return (final);
}
