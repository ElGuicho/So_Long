/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:13:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/05 16:30:57 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "colors.h"
# include "../Libft/libft.h"
# include "../Libft/ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_map {
	int		n_col;
	int		n_row;
	int		player;
	int		player_x;
	int		player_y;
	int		collect;
	int		exit;
	char	**map;
	int		map_fd;
}				t_map;

typedef struct	s_data {
	void	*main_char;
	void	*floor;
	void	*corner_up_left;
	void	*corner_up_right;
	void	*corner_down_left;
	void	*corner_down_right;
	void	*wall_up;
	void	*wall_down;
	void	*wall_left;
	void	*wall_right;
	void	*inner_wall;
	void	*door_exit;
	void	*char_in_door;
	void	*coin;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		up;
	int		down;
	int		left;
	int		right;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		steps;
	int		screen_size;
	t_data	*img;
	t_map	*lay;
}				t_vars;

int		close_win(int keycode, t_vars *vars);
int		close_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		render_next_frame(t_vars *vars);
void	move_up(t_vars *vars);
void	move_left(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
void	endgame(t_vars *vars);
void	init_vars(t_vars *vars, t_map *lay, t_data *img);
int		init_mlx(t_vars *vars, t_map *lay);
int		init_imgs(t_vars *vars, t_data *img);
int		img_err(t_vars *vars, void **img_ptr, char *img_name);
void	put_sprites(t_vars *vars);
int		create_map(int argc, const char **argv, t_map *lay);

#endif