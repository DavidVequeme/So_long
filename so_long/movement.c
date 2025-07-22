/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:44:37 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/22 11:06:29 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyp(int keyp, t_data *program)
{
	int	x;
	int	y;

	x = program->xpm.x;
	y = program->xpm.y;
	if (keyp == XK_Escape)
		ft_close(program);
	program->last_tile = '0';
	keypy(keyp, program->xpm.y, program->xpm.x, program);
	keypx(keyp, y, x, program);
	if (keyp == XK_Right)
	{
		mlx_destroy_image(program->mlx, program->xpm.player);
		program->xpm.player = mlx_xpm_file_to_image(program->mlx,
			 "issac_3_64.xpm", &x, &y);
	}
	if (keyp == XK_Left)
	{
		mlx_destroy_image(program->mlx, program->xpm.player);
		program->xpm.player = mlx_xpm_file_to_image(program->mlx, 
			"issac_2_64.xpm", &x, &y);
	}
	render(program);
	return (0);
}
void	keypy(int keyp, int y, int x, t_data *program)
{
	if (keyp == XK_Up)
	{
		if (colisioncheck(x, y, 'W', program) == 0)
		{
			program->map[y][x] = program->last_tile;
			ft_tilekeeper(y - 1, x, program);
			program->xpm.y--;
		}
	}
	if (keyp == XK_Down)
	{
		if (colisioncheck(x, y, 'S', program) == 0)
		{
			program->map[y][x] = program->last_tile;
			ft_tilekeeper(y + 1, x, program);
			program->xpm.y++;
		}
	}
}

void ft_tilekeeper(int y, int x, t_data *program)
{
	program->last_tile = program->map[y][x];
	program->map[y][x] = 'P';
	program->xpm.moves++;
	ft_printf("moves:%i\n", program->xpm.moves);
}

void	keypx(int keyp, int y, int x, t_data *program)
{
	if (keyp == XK_Right)
	{
		if (colisioncheck(x, y, 'A', program) == 0)
		{
			program->map[y][x] = program->last_tile;
			ft_tilekeeper(y, x + 1, program);
			mlx_destroy_image(program->mlx, program->xpm.player);
			program->xpm.player = mlx_xpm_file_to_image(program->mlx, "issac_3_64.xpm", &x, &y);
			program->xpm.x++;
		}
	}
	if (keyp == XK_Left)
	{
		if (colisioncheck(x, y, 'D', program) == 0)
		{
			program->map[y][x] = program->last_tile;
			ft_tilekeeper(y, x - 1, program);
			program->xpm.x--;
		}
	}
}

void	exitconfirm(char **mapa, char key, int cc, t_data *program)
{
	if (key == 'S' && mapa[program->xpm.y + 1][program->xpm.x] == 'E'
		&& cc == 0)
		ft_close(program);
	if (key == 'W' && mapa[program->xpm.y - 1][program->xpm.x] == 'E'
		&& cc == 0)
		ft_close(program);
	if (key == 'A' && mapa[program->xpm.y][program->xpm.x + 1] == 'E'
		&& cc == 0)
		ft_close(program);
	if (key == 'D' && mapa[program->xpm.y][program->xpm.x - 1] == 'E'
		&& cc == 0)
		ft_close(program);
}