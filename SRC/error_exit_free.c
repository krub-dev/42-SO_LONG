/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:11:43 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:04 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_callback(void *param)
{
	t_game	*game;

	if (param == NULL)
		return ;
	game = (t_game *)param;
	exit_game(game, "[X] Cierra ventana.");
}

void	exit_error(t_game *game, char *error)
{
	int	i;

	i = 0;
	if (error)
		ft_printf("Error\n%s\n", error);
	if (game->level.map != NULL)
	{
		while (game->level.map[i])
			free(game->level.map[i++]);
		free(game->level.map);
	}
	exit(EXIT_FAILURE);
}

void	exit_game(t_game *game, char *msg)
{
	if (msg)
		ft_printf("\n%s\n", msg);
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
