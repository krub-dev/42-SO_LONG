/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayCollectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 02:42:35 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:15 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sprite_collectibles(t_game *game, float ratio)
{
	game->coll.sprites.texture = mlx_load_png("./TEXTURES/diamond_nobg.png");
	if (!game->coll.sprites.texture)
		exit_error(game, NULL);
	game->coll.sprites.img = mlx_texture_to_image(game->mlx,
			game->coll.sprites.texture);
	if (!game->coll.sprites.img)
		exit_error(game, NULL);
	mlx_resize_image(game->coll.sprites.img, ratio * game->size,
		ratio * game->size);
}

void	display_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	k;

	sprite_collectibles(game, 0.75);
	i = -1;
	k = 0;
	while (game->level.map[++i])
	{
		j = -1;
		while (game->level.map[i][++j] != '\0')
		{
			if (game->level.map[i][j] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->coll.sprites.img,
						j * game->size + (game->size / 5),
						i * game->size + (game->size / 6)) < 0)
					exit_error(game, NULL);
				game->coll.sprites.x = j;
				game->coll.sprites.y = i;
				mlx_set_instance_depth
					(&game->coll.sprites.img->instances[k++], 1);
			}
		}
	}
}
