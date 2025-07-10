/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:51:12 by dvidal            #+#    #+#             */
/*   Updated: 2025/05/09 14:19:46 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void helper(char *s, int *counter)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], counter),
		i++;
	}
}

void ft_putstr(char *s, int *counter)
{
	if (!s)
		helper("(null)", counter);
	else
		helper(s, counter);
}