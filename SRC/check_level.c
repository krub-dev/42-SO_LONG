/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:48:48 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:26 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (game->level.map[i] != NULL)
	{
		j = 0;
		while (game->level.map[i][j] != '\0')
		{
			if (game->level.map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	ft_printf("[E]XIT: %d\n", count);
	if (count != 1)
		return (1);
	return (0);
}

int	check_player(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (game->level.map[i] != NULL)
	{
		j = 0;
		while (game->level.map[i][j] != '\0')
		{
			if (game->level.map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	ft_printf("[P]LAYER: %d\n", count);
	if (count != 1)
		return (1);
	return (0);
}

int	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->level.cols)
	{
		if (game->level.map[0][i] != '1')
			return (1);
		if (game->level.map[game->level.rows - 1][i] != '1')
			return (1);
		else
			i++;
	}
	i = 0;
	while (i < game->level.rows)
	{
		if (game->level.map[i][0] != '1')
			return (1);
		if (game->level.map[i][game->level.cols - 1] != '1')
			return (1);
		else
			i++;
	}
	ft_printf("[1]BORDES OK\n");
	return (0);
}

int	check_char_valid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->level.map[i] != NULL)
	{
		j = 0;
		while (game->level.map[i][j] != '\0')
		{
			if (game->level.map[i][j] == '0'
					|| game->level.map[i][j] == '1'
					|| game->level.map[i][j] == 'P'
					|| game->level.map[i][j] == 'E'
					|| game->level.map[i][j] == 'C')
				j++;
			else if (game->level.map[i][j] == '\n')
				j++;
			else
				return (1);
		}
		i++;
	}
	ft_printf("TODO ES [0][1][P][E][C]\n");
	return (0);
}
