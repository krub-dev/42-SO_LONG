/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayExit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 02:42:50 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:09 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sprite_hole(t_game *game, float ratio)
{
	game->level.s_hole.texture = mlx_load_png("./TEXTURES/hole_base_nobg.png");
	if (!game->level.s_hole.texture)
		exit_error(game, NULL);
	game->level.s_hole.img = mlx_texture_to_image(game->mlx,
			game->level.s_hole.texture);
	if (!game->level.s_hole.img)
		exit_error(game, NULL);
	mlx_resize_image(game->level.s_hole.img, ratio * game->size,
		1 * game->size);
}

t_game	display_hole(t_game game)
{
	int	i;
	int	j;

	sprite_hole(&game, 1.0);
	i = 0;
	while (game.level.map[i])
	{
		j = 0;
		while (game.level.map[i][j] != '\0')
		{
			if (game.level.map[i][j] == 'E')
			{
				if (mlx_image_to_window(game.mlx, game.level.s_hole.img,
						j * game.size, i * game.size) < 0)
					exit_error(&game, NULL);
				game.level.s_hole.x = j;
				game.level.s_hole.y = i;
			}
			j++;
		}
		i++;
	}
	mlx_set_instance_depth(&game.level.s_hole.img->instances[0], 1);
	return (game);
}

static void	sprite_exit(t_game *game, float ratio)
{
	game->level.s_exit.texture = mlx_load_png("./TEXTURES/hole_exit_nobg.png");
	if (!game->level.s_exit.texture)
		exit_error(game, NULL);
	game->level.s_exit.img = mlx_texture_to_image(game->mlx,
			game->level.s_exit.texture);
	if (!game->level.s_exit.img)
		exit_error(game, NULL);
	mlx_resize_image(game->level.s_exit.img, 1 * game->size,
		1 * (game->size * ratio));
}

void	display_exit(t_game *game)
{
	int	i;
	int	j;

	sprite_exit(game, 1.0);
	i = 0;
	while (game->level.map[i])
	{
		j = 0;
		while (game->level.map[i][j] != '\0')
		{
			if (game->level.map[i][j] == 'E')
			{
				if (mlx_image_to_window(game->mlx, game->level.s_exit.img,
						j * game->size, i * game->size) < 0)
					exit_error(game, NULL);
				game->level.s_exit.x = i;
				game->level.s_exit.y = j;
			}
			j++;
		}
		i++;
	}
	mlx_set_instance_depth(&game->level.s_exit.img->instances[0], 2);
}
