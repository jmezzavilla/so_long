/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:54:38 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 23:08:07 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_pixel(t_buffer *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_pixel_color(t_buffer *sprite, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= sprite->width || y >= sprite->height)
		return (0);
	dst = sprite->addr + (y * sprite->line_length + x * (sprite->bits_per_pixel
				/ 8));
	return (*(unsigned int *)dst);
}

void	draw(int x, int y, t_buffer *sprite, t_game *game)
{
	int	sprite_x;
	int	sprite_y;
	int	color;

	sprite_x = 0;
	sprite_y = 0;
	while (sprite_y < sprite->height)
	{
		sprite_x = 0;
		while (sprite_x < sprite->width)
		{
			color = get_pixel_color(sprite, sprite_x, sprite_y);
			put_pixel(&game->image_buffer, (x * BLOCK_PIXEL) + sprite_x, (y
					* BLOCK_PIXEL) + sprite_y, color);
			sprite_x++;
		}
		sprite_y++;
	}
}
