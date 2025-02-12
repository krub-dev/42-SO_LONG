/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:48:02 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/05 01:21:58 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves_colls(t_game *game)
{
	char		*mov;
	char		*coll;
	mlx_image_t	*text;
	mlx_image_t	*text2;

	mov = ft_itoa(game->moves);
	coll = ft_itoa(game->n_coll);
	if (game->text_moves && game->text_colls)
	{
		mlx_delete_image(game->mlx, game->text_moves);
		mlx_delete_image(game->mlx, game->text_colls);
		game->text_moves = NULL;
		game->text_colls = NULL;
	}
	game->text_moves = mlx_put_string(game->mlx, mov, 150, 40);
	game->text_colls = mlx_put_string(game->mlx, coll, 280, 60);
	if (!game->text_moves || !game->text_colls)
		exit_error(game, NULL);
	text = mlx_put_string(game->mlx, "MOVIMIENTOS: ", 25, 40);
	text2 = mlx_put_string(game->mlx, "COLLECIONABLES RESTANTES: ", 25, 60);
	if (!text || !text2)
		exit_error(game, NULL);
	free(mov);
	free(coll);
}

static char	**maps_init(char **maps)
{
	maps[0] = "MAPS/map.ber";
	maps[1] = "MAPS/map2.ber";
	maps[2] = "MAPS/map_42.ber";
	maps[3] = "MAPS/map_42_small.ber";
	maps[4] = "MAPS/map_small.ber";
	maps[5] = "MAPS/map_big.ber";
	maps[6] = "MAPS/map3_bonus.ber";
	maps[7] = "MAPS/map_e_borders.ber";
	maps[8] = "MAPS/map_e_path_small.ber";
	maps[9] = "MAPS/map_e_no_player.ber";
	maps[10] = "MAPS/map_e_no_rectangle.ber";
	maps[11] = "MAPS/map_e_exit_no_access.ber";
	maps[12] = "MAPS/map_e_collectible_no_access.ber";
	return (maps);
}

static int	open_fd(int argc, char **argv, bool print)
{
	int		i;
	int		fd;
	char	*maps[13];

	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (print && (ft_strncmp("MAPS/map", argv[1], 8) == 0)
			&& ft_strnstr(argv[1], ".ber", sizeof(argv[1])))
			ft_printf("MAPA: %s\n", argv[1]);
		else
			ft_printf("Error.\nNo valido [./so_long MAPS/map*.ber]\n");
	}
	else
	{
		*maps = *maps_init(maps);
		fd = open(maps[i], O_RDONLY);
		if (print)
			ft_printf("MAPA: %s\n", maps[i]);
	}
	if (fd == -1)
		exit(EXIT_FAILURE);
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	init_s(&game);
	fd = open_fd(argc, argv, true);
	game.level = ft_level_count(fd, game.level);
	if (game.level.rows == 0)
		return (EXIT_FAILURE);
	fd = open_fd(argc, argv, false);
	ft_conv_level(&game, fd);
	ft_printf("Filas: [%d] | Columnas: [%d] | ",
		game.level.rows, game.level.cols);
	ft_printf("Longitud: [%d]\n", game.level.rows * game.level.cols);
	if (check_level(&game) != 0)
		exit_error(&game, "MAPA NO VALIDO");
	else
		ft_printf("MAPA VALIDO\n");
	scale_monitor(&game);
	game = game_init(game);
	return (EXIT_SUCCESS);
}
