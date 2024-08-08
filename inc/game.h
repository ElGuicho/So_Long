/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:13:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/08/08 19:51:44 by gmunoz           ###   ########.fr       */
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
	char	**map;
}				t_map;

#endif