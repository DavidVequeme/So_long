/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:49:50 by dvidal            #+#    #+#             */
/*   Updated: 2025/07/18 16:52:35 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init(t_data *program)
{
    program->xpm.wall = NULL;
	program->xpm.floor = NULL;
	program->xpm.exit = NULL;
	program->xpm.collectable = NULL;
}