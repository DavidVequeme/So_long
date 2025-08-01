/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:32:36 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/09 13:07:21 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t ft_strlen(char *s)
{
	size_t i;
	
	if (!s)
		return (0);
	i = 0;
	while(s[i])
		i++;
	return(i);
}