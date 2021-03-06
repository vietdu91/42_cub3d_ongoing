/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:08:18 by emtran            #+#    #+#             */
/*   Updated: 2022/07/12 20:04:33 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	define_texy(t_sprites *sprites, int y)
{
	int	i;
	int	tex_y;

	i = (y) * 256 - WINDOW_GAME * 128 + sprites->sprite_height * 128;
	tex_y = ((i * SPRITE_H) / sprites->sprite_height) / 256;
	return (tex_y);
}

int	define_texx(t_sprites *sprites)
{
	int	tex_x;

	tex_x = (int)((256 * (sprites->stripe - (-sprites->sprite_width \
	/ 2 + sprites->spritescreenx)) * SPRITE_W / sprites->sprite_width) / 256);
	return (tex_x);
}

int	get_text_rgb_sprites(char *addr, t_data *data, int add, int y)
{
	int	rgb;

	rgb = addr[(int)(data->sprites->stripe * SPRITE_W) \
		* (data->game->dylan_the_butcher->bpp >> 3) \
		+ add + (int)((y - data->sprites->draw_start_x * 1.0) \
		/ (int)(WINDOW_HEIGHT / data->game->p1->perp_wall_dist) * SPRITE_H) \
		*data->game->dylan_the_butcher->line_len];
	return (rgb);
}

int	store_color_in_buffer(t_data *data, t_sprites *sprites)
{
	u_int32_t	color;
	int			y;

	color = 0;
	sprites->stripe = sprites->draw_start_x;
	while (sprites->stripe < sprites->draw_end_x)
	{
		if (sprites->transformy > 0 && sprites->stripe > 0 && \
		sprites->stripe < WINDOW_WIDTH && sprites->transformy < \
		sprites->z_buffer[data->sprites->stripe])
		{
			sprites->tex_x = define_texx(sprites);
			y = sprites->draw_start_y;
			while (y < sprites->draw_end_y)
			{
				sprites->tex_y = define_texy(sprites, y);
				if ((color & 0x00FFFFFF) != 0)
					img_pix_put(data->game->screen, sprites->stripe, y, WHITE);
				y++;
			}
		}
		sprites->stripe++;
	}
	return (0);
}
