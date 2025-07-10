/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:43:17 by dvidal            #+#    #+#             */
/*   Updated: 2025/05/09 14:19:57 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
