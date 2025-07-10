/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:08:59 by dvidal            #+#    #+#             */
/*   Updated: 2025/05/07 11:27:39 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	leng(int n)
{
	int	length;

	length = 0;
	if (n < 0)
		length++;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*c;
	long	n2;
	int		length;

	n2 = n;
	if (n2 == 0)
		return (ft_strdup("0"));
	length = leng(n2);
	c = malloc(length + 1);
	if (!c)
		return (NULL);
	if (n2 < 0)
	{
		n2 = -n2;
		c[0] = '-';
	}
	c[length] = '\0';
	while (n2 != 0)
	{
		c[--length] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	return (c);
}
