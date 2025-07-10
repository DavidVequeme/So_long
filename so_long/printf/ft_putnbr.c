/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:47:34 by dvidal            #+#    #+#             */
/*   Updated: 2025/05/09 14:19:49 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
