/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:47:34 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/08 12:42:40 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void ft_putnbr(long n, int *counter)
{
	if (n < 0)
	{
		ft_putchar('-', counter);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, counter);
	ft_putchar(n % 10 + '0', counter);
}
