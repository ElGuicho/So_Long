/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:57:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/24 19:04:38 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	map_cpy(t_map *lay, char **map, int i, int j)
{
	while (i < lay->n_row)
	{
		map[i] = ft_strdup(lay->map[i]);
		if (!map[i])
			return (map_free(map, i), 1);
		i++;
	}
	i = 1;
	while (i < lay->n_row - 1)
	{
		j = 1;
		while (j < lay->n_col - 1)
		{
			if (map[i][j] != '1' && map[i][j] != '0')
				break ;
			j++;
		}
		if (map[i][j] != '1' && map[i][j] != '0')
			break ;
		i++;
	}
	lay->init_x = j;
	lay->init_y = i;
	return (0);
}

int	path_algorithm(t_map *lay, char **map)
{
	check_interactibles(lay, lay->init_y, lay->init_x, map);
	if (lay->path_nb == 0)
	{
		ft_printf("Error\nInteractible is closed by walls\n");
		return (1);
	}
	if (path_loop(lay, map) == 1)
	{
		ft_printf("Error\nMap can't be completed\n");
		return (1);
	}
	return (0);
}

int	check_path(t_map *lay)
{
	char	**map;
	int		i;

	i = 0;
	lay->collect_cp = lay->collect;
	lay->exit_cp = lay->exit;
	lay->player_cp = lay->player;
	map = malloc(sizeof(char *) * lay->n_row);
	if (!map)
		return (1);
	while (i < lay->n_row)
	{
		map[i] = NULL;
		i++;
	}
	map_cpy(lay, map, 0, 0);
	if (path_algorithm(lay, map) == 1)
		return (map_free(map, lay->n_row), 1);
	ft_printf("There is a viable path\n");
	map_free(map, lay->n_row);
	return (0);
}
