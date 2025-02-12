/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 06:14:40 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/05 00:53:56 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_info(t_game game)
{
	ft_printf("RESOLUCION MONITOR [%dx%d]\n", game.w_monitor, game.h_monitor);
	ft_printf("RESOLUCION VENTANA [%dx%d]\n", game.mlx->width,
		game.mlx->height);
	ft_printf("SIZE TILE DINAMICA [%d]\n", game.size);
	ft_printf("Pos de HOLE es [%d][%d]\n", game.level.s_hole.x,
		game.level.s_hole.y);
	ft_printf("Pos de PLAYER: [%d][%d]\n", game.player.sprites.x,
		game.player.sprites.y);
}

t_game	game_init(t_game game)
{
	game = win_borders(game);
	game = display_background(game);
	game = display_borders(game);
	display_collectibles(&game);
	game = display_hole(game);
	game = display_player(game);
	display_info(game);
	mlx_close_hook(game.mlx, close_callback, &game);
	mlx_key_hook(game.mlx, player_input, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (game);
}
