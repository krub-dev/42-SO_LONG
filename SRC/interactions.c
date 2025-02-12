/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:37:06 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:06 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_collider(t_game *game, int key)
{
	if (key == 1 && game->level.map[game->player.sprites.y - 1]
		[game->player.sprites.x] == '1')
		game->collider = true;
	else if (key == 2 && game->level.map[game->player.sprites.y + 1]
		[game->player.sprites.x] == '1')
		game->collider = true;
	else if (key == 3 && game->level.map[game->player.sprites.y]
		[game->player.sprites.x - 1] == '1')
		game->collider = true;
	else if (key == 4 && game->level.map[game->player.sprites.y]
		[game->player.sprites.x + 1] == '1')
		game->collider = true;
	if (game->collider == true)
		ft_printf("NO PUEDES HACER ESE MOVIMIENTO.\n");
}

int	check_move(t_game *game)
{
	if (is_coll(game) == 1)
	{
		game->n_coll--;
		ft_printf("Detecto COLLECCIONABLE. Restantes: %d\n", game->n_coll);
		game->level.map[game->player.sprites.y][game->player.sprites.x] = 'X';
	}
	is_wall(game);
	is_exit(game);
	ft_printf("Aqui hay [%c]\n",
		game->level.map[game->player.sprites.y][game->player.sprites.x]);
	return (0);
}

int	is_wall(t_game *game)
{
	if (game->level.map[game->player.sprites.y][game->player.sprites.x] == '1')
	{
		ft_printf("Detecto PARED\n");
		return (1);
	}
	ft_printf("NO Detecto PARED\n");
	return (0);
}

int	is_coll(t_game *game)
{
	int	size;

	size = game->size;
	if (game->level.map[game->player.sprites.y][game->player.sprites.x] == 'C')
	{
		game->coll.posc = 0;
		while (game->coll.posc < game->coll.n_temp)
		{
			if ((game->player.sprites.y == (game->coll.sprites.img
						->instances[game->coll.posc].y / size))
				&& (game->player.sprites.x == (game->coll.sprites.img
						->instances[game->coll.posc].x / size)))
			{
				mlx_set_instance_depth
					(&game->coll.sprites.img->instances[game->coll.posc], -20);
			}
			ft_printf("POSC: %d\n", game->coll.posc);
			game->coll.posc++;
		}
		return (1);
	}
	ft_printf("NO Detecto COLLECCIONABLE\n");
	return (0);
}

int	is_exit(t_game *game)
{
	if (game->exit == false && game->n_coll == 0)
	{
		game->exit = true;
		display_exit(game);
	}
	if (game->exit == false && (game->player.sprites.x == game->level.s_hole.x)
		&& (game->player.sprites.y == game->level.s_hole.y))
	{
		ft_printf("Detecto HOLE\n");
		return (1);
	}
	if (game->exit == true && ((game->player.sprites.x == game->level.s_exit.y)
			&& (game->player.sprites.y == game->level.s_exit.x)))
		exit_game(game, "Detecto EXIT\n\n[VICTORIA]");
	ft_printf("NO Detecto EXIT\n");
	return (0);
}
