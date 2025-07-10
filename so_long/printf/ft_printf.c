/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:18:32 by dvidal            #+#    #+#             */
/*   Updated: 2025/05/12 12:08:49 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(int c, va_list argc, int *counter)
{
	if (c == '%')
		ft_putchar(c, counter);
	if (c == 'c')
		ft_putchar(va_arg(argc, int), counter);
	if (c == 's')
		ft_putstr(va_arg(argc, char*), counter);
	if (c == 'p')
		ft_printp(va_arg(argc, void*), counter);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(argc, int), counter);
	if (c == 'u')
		ft_printbase(va_arg(argc, unsigned int),"0123456789", 10, counter);
	if (c == 'x')
		ft_printbase(va_arg(argc, unsigned int),"0123456789abcdef", 16, counter);
	if (c == 'X')
		ft_printbase(va_arg(argc, unsigned int), "0123456789ABCDEF", 16, counter);
	else
		*counter = -1;	
}


int	ft_printf(const char *s, ...)
{
	va_list argc;
	size_t i;
	int counter;
	
	i = 0;
	counter = 0;
	va_start(argc, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i], &counter);
		else
		{
			ft_format(s[i+1], argc, &counter);
			i++;
		}
		i++;
	}
	va_end(argc);
	return (counter);
}