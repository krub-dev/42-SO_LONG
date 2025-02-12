/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerController.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:36:30 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/05 01:22:48 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game, int mov, int key)
{
	ft_printf("\nUP\n");
	is_collider(game, key);
	if (game->collider == false)
	{
		game->player.sprites.img->instances[0].y -= mov;
		game->player.sprites.img_bonus->instances[0].y -= mov;
		game->player.sprites.y -= 1;
		check_move(game);
		ft_printf("Pos de PLAYER: [%d][%d]\n", game->player.sprites.x,
			game->player.sprites.y);
		ft_printf("Movimientos[%d]\n", game->moves++);
	}
}

static void	move_down(t_game *game, int mov, int key)
{
	ft_printf("\nDOWN\n");
	is_collider(game, key);
	if (game->collider == false)
	{
		game->player.sprites.img->instances[0].y += mov;
		game->player.sprites.img_bonus->instances[0].y += mov;
		game->player.sprites.y += 1;
		check_move(game);
		ft_printf("Pos de PLAYER: [%d][%d]\n", game->player.sprites.x,
			game->player.sprites.y);
		ft_printf("Movimientos[%d]\n", game->moves++);
	}
}

static void	move_left(t_game *game, int mov, int key)
{
	ft_printf("\nLEFT\n");
	is_collider(game, key);
	if (game->collider == false)
	{
		game->mirrored = true;
		mirrored_player(game);
		game->player.sprites.img->instances[0].x -= mov;
		game->player.sprites.img_bonus->instances[0].x -= mov;
		game->player.sprites.x -= 1;
		check_move(game);
		ft_printf("Pos de PLAYER: [%d][%d]\n", game->player.sprites.x,
			game->player.sprites.y);
		ft_printf("Movimientos[%d]\n", game->moves++);
	}
}

static void	move_right(t_game *game, int mov, int key)
{
	ft_printf("\nRIGHT\n");
	is_collider(game, key);
	if (game->collider == false)
	{
		game->mirrored = false;
		mirrored_player(game);
		game->player.sprites.img->instances[0].x += mov;
		game->player.sprites.img_bonus->instances[0].x += mov;
		game->player.sprites.x += 1;
		check_move(game);
		ft_printf("Pos de PLAYER: [%d][%d]\n", game->player.sprites.x,
			game->player.sprites.y);
		ft_printf("Movimientos[%d]\n", game->moves++);
	}
}

void	player_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->collider = false;
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_up(game, game->size, 1);
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_down(game, game->size, 2);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_left(game, game->size, 3);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right(game, game->size, 4);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_game(game, "ESC\nSalgo del juego.");
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		display_moves_colls(game);
		ft_printf("FPS: %d\n", (int)(round(1.0 / game->mlx->delta_time)));
		ft_printf("Coleccionables restantes: %d\n", game->n_coll);
	}
}
