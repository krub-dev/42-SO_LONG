/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:36:31 by frubio-i          #+#    #+#             */
/*   Updated: 2025/02/05 01:19:29 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "./so_long.h"

// SO_LONG

// Structs sprites
typedef struct s_sprites
{
	mlx_texture_t	*texture;
	mlx_texture_t	*texture_bonus;
	mlx_image_t		*img;
	mlx_image_t		*img_bonus;
	int				x;
	int				y;
}	t_sprites;

// Structure interactive elements
// Player / Enemies / Collectibles
typedef struct s_inter
{
	t_sprites	sprites;
	int			x;
	int			y;
	int			posc;
	int			n_temp;
	float		speed;
	bool		flag;
	bool		jumped;
	int			health;
	int			damage;
}	t_inter;

// Structure non interactive elements
// Level
typedef struct s_static
{
	t_sprites	s_bg;
	t_sprites	s_borders;	
	t_sprites	s_hole;
	t_sprites	s_exit;
	char		**map;
	int			rows;
	int			cols;
	int			x;
	int			y;
}	t_static;

// Struct general game state
typedef struct s_game
{
	t_inter		player;
	t_inter		coll;
	t_inter		enem;
	t_static	level;
	t_sprites	icon;
	mlx_t		*mlx;
	int			w_monitor;
	int			h_monitor;
	int			size;
	int			lives;
	int			inter;
	int			n_coll;
	int			collected;
	int			moves;
	mlx_image_t	*text_moves;
	mlx_image_t	*text_colls;
	bool		exit;
	bool		hole;
	bool		collider;
	bool		mirrored;
}	t_game;

#endif
