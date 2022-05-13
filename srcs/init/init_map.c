/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:27 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 15:48:03 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_struct_walls(t_walls *walls)
{
	walls->check_no = false;
	walls->path_no = NULL;
	walls->check_so = false;
	walls->path_so = NULL;
	walls->check_we = false;
	walls->path_we = NULL;
	walls->check_ea = false;
	walls->path_ea = NULL;
}

void	init_struct_floor(t_floor *floor)
{
	floor->check_floor = false;
	floor->path_floor = NULL;
	floor->check_celling = false;
	floor->path_celling = NULL;
}

void	init_struct_map(t_map *map)
{
	map->map = NULL;
	map->lines_map = 0;
	map->max_len_map = 0;
	init_struct_walls(map->walls);
	init_struct_floor(map->floor);
}