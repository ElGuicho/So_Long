/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:13:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/08/08 17:55:31 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "colors.h"
# include "../Libft/libft.h"

typedef struct	s_map {
	int		n_col;
	int		n_row;
	char	**map;
}				t_map;

#endif