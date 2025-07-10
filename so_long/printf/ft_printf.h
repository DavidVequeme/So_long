/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:08:38 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/08 16:09:29 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void ft_putchar(int c, int *counter);
void ft_putstr(char *str, int *counter);
void ft_printbase(unsigned long n, char *base, int basesize, int *counter);
void ft_putnbr(long n, int *counter);
void ft_printp(void *p, int *counter);
int	ft_printf(const char *s, ...);

#endif