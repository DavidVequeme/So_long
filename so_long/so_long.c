/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:06:35 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/10 16:42:13 by dvidal           ###   ########.fr       */
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
	keypy(keyp, y, x, program);
	keypx(keyp, y, x, program);
	return (0);
}

void	keypy(int keyp, int y, int x, t_data *program)
{
	if (keyp == XK_Up)
	{
		if (colisioncheck(program->map, x, y, 'W', program) == 0)
		{
			program->map[y][x] = '0';
			program->map[y - 1][x] = 'P';
			program->xpm.y--;
			program->xpm.moves++;
			ft_printf("moves:%i\n", program->xpm.moves);
		}
	}
	if (keyp == XK_Down)
	{
		if (colisioncheck(program->map, x, y, 'S', program) == 0)
		{
			program->map[y][x] = '0';
			program->map[y + 1][x] = 'P';
			program->xpm.y++;
			program->xpm.moves++;
			ft_printf("moves:%i\n", program->xpm.moves);
		}
	}
}

void	keypx(int keyp, int y, int x, t_data *program)
{
	if (keyp == XK_Right)
	{
		if (colisioncheck(program->map, x, y, 'A', program) == 0)
		{
			program->map[y][x] = '0';
			program->map[y][x + 1] = 'P';
			program->xpm.x++;
			program->xpm.moves++;
			ft_printf("moves:%i\n", program->xpm.moves);
		}
	}
	if (keyp == XK_Left)
	{
		if (colisioncheck(program->map, x, y, 'D', program) == 0)
		{
			program->map[y][x] = '0';
			program->map[y][x - 1] = 'P';
			program->xpm.x--;
			program->xpm.moves++;
			ft_printf("moves:%i\n", program->xpm.moves);
		}
	}
}

int	collectablecount(char **mapa, t_data *program)
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
	return (cc);
}

int	colisioncheck(char **mapa, int x, int y, char key, t_data *program)
{
	program->xpm.cc = collectablecount(mapa, program);
	if (key == 'W' && mapa[y - 1][x] == '1')
		return (1);
	else if (key == 'S' && mapa[y + 1][x] == '1')
		return (1);
	else if (key == 'A' && mapa[y][x + 1] == '1')
		return (1);
	else if (key == 'D' && mapa[y][x - 1] == '1')
		return (1);
	else if ((key == 'W' && mapa[y - 1][x] == 'E') && program->xpm.cc != 0)
		return (1);
	else if ((key == 'S' && mapa[y + 1][x] == 'E') && program->xpm.cc != 0)
		return (1);
	else if ((key == 'A' && mapa[y][x + 1] == 'E') && program->xpm.cc != 0)
		return (1);
	else if ((key == 'D' && mapa[y][x - 1] == 'E') && program->xpm.cc != 0)
		return (1);
	exitconfirm(mapa, key, program->xpm.cc, program);
	return (0);
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

int	ft_close(t_data *program)
{
	mlx_destroy_image(program->mlx, program->xpm.player);
	mlx_destroy_image(program->mlx, program->xpm.wall);
	mlx_destroy_image(program->mlx, program->xpm.floor);
	mlx_destroy_image(program->mlx, program->xpm.exit);
	mlx_destroy_image(program->mlx, program->xpm.collectable);
	mlx_destroy_window(program->mlx, program->window);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	freemap(program->map, program);
	freemap(program->mapcheck, program);
	exit(0);
	return (0);
}

void	chosetile(t_data *program, int x, int y)
{
	if (program->map[y][x] == '1')
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.wall, x * SPRITE, y * SPRITE);
	if (program->map[y][x] == '0')
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.floor, x * SPRITE, y * SPRITE);
	if (program->map[y][x] == 'E')
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.exit, x * SPRITE, y * SPRITE);
	if (program->map[y][x] == 'C')
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.collectable, x * SPRITE, y * SPRITE);
	if (program->map[y][x] == 'P')
		mlx_put_image_to_window(program->mlx, program->window,
			program->xpm.player, x * SPRITE, y * SPRITE);
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

int	mapcheck(char **mapa, t_data *program)
{
	int	x;
	int	y;

	program->xpm.pcheck = 0;
	program->xpm.echeck = 0;
	program->xpm.ccheck = 0;
	y = 0;
	while (y < program->xpm.height)
	{
		x = 0;
		while (x < program->xpm.length)
		{
			if (mapa[y][x] == 'P')
				program->xpm.pcheck++;
			if (mapa[y][x] == 'E')
				program->xpm.echeck++;
			if (mapa[y][x] == 'C')
				program->xpm.ccheck++;
			x++;
		}
		y++;
	}
	if (program->xpm.pcheck != 1 || program->xpm.echeck != 1
		|| program->xpm.ccheck != 1)
		return (ft_printf("ERROR:\nInvalid Map \nReason: dosen't have enough special tiles\n"),\
			1);
	return (0);
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

int	checkers(char *line, t_data *ret)
{
	if (dimensioncheck(ret->map, ret) == 1)
		return (freemap(ret->map, ret), freemap(ret->mapcheck, ret), 1);
	if (cfinder(ret->map, ret) == 1)
		return (freemap(ret->map, ret), freemap(ret->mapcheck, ret), 1);
	if (mapcheck(ret->map, ret) == 1)
		return (freemap(ret->map, ret), freemap(ret->mapcheck, ret), 1);
	P_value(ret->map, &ret->xpm.y, &ret->xpm.x, ret);
	floodfill(ret->mapcheck, ret->xpm.y, ret->xpm.x);
	if (floodfillcheck(ret->mapcheck, ret) == 1)
		return (freemap(ret->map, ret), freemap(ret->mapcheck, ret), 1);
	return (0);
}

int	initialize(char *line, t_data *ret)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	x = SPRITE;
	y = SPRITE;
	ret->xpm.moves = 0;
	ret->xpm.height = 0;
	if (line == NULL)
		return (1);
	ret->map = ft_split(line, '\n');
	ret->mapcheck = ft_split(line, '\n');
	if (checkers(line, ret) == 1)
		return (1);
	ret->mlx = mlx_init();
	ret->window = mlx_new_window(ret->mlx, WIDTH, HEIGHT, "So_Long");
	ret->xpm.player = mlx_xpm_file_to_image(ret->mlx, "wizard_64.xpm", &x, &y);
	ret->xpm.wall = mlx_xpm_file_to_image(ret->mlx, "wall_64.xpm", &x, &y);
	ret->xpm.floor = mlx_xpm_file_to_image(ret->mlx, "floor_64.xpm", &x, &y);
	ret->xpm.exit = mlx_xpm_file_to_image(ret->mlx, "door_closed_64.xpm", &x,
			&y);
	ret->xpm.collectable = mlx_xpm_file_to_image(ret->mlx, "key_64.xpm", &x,
			&y);
	return (0);
}

void	P_value(char **mapa, int *y, int *x, t_data *program)
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

int	dimensioncheck(char **mapa, t_data *program)
{
	int	y;
	int	i;
	int	lenghchecker;

	y = 0;
	i = 0;
	if (mapa[y] == NULL)
		return (ft_printf("ERROR:\nYour map is empty!\n"), 1);
	while (mapa[y] != NULL)
		y++;
	lenghchecker = ft_strlen(mapa[0]);
	while (mapa[i] != NULL)
	{
		if (lenghchecker != ft_strlen(mapa[i]))
		{
			program->xpm.height = y;
			ft_printf("ERROR:\nYour map is invalid,\
				please be sure that the map is even\n");
			return (1);
		}
		i++;
	}
	program->xpm.height = y;
	program->xpm.length = lenghchecker;
	return (0);
}
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

void	freemap(char **map, t_data *program)
{
	int	y;

	y = 0;
	if (map == NULL)
		return ;
	while (y < program->xpm.height)
	{
		free(map[y]);
		y++;
	}
	free(map);
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
		return (ft_printf("ERROR:\nPlease submit a map\n"), NULL);
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
	char	*line;

	if (ac == 2)
	{
		line = helper(av[1]);
		if (initialize(line, &program) == 1)
		{
			free(line);
			exit(0);
		}
		free(line);
		mlx_loop_hook(program.mlx, render, &program);
		mlx_hook(program.window, KeyPress, KeyPressMask, keyp, &program);
		mlx_hook(program.window, DestroyNotify, NoEventMask, ft_close,
			&program);
		mlx_loop(program.mlx);
	}
	return (0);
}
