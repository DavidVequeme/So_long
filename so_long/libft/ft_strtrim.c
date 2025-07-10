/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:16:46 by dvidal            #+#    #+#             */
/*   Updated: 2025/05/07 11:42:37 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	size_t	i;
	size_t	j;
	size_t	final_len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_set(s1[i], set) || is_set(s1[j], set))
	{
		if (is_set(s1[i], set))
			i++;
		if (is_set(s1[j], set))
			j--;
	}
	if (ft_strlen(s1) == i)
		return (ft_strdup(""));
	final_len = j - i + 2;
	final = (char *)malloc(final_len * sizeof(char));
	if (!final)
		return (NULL);
	ft_strlcpy(final, s1 + i, final_len);
	return (final);
}
