/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:54:45 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/08 12:42:50 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printbase(unsigned long n, char *base, int basesize, int *counter)
{
	if (n / basesize > 0)
		ft_printbase(n / basesize, base, basesize, counter);
	ft_putchar(base[n % basesize], counter);
}
