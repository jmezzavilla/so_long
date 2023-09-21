/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:54:38 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/19 19:02:29 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_pixel(t_buffer *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int get_pixel_color(t_buffer* sprite, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= sprite->width || y >= sprite->height)
		return (0);

	dst = sprite->addr + (y * sprite->line_length + x * (sprite->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw(int x, int y, t_buffer* sprite, t_game *game)
{
	int ix = 0;
	int iy = 0;
	int color;

	while (iy < sprite->height) {
		ix = 0;
		while (ix < sprite->width) {
			color = get_pixel_color(sprite, ix, iy);
			put_pixel(&game->image_buffer, (x * BLOCK_PIXEL) + ix, (y * BLOCK_PIXEL) + iy, color);
			ix++;
		}
		iy++;
	}
}

void	draw_map_game_over(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			game->map->matrix[y][x] = 'B';
			x++;
		}
		y++;
	}
}
