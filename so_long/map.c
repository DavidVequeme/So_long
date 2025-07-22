/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:26:36 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/22 10:38:18 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(char **mapa, int y, int x)
{
	if (mapa[y][x] == '1' || mapa[y][x] == 'F')
		return ;
	mapa[y][x] = 'F';
	floodfill(mapa, y + 1, x);
	floodfill(mapa, y - 1, x);
	floodfill(mapa, y, x + 1);
	floodfill(mapa, y, x - 1);
}

void	p_value(char **mapa, int *y, int *x, t_data *program)
{
	*y = 0;
	while (*y < program->xpm.height)
	{
		*x = 0;
		while (*x < program->xpm.length)
		{
			if (mapa[*y][*x] == 'P')
				return ;
			*x += 1;
		}
		*y += 1;
	}
}

void	freemap(char **mapa, t_data *program)
{
	int	y;

	y = 0;
	if (mapa == NULL)
		return ;
	while (y < program->xpm.height)
	{
		free(mapa[y]);
		y++;
	}
	free(mapa);
}

int	cfinder(char **mapa, t_data *program)
{
	int	x;
	int	y;

	y = 0;
	while (y < program->xpm.height)
	{
		x = 0;
		while (x < program->xpm.length)
		{
			if (mapa[y][x] != 'C' && mapa[y][x] != 'P' && mapa[y][x] != '1'
				&& mapa[y][x] != '0' && mapa[y][x] != 'E')
				return (ft_printf("ERROR:\nUnknown character,\
						check your map!!"), 1);
			x++;
		}
		y++;
	}
	return (0);
}

void	collectablecount(char **mapa, t_data *program)
{
	int	cc;
	int	x;
	int	y;

	x = 0;
	cc = 0;
	y = 0;
	while (y < program->xpm.height)
	{
		x = 0;
		while (x < program->xpm.length)
		{
			if (mapa[y][x] == 'C')
				cc++;
			x += 1;
		}
		y += 1;
	}
	program->xpm.cc = cc;
}
