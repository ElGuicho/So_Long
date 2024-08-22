/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:13:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/08/22 18:10:14 by gmunoz           ###   ########.fr       */
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
}				t_map;

typedef struct	s_data {
	void	*img;
	void	*img2;
	void	*corner_up_left;
	void	*corner_up_right;
	void	*corner_down_left;
	void	*corner_down_right;
	void	*wall_up;
	void	*wall_down;
	void	*wall_left;
	void	*wall_right;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		steps;
	int		screen_size;
	t_data	*img;
	t_map	*lay;
}				t_vars;

int	close_win(int keycode, t_vars *vars);
int	close_window(t_vars *vars);
int	key_hook(int keycode, t_vars *vars);
int	render_next_frame(t_vars *vars);

#endif