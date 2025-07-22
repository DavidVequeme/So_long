/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:41:36 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/22 14:43:44 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chosetile(t_data *program, int x, int y)
{
	if (program->map[y][x] == '1')
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.wall, x * SPRITE, y * SPRITE);
	else if (program->map[y][x] == 'E' && program->xpm.cc == 0)
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.exit, x * SPRITE, y * SPRITE);
	else if (program->map[y][x] == 'C')
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.collectable, x * SPRITE, y * SPRITE);
	else if (program->map[y][x] == 'P')
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.issac.idle, x * SPRITE, y * SPRITE);
	else
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.floor, x * SPRITE, y * SPRITE);
}

int	render(t_data *program)
{
	int	x;
	int	y;

	y = 0;
	while (y < program->xpm.height)
	{
		x = 0;
		while (x < program->xpm.length)
		{
			chosetile(program, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
