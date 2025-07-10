/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:33:17 by dvidal            #+#    #+#             */
/*   Updated: 2025/05/05 11:42:23 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	h;

	i = 0;
	if ((little == NULL || big == NULL) && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		h = 0;
		while (little[h] != '\0' && big[i + h] == little[h] && i + h < len)
			h++;
		if (little[h] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
