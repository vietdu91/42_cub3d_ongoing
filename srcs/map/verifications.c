/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:34:35 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/14 21:20:22 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	wall_touched(t_data *data, int size_x, int size_y, int dir)
{
	int	x;
	int	y;

	x = data->game->p1->posX;
	y = data->game->p1->posY;
	if ((x) % size_x == 0 && dir == KEY_A)
		return (is_a_space_or_is_wall \
		(data->map->map[y / size_y][(x - 1) / size_x]));
	else if ((x) % size_x  == 0 && dir == KEY_D)
		return (is_a_space_or_is_wall(data->map->map[y / size_y]\
		[(x + 1) / size_x]));
	else if ((y) % size_y == 0 && dir == KEY_S )
		return (is_a_space_or_is_wall \
		(data->map->map[(y + 2) / size_y][x / size_x]));
	else if ((y) % size_y == 0 && dir == KEY_W)
		return (is_a_space_or_is_wall\
		(data->map->map[(y - 1) / size_y][x / size_x]));
	return (-1);
}