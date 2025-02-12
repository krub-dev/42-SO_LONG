/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:48:26 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:23 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_static	ft_columns_count(char *s, t_static level)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (level);
	while (s[i] != '\n')
		i++;
	level.cols = i;
	return (level);
}

t_static	ft_level_count(int fd, t_static level)
{
	char	*level_read;
	int		count;

	count = 0;
	level_read = get_next_line(fd);
	level = ft_columns_count(level_read, level);
	while (level_read)
	{
		free(level_read);
		level_read = NULL;
		level_read = get_next_line(fd);
		count++;
	}
	close(fd);
	if (count == 0)
		ft_printf("Mapa vacio. INVALIDO\n");
	level.rows = count;
	return (level);
}

void	ft_conv_level(t_game *game, int fd)
{
	int	i;

	i = 0;
	if (game->level.rows != 0)
	{
		game->level.map = malloc((game->level.rows + 1) * sizeof(char *));
		if (!game->level.map)
			exit_error(game, NULL);
		game->level.map[game->level.rows] = NULL;
		while (i < game->level.rows || game->level.map[i] != NULL)
			game->level.map[i++] = get_next_line(fd);
	}
	i = 0;
	while (game->level.map[i] != NULL)
		ft_printf("%s", game->level.map[i++]);
	close(fd);
}

void	player_coll_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->level.map[i])
	{
		j = 0;
		while (game->level.map[i][j] != '\0')
		{
			if (game->level.map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			else if (game->level.map[i][j] == 'C')
				game->n_coll++;
			j++;
		}
		i++;
	}
	game->coll.n_temp = game->n_coll;
	ft_printf("[C]OLLECTIBLES: %d\n", game->n_coll);
	ft_printf("POS INICIAL PLAYER [%d][%d]\n", game->player.x, game->player.y);
}
