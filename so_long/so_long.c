/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:06:35 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/25 11:53:20 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalue(t_data *ret)
{
	int	x;
	int	y;

	x = SPRITE;
	y = SPRITE;
	ret->mlx = mlx_init();
	ft_init(ret);
	ret->window = mlx_new_window(ret->mlx, ret->xpm.length * SPRITE,
			ret->xpm.height * SPRITE, "So_Long");
	ret->xpm.issac.idle = mlx_xpm_file_to_image(ret->mlx, "issac_1_64.xpm", &x,
			&y);
	ret->xpm.wall = mlx_xpm_file_to_image(ret->mlx, "wall_64.xpm", &x, &y);
	ret->xpm.floor = mlx_xpm_file_to_image(ret->mlx, "floor_64.xpm", &x, &y);
	ret->xpm.exit = mlx_xpm_file_to_image(ret->mlx, "d_closed_64.xpm", &x, &y);
	ret->xpm.collectable = mlx_xpm_file_to_image(ret->mlx, "c_1.xpm", &x, &y);
	norminetteisabitch(ret);
}

void	norminetteisabitch(t_data *ret)
{
	if (ret->window == NULL)
		ft_close(ret);
	if (ret->xpm.issac.idle == NULL)
		ft_close(ret);
	if (ret->xpm.wall == NULL)
		ft_close(ret);
	if (ret->xpm.floor == NULL)
		ft_close(ret);
	if (ret->xpm.exit == NULL)
		ft_close(ret);
	if (ret->xpm.collectable == NULL)
		ft_close(ret);
}

int	initialize(char *line, t_data *ret)
{
	int	i;

	i = 0;
	ret->xpm.moves = 0;
	ret->xpm.height = 0;
	if (line == NULL)
		return (1);
	ret->last_tile = '0';
	ret->map = ft_split(line, '\n');
	ret->mapcheck = ft_split(line, '\n');
	if (checkers(ret) == 1)
		return (1);
	collectablecount(ret->map, ret);
	invalue(ret);
	return (0);
}

char	*helper(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	size_t	bytesread;
	char	buffer[BUFFER_SIZE + 1];

	fd = open(filename, O_RDONLY);
	bytesread = 1;
	if (fd < 0)
		return (write(2, "ERROR:\nPlease submit a map!\n", 29), NULL);
	line = ft_strdup("");
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread > 0)
		{
			buffer[bytesread] = '\0';
			temp = line;
			line = ft_strjoin(line, buffer);
			free(temp);
		}
		if (bytesread < 0)
			return (free(line), NULL);
	}
	return (line);
}

int	main(int ac, char **av)
{
	t_data	program;

	if (ac == 2)
	{
		if (ft_filenamechecker(av[1]) != 0)
			exit(0);
		program.xpm.line = helper(av[1]);
		if (initialize(program.xpm.line, &program) == 1)
		{
			free(program.xpm.line);
			exit(0);
		}
		mlx_loop_hook(program.mlx, render, &program);
		mlx_hook(program.window, KeyPress, KeyPressMask, keyp, &program);
		mlx_hook(program.window, DestroyNotify, NoEventMask, ft_close,
			&program);
		mlx_loop(program.mlx);
	}
	return (0);
}
