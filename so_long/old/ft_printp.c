/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:43:17 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/08 12:42:30 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_printp(void *p, int *counter)
{
	if (p == NULL)
		ft_putstr("(nil)", counter);
	else
	{
		ft_putstr("0x", counter);
		ft_printbase((unsigned long)p, "0123456789abcdef", 16, counter);
	}
}
