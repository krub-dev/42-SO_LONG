/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:46:39 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/05 01:13:41 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../LIBFT/libft.h"
# include "../LIBFT/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "./so_long_structs.h"

# define WIDTH 3840
# define HEIGHT 2160

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <string.h>

// Colors
# define RESET		"\x1b[0m"
# define RED		"\x1b[0;31m"
# define BRED		"\x1b[1;31m"
# define GREEN		"\x1b[0;32m"
# define BGREEN		"\x1b[1;32m"
# define PURPLE		"\x1b[0;35m"
# define BPURPLE	"\x1b[1;35m"
# define BLUE		"\x1b[0;34m"
# define BBLUE		"\x1b[1;34m"
# define CYAN		"\x1b[0;36m"
# define BCYAN		"\x1b[1;36m"
# define WHITE		"\x1b[0;97m"
# define BWHITE		"\x1b[1;97m"
# define YELLOW		"\x1b[0;33m"
# define BYELLOW	"\x1b[1;33m"

// SO_LONG

// Level (create)
t_static	ft_columns_count(char *s, t_static level);
t_static	ft_level_count(int fd, t_static level);
void		ft_conv_level(t_game *game, int fd);

// Level 
// First parse
int			check_char_valid(t_game *game);
int			check_wall(t_game *game);
int			check_player(t_game *game);
int			check_exit(t_game *game);
// Second parse
int			check_level(t_game *game);
void		player_coll_pos(t_game *game);
int			is_valid_path(t_game *game);
char		**copy_level(t_game *game);
int			dfs(t_game *game, int x, int y, char **visited);
int			is_valid_move(t_game *game, int x, int y, char **visited);

// Display ENV
t_game		display_background(t_game game);
t_game		display_borders(t_game game);

// Display Collectibles / EXIT
void		display_collectibles(t_game *game);
t_game		display_hole(t_game game);
void		display_exit(t_game *game);

// Display Player
t_game		display_player(t_game game);
void		set_player(t_game *game, int i, int j);
void		mirrored_player(t_game *game);
void		sprites_player(t_game *game, float ratio);

// GAME
t_game		game_init(t_game game);

// Game Utils
void		tile_size(t_game *game);
void		scale_monitor(t_game *game);
void		init_s(t_game *game);
size_t		ft_strcpy(char *dst, char *src);
t_game		win_borders(t_game game);

// Interface
void		display_moves_colls(t_game *game);

// Controllers
void		player_input(mlx_key_data_t keydata, void *param);

// Interact
int			check_move(t_game *game);
void		is_collider(t_game *game, int key);
int			is_wall(t_game *game);
int			is_coll(t_game *game);
int			is_exit(t_game *game);

// Errors / Exit / Free
void		close_callback(void *param);
void		exit_error(t_game *game, char *error);
void		exit_game(t_game *game, char *msg);

#endif
