/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:04:02 by dvidal            #+#    #+#             */
/*   Updated: 2025/05/07 11:32:14 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c_dest;
	size_t	c_src;
	size_t	i;

	c_src = ft_strlen((char *)src);
	c_dest = 0;
	i = 0;
	while (c_dest < size && dst[c_dest] != '\0')
		c_dest++;
	if (c_dest == size)
		return (size + c_src);
	while ((c_dest + i + 1) < size && src[i] != '\0')
	{
		dst[c_dest + i] = src[i];
		i++;
	}
	dst[c_dest + i] = '\0';
	return (c_dest + c_src);
}
