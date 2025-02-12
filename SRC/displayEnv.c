/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayEnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:34:18 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:14 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sprite_background(t_game *game, float ratio)
{
	game->level.s_bg.texture = mlx_load_png("./TEXTURES/tilebg_resize.png");
	if (!game->level.s_bg.texture)
		exit_error(game, NULL);
	game->level.s_bg.img = mlx_texture_to_image(game->mlx,
			game->level.s_bg.texture);
	if (!game->level.s_bg.img)
		exit_error(game, NULL);
	mlx_resize_image(game->level.s_bg.img,
		ratio * game->size, game->size);
}

t_game	display_background(t_game game)
{
	int	i;
	int	j;
	int	k;

	sprite_background(&game, 1.0);
	i = 0;
	k = 0;
	while (game.level.map[i])
	{
		j = 0;
		while (game.level.map[i][j] != '\0')
		{
			if ((mlx_image_to_window(game.mlx, game.level.s_bg.img,
						j * game.size, i * game.size)) < 0)
				exit_error(&game, NULL);
			mlx_set_instance_depth(&game.level.s_bg.img->instances[k++], -1);
			j++;
		}
		i++;
	}
	return (game);
}

static void	sprite_borders(t_game *game)
{
	game->level.s_borders.texture = mlx_load_png
		("./TEXTURES/tilemap2_resize.png");
	if (!game->level.s_borders.texture)
		exit_error(game, NULL);
	game->level.s_borders.img = mlx_texture_to_image(game->mlx,
			game->level.s_borders.texture);
	if (!game->level.s_borders.img)
		exit_error(game, NULL);
	mlx_resize_image(game->level.s_borders.img, game->size, game->size);
}

t_game	display_borders(t_game game)
{
	int	i;
	int	j;
	int	k;

	sprite_borders(&game);
	i = -1;
	k = 0;
	while (game.level.map[++i])
	{
		j = -1;
		while (game.level.map[i][++j] != '\0')
		{
			if (game.level.map[i][j] == '1')
			{
				if ((mlx_image_to_window(game.mlx, game.level.s_borders.img,
							j * game.size, i * game.size)) < 0)
					exit_error(&game, NULL);
				mlx_set_instance_depth
					(&game.level.s_borders.img->instances[k++], 1);
			}
		}
	}
	return (game);
}
