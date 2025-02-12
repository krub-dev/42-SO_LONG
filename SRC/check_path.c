/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:54:28 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:19 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_path(t_game *game)
{
	char	**visited;
	int		i;
	int		result;

	visited = copy_level(game);
	i = 0;
	if (!visited)
		return (1);
	result = dfs(game, game->player.x, game->player.y, visited);
	while (i < game->level.rows)
		free(visited[i++]);
	free(visited);
	if ((game->collected == game->n_coll && game->hole == true) && result == 1)
		return (0);
	else
	{
		ft_printf("Error.\nNINGUNA RUTA VALIDA\n");
		return (1);
	}
}

char	**copy_level(t_game *game)
{
	char	**visited;
	int		i;

	visited = malloc(game->level.rows * sizeof(char *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < game->level.rows)
	{
		visited[i] = malloc(game->level.cols * sizeof(char));
		if (!visited[i])
		{
			while (i > 0)
			{
				i--;
				free(visited[i]);
			}
			free(visited);
			return (NULL);
		}
		ft_memset(visited[i], 0, game->level.cols);
		ft_strcpy(visited[i], game->level.map[i]);
		i++;
	}
	return (visited);
}

int	dfs(t_game *game, int x, int y, char **visited)
{
	if (x < 0 || x >= game->level.cols || y < 0 || y >= game->level.rows)
		return (0);
	if (visited[y][x] == 1 || game->level.map[y][x] == '1')
		return (0);
	if (game->level.map[y][x] == 'C')
		(game->collected)++;
	if (game->level.map[y][x] == 'E')
		game->hole = true;
	if (game->collected == game->n_coll && game->hole == true)
		return (1);
	visited[y][x] = 1;
	if (dfs(game, x + 1, y, visited) || dfs(game, x - 1, y, visited)
		|| dfs(game, x, y + 1, visited) || dfs(game, x, y - 1, visited))
		return (1);
	return (0);
}

int	check_level(t_game *game)
{
	if (!game->level.map)
		return (1);
	if (game->level.rows == game->level.cols)
	{
		ft_printf("MAPA NO ES RECTANGULO\n");
		return (1);
	}
	if (check_wall(game) != 0)
		return (1);
	if (check_player(game) != 0)
		return (1);
	if (check_exit(game) != 0)
		return (1);
	player_coll_pos(game);
	if (game->n_coll == 0)
		return (1);
	if (check_char_valid(game) != 0)
		return (1);
	if (is_valid_path(game) != 0)
		return (1);
	return (0);
}
