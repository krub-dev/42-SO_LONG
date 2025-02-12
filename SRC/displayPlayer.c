/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayPlayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:34:45 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:12 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mirrored_player(t_game *game)
{
	if (game->mirrored == false)
	{
		mlx_set_instance_depth(&game->player.sprites.img->instances[0], 5);
		mlx_set_instance_depth
			(&game->player.sprites.img_bonus->instances[0], -5);
	}
	else
	{
		mlx_set_instance_depth(&game->player.sprites.img->instances[0], -5);
		mlx_set_instance_depth
			(&game->player.sprites.img_bonus->instances[0], 5);
	}
}

void	sprites_player(t_game *game, float ratio)
{
	game->player.sprites.texture = mlx_load_png("./TEXTURES/marcus.png");
	game->player.sprites.texture_bonus = mlx_load_png
		("./TEXTURES/marcus_mirr.png");
	if (!game->player.sprites.texture || !game->player.sprites.texture_bonus)
		exit_error(game, NULL);
	game->player.sprites.img = mlx_texture_to_image
		(game->mlx, game->player.sprites.texture);
	game->player.sprites.img_bonus = mlx_texture_to_image
		(game->mlx, game->player.sprites.texture_bonus);
	if (!game->player.sprites.img || !game->player.sprites.img_bonus)
	{
		mlx_delete_texture(game->player.sprites.texture);
		mlx_delete_texture(game->player.sprites.texture_bonus);
		exit_error(game, NULL);
	}
	mlx_resize_image(game->player.sprites.img,
		1 * game->size, (1 * game->size) * ratio);
	mlx_resize_image(game->player.sprites.img_bonus,
		1 * game->size, (1 * game->size) * ratio);
}

void	set_player(t_game *game, int i, int j)
{
	if (mlx_image_to_window(game->mlx, game->player.sprites.img,
			j * (game->size) + (game->size / 10), (i - 0.6) * (game->size)) < 0)
		exit_error(game, NULL);
	mlx_set_instance_depth(&game->player.sprites.img->instances[0], 5);
	if (mlx_image_to_window(game->mlx, game->player.sprites.img_bonus,
			j * (game->size) + (game->size / 10),
			(i - 0.6) * (game->size)) < 0)
		exit_error(game, NULL);
	mlx_set_instance_depth(&game->player.sprites.img_bonus->instances[0], -5);
	game->player.sprites.x = j;
	game->player.sprites.y = i;
}

t_game	display_player(t_game game)
{
	int		i;
	int		j;
	float	ratio;

	ratio = 1.49;
	sprites_player(&game, ratio);
	i = 0;
	while (game.level.map[i])
	{
		j = 0;
		while (game.level.map[i][j] != '\0')
		{
			if (game.level.map[i][j] == 'P')
				set_player(&game, i, j);
			j++;
		}
		i++;
	}
	return (game);
}
