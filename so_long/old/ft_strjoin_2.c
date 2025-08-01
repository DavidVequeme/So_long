/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:55:53 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/08 15:12:24 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_final;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_final = (char *)malloc(size);
	if (!str_final)
		return (NULL);
	ft_strlcpy(str_final, s1, size);
	ft_strlcat(str_final, s2, size);
	return (str_final);
}
