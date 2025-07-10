/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:51:12 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/08 12:42:43 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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