/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:49:50 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/25 11:16:19 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *program)
{
	program->xpm.wall = NULL;
	program->xpm.floor = NULL;
	program->xpm.exit = NULL;
	program->xpm.collectable = NULL;
}

void	clearimg(t_data *program, void *img)
{
	if (img != NULL)
		mlx_destroy_image(program->mlx, img);
}

int	ft_close(t_data *program)
{
	clearimg(program, program->xpm.issac.idle);
	clearimg(program, program->xpm.wall);
	clearimg(program, program->xpm.floor);
	clearimg(program, program->xpm.exit);
	clearimg(program, program->xpm.collectable);
	if (program->window != NULL)
		mlx_destroy_window(program->mlx, program->window);
	if (program->mlx != NULL)
		mlx_destroy_display(program->mlx);
	free(program->mlx);
	freemap(program->map, program);
	freemap(program->mapcheck, program);
	free(program->xpm.line);
	exit(0);
	return (0);
}
