/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:23:29 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/22 10:37:08 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkers(t_data *ret)
{
	if (dimensioncheck(ret->map, ret) == 1)
		return (freemap(ret->map, ret), freemap(ret->mapcheck, ret), 1);
	if (cfinder(ret->map, ret) == 1)
		return (freemap(ret->map, ret), freemap(ret->mapcheck, ret), 1);
	if (mapcheck(ret->map, ret) == 1)
		return (freemap(ret->map, ret), freemap(ret->mapcheck, ret), 1);
	p_value(ret->map, &ret->xpm.y, &ret->xpm.x, ret);
	floodfill(ret->mapcheck, ret->xpm.y, ret->xpm.x);
	if (floodfillcheck(ret->mapcheck, ret) == 1)
		return (freemap(ret->map, ret), freemap(ret->mapcheck, ret), 1);
	return (0);
}
int	dimensioncheck(char **mapa, t_data *program)
{
	int	y;
	int	i;
	size_t	lengthchecker;

	y = 0;
	i = 0;
	if (mapa[y] == NULL)
		return (ft_printf("ERROR:\nYour map is empty!\n"), 1);
	while (mapa[y] != NULL)
		y++;
	lengthchecker = ft_strlen(mapa[0]);
	while (mapa[i] != NULL)
	{
		if (lengthchecker != ft_strlen(mapa[i]))
		{
			program->xpm.height = y;
			ft_printf("ERROR:\nYour map is invalid,\
				please be sure that the map is even\n");
			return (1);
		}
		i++;
	}
	program->xpm.height = y;
	program->xpm.length = lengthchecker;
	return (0);
}
int	mapcheck(char **mapa, t_data *program)
{
	int	x;
	int	y;

	program->xpm.pck = 0;
	program->xpm.eck = 0;
	program->xpm.cck = 0;
	y = 0;
	while (y < program->xpm.height)
	{
		x = 0;
		while (x < program->xpm.length)
		{
			if (mapa[y][x] == 'P')
				program->xpm.pck++;
			if (mapa[y][x] == 'E')
				program->xpm.eck++;
			if (mapa[y][x] == 'C')
				program->xpm.cck++;
			x++;
		}
		y++;
	}
	if (program->xpm.pck != 1 || program->xpm.eck != 1 || program->xpm.cck != 1)
		return (ft_printf("ERROR:\nInvalid Map\nReason: special tiles\n"), 1);
	return (0);
}
int	floodfillcheck(char **mapa, t_data *program)
{
	int	y;
	int	x;

	y = 0;
	while (y < program->xpm.height)
	{
		x = 0;
		while (x < program->xpm.length)
		{
			if (mapa[y][x] == 'C' || mapa[y][x] == 'P' || mapa[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	colisioncheck(int x, int y, char key, t_data *program)
{
	if (program->xpm.cc == 0)
		program->map[2][1] = 'E';
	if (key == 'W' && program->map[y - 1][x] == '1')
		return (1);
	else if (key == 'S' && program->map[y + 1][x] == '1')
		return (1);
	else if (key == 'A' && program->map[y][x + 1] == '1')
		return (1);
	else if (key == 'D' && program->map[y][x - 1] == '1')
		return (1);
	// else if ((key == 'W' && program->map[y - 1][x] == 'E') && program->xpm.cc != 0)
	// 	return (1);
	// else if ((key == 'S' && program->map[y + 1][x] == 'E') && program->xpm.cc != 0)
	// 	return (1);
	// else if ((key == 'A' && program->map[y][x + 1] == 'E') && program->xpm.cc != 0)
	// 	return (1);
	// else if ((key == 'D' && program->map[y][x - 1] == 'E') && program->xpm.cc != 0)
		//return (1);
	exitconfirm(program->map, key, program->xpm.cc, program);
	return (0);
}