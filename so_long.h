/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:54:04 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/28 21:55:45 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//libft library
# include "srcs/libft/includes/libft.h"
//mlx library
# include "srcs/mlx/mlx.h"
//open()
# include <fcntl.h>
//read(), close(), write()
# include <unistd.h>
//malloc()
# include <stdlib.h>


//to-do: define key for MacOS
# ifdef __linux__
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
#  define ARROW_UP 65362
#  define ARROW_DOWN 65364
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
#  define  ESC_KEY 65307
// # elif __APPLE__
# endif

//to-do: define path to assets

# define HEIGHT 64
# define LENGTH 64

typedef struct position
{
	int	x;
	int	y;
} t_pos;

typedef struct counter
{
	int		walls;
	int		floors;
	int		collectibles;
	int		movements;
} t_count;

typedef struct player_data
{
	t_pos	current_pos;
	int		current_direction;
	int		next_movement;
} t_player;

/*
mlx : mlx pointer
window : window pointer
player : player struct
i : store all counter
*/
typedef struct game_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_pos		start;
	t_pos		exit;
	t_pos		*wall;
	t_pos		*floor;
	t_pos		*collect;
	t_count		i;
	int			collect_left;
	int			exit_state;
	t_player	*player;
} t_data;


#endif
