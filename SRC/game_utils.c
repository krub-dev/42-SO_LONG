/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:37:36 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:17 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tile_size(t_game *game)
{
	float	h_size;
	float	w_size;

	h_size = (float)game->h_monitor / HEIGHT;
	w_size = (float)game->w_monitor / WIDTH;
	game->size = (int)(96 * fminf(w_size, h_size));
	game->size = fmax(game->size, 32);
	game->size = fmin(game->size, 96);
}

void	scale_monitor(t_game *game)
{
	mlx_t	*tmp_mlx;

	tmp_mlx = mlx_init(1, 1, "temp", false);
	if (!tmp_mlx)
	{
		game->w_monitor = 3840;
		game->h_monitor = 2160;
		return ;
	}
	mlx_get_monitor_size(0, &game->w_monitor, &game->h_monitor);
	mlx_terminate(tmp_mlx);
}

void	init_s(t_game *game)
{
	game->level.cols = 0;
	game->level.rows = 0;
	scale_monitor(game);
	game->n_coll = 0;
	game->coll.posc = 0;
	game->collected = 0;
	game->moves = 1;
	game->text_moves = NULL;
	game->level.map = NULL;
	game->hole = false;
	game->exit = false;
	game->coll.flag = true;
	game->mirrored = false;
	game->collider = false;
	game->inter = 1;
}

size_t	ft_strcpy(char *dst, char *src)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (i < len)
	{
		while (src[i] != '\0' && i < len - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (len);
}

t_game	win_borders(t_game game)
{
	int			w_window;
	int			h_window;
	float		scale;

	tile_size(&game);
	w_window = game.size * game.level.cols;
	h_window = game.size * game.level.rows;
	if (w_window > game.w_monitor || h_window > game.h_monitor)
	{
		scale = fminf((float)game.w_monitor / w_window,
				(float)game.h_monitor / h_window);
		game.size = (int)(game.size * scale);
		w_window = game.size * game.level.cols;
		h_window = game.size * game.level.rows;
	}
	game.mlx = mlx_init(w_window, h_window, "WANNABE", false);
	if (!game.mlx)
		exit_error(&game, NULL);
	game.icon.texture = mlx_load_png("./TEXTURES/icon.png");
	if (!game.icon.texture)
		exit_error(&game, NULL);
	mlx_set_icon(game.mlx, game.icon.texture);
	return (game);
}
