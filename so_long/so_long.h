/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:39:01 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/10 15:24:43 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

#define WIDTH 1500
#define HEIGHT 1500
#define SPRITE 64

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_img    
{
    void *img;
    int  bytes_per_pixel;
    int  line_len;
    int  endian;
}   t_img;

typedef struct s_xpm
{
    void *player;
    void *exit;
    void *floor;
    void *wall;
    void *collectable;
    int y;
    int x;
    int cc;
    int moves;
    int height;
    int length;
    int pcheck;
    int echeck;
    int ccheck;
}   t_xpm;

typedef struct s_data
{
    void *mlx;
    void *window;
    t_img img;
    t_xpm xpm;
    char    **map;
    char    **mapcheck;
    
} t_data;

void P_value(char **mapa, int *y, int *x, t_data *program);
int colisioncheck(char **mapa, int x, int y, char key, t_data *program);
int collectablecount(char **mapa, t_data *program);
void floodfill(char **mapa, int y, int x);
void freemap(char **map, t_data *program);
int floodfillcheck(char **mapa, t_data *program);
void keypy(int keyp, int y, int x, t_data *program);
void keypx(int keyp, int y, int x, t_data *program);
void exitconfirm(char **mapa, char key, int cc, t_data *program);
int ft_close(t_data *program);
int dimensioncheck(char **mapa, t_data *program);
# endif