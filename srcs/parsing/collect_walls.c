/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:23:42 by emtran            #+#    #+#             */
/*   Updated: 2022/07/01 11:45:36 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	collect_walls(t_data *data, char **file)
{
	int		i;

	i = 0;
	while (i < data->lines_file)
	{
		if (!is_it_an_id_in_file(data, file, "NO", i))
			check_good_path_wall(data, data->map->walls, file[i], "NO");
		else if (!is_it_an_id_in_file(data, file, "SO", i))
			check_good_path_wall(data, data->map->walls, file[i], "SO");
		else if (!is_it_an_id_in_file(data, file, "WE", i))
			check_good_path_wall(data, data->map->walls, file[i], "WE");
		else if (!is_it_an_id_in_file(data, file, "EA", i))
			check_good_path_wall(data, data->map->walls, file[i], "EA");
		i++;
	}
	return (0);
}

int	put_wall_in_structure(t_walls *walls, char **split, char *type)
{
	if (!ft_strcmp("NO", type))
		walls->path_no = ft_strdup(split[1]);
	else if (!ft_strcmp("SO", type))
		walls->path_so = ft_strdup(split[1]);
	else if (!ft_strcmp("WE", type))
		walls->path_we = ft_strdup(split[1]);
	else if (!ft_strcmp("EA", type))
		walls->path_ea = ft_strdup(split[1]);
	return (0);
}

int	put_img_wall_to_mlx(t_data *data, char *path, t_img *img)
{
	img->mlx_img = mlx_xpm_file_to_image(data->game->mlx_ptr, path, \
	&img->width, &img->height);
	if (!img->mlx_img)
		print_error_and_exit(ERR_MLC_IMG, data);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	if (img->mlx_img == NULL || img->addr == NULL)
		print_error_and_exit(ERR_MLC_IMG, data);
	return (0);
}

int	walls_butcher(t_data *data, t_walls *walls, t_texture *img)
{
	destroy_walls(data, img);
	if (walls->path_no)
		put_img_wall_to_mlx(data, BUTCHER_NO, img->wall_no);
	if (walls->path_so)
		put_img_wall_to_mlx(data, BUTCHER_SO, img->wall_so);
	if (walls->path_we)
		put_img_wall_to_mlx(data, BUTCHER_WE, img->wall_we);
	if (walls->path_ea)
		put_img_wall_to_mlx(data, BUTCHER_EA, img->wall_ea);
	data->game->texture->floor->hexa = 0x800000;
	data->game->texture->celling->hexa = 0x000000;
	return (0);
}

int	create_img_of_walls(t_data *data, t_walls *walls, t_texture *img)
{
	if (data->game->good_or_bad == true)
	{
		if (data->game->step_of_game == 4)
		{
			destroy_walls(data, img);
			data->game->texture->floor->hexa = ft_rgb_to_hex(data, img->floor->r, img->floor->g, img->floor->b);
			data->game->texture->celling->hexa = ft_rgb_to_hex(data, img->celling->r, img->celling->g, img->celling->b);
		}
		if (walls->path_no)
			put_img_wall_to_mlx(data, walls->path_no, img->wall_no);
		if (walls->path_so)
			put_img_wall_to_mlx(data, walls->path_so, img->wall_so);
		if (walls->path_we)
			put_img_wall_to_mlx(data, walls->path_we, img->wall_we);
		if (walls->path_ea)
			put_img_wall_to_mlx(data, walls->path_ea, img->wall_ea);
	}
	else
		walls_butcher(data, walls, img);
	return (0);
}
