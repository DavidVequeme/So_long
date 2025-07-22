/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:29:49 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/21 10:22:47 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_filenamechecker(char *filename)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while(filename[i])
		i++;
	if (ft_strncmp(&filename[i - 4], ".ber", 5) == 0)
		return(0);
	return(1);
}
