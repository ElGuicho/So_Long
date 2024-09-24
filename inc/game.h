/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:13:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/24 18:18:21 by gmunoz           ###   ########.fr       */
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

typedef struct s_map
{
	int		n_col;
	int		n_row;
	int		player;
	int		player_cp;
	int		player_x;
	int		player_y;
	int		collect;
	int		collect_cp;
	int		exit;
	int		exit_cp;
	int		path_nb;
	int		path_up;
	int		path_down;
	int		path_left;
	int		path_right;
	int		init_x;
	int		init_y;
	char	**map;
	int		map_fd;
}				t_map;

typedef struct s_data
{
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

typedef struct s_vars
{
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
void	init_imgs(t_vars *vars, t_data *img);
int		img_err(t_vars *vars, void **img_ptr, char *img_name);
void	put_sprites(t_vars *vars, t_map *lay, t_data *img);
int		create_map(int argc, const char **argv, t_map *lay);
int		map_err(char *line, t_map *lay, int i);
char	*check_char(char *line, t_map *lay, int i, char *map);
void	freee(t_data *img, t_vars *vars, t_map *lay);
int		check_path(t_map *lay);
int		path_loop(t_map *lay, char **map);
void	check_interactibles(t_map *lay, int i, int j, char **map);
void	map_free(char **map, int n_row);

#endif