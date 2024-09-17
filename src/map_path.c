/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:31:17 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/17 19:16:17 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	map_free(char **map, int n_row)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < n_row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_interactibles(t_map *lay, int i, int j, char **map)
{
	lay->path_nb = 4;
	if (map[i][j] == 'P')
		lay->player_cp--;
	else if (map[i][j] == 'C')
		lay->collect_cp--;
	else if (map[i][j] == 'E')
		lay->exit_cp--;
	if (map[i][j - 1] == '1' || map[i][j - 1] == '2' || map[i][j - 1] == '3' || map[i][j - 1] == '4')
		lay->path_nb--;
	else
		lay->path_left++;
	if (map[i][j + 1] == '1' || map[i][j + 1] == '2' || map[i][j + 1] == '3' || map[i][j + 1] == '4')
		lay->path_nb--;
	else
		lay->path_right++;
	if (map[i - 1][j] == '1' || map[i - 1][j] == '2' || map[i - 1][j] == '3' || map[i - 1][j] == '4')
		lay->path_nb--;
	else
		lay->path_up++;
	if (map[i + 1][j] == '1' || map[i + 1][j] == '2' || map[i + 1][j] == '3' || map[i + 1][j] == '4')
		lay->path_nb--;
	else
		lay->path_down++;
}

char	**follow_path(t_map *lay, int i, int j, char **map)
{
	int	n;

	n = lay->path_nb;
	map[i][j] = n + '0';
	if (lay->path_right != 0)
	{
		lay->path_right = 0;
		lay->path_nb = 0;
		lay->init_x++;
	}
	else if (lay->path_left != 0)
	{
		lay->path_left = 0;
		lay->path_nb = 0;
		lay->init_x--;
	}
	else if (lay->path_up != 0)
	{
		lay->path_up = 0;
		lay->path_nb = 0;
		lay->init_y--;
	}
	else if (lay->path_down != 0)
	{
		lay->path_down = 0;
		lay->path_nb = 0;
		lay->init_y++;
	}
	return (map);
}

int	follow_path2(t_map *lay, int i, int j, char **map)
{
	int	path_nb;

	path_nb = 4;
	while (path_nb > 1)
	{
		i = 1;
		while (i < lay->n_row - 1)
		{
			j = 1;
			while (j < lay->n_col - 1)
			{
				if (map[i][j] == path_nb + '0')
				{
					lay->init_x = j;
					lay->init_y = i;
					return (path_nb);
				}
				j++;
			}
			i++;
		}
		path_nb--;
	}
	return (path_nb);
}

int	path_loop(t_map *lay, char **map)
{
	while (lay->player_cp != 0 && lay->collect_cp != 0 && lay->exit_cp != 0)
	{
		check_interactibles(lay, lay->init_y, lay->init_x, map);
		if (lay->path_nb > 0)
			map = follow_path(lay, lay->init_y, lay->init_x, map);
		else
		{
			lay->path_nb = follow_path2(lay, lay->init_y, lay->init_x, map);
			if (lay->path_nb > 1)
				path_loop(lay, map);
			else if (lay->player_cp != 0 || lay->collect_cp != 0 || lay->exit_cp != 0)
			{
				ft_printf("Error\nMap can't be completed\n");
				return (1);
			}
		}
		if (!map)
		{
			ft_printf("Error\nMap can't be completed\n");
			return (1);
		}
	}
	return (0);
}

int	check_path(t_map *lay)
{
	int	i;
	int	j;
	char	**map;

	lay->collect_cp = lay->collect;
	lay->exit_cp = lay->exit;
	lay->player_cp = lay->player;
	i = 0;
	map = malloc(sizeof(char *) * lay->n_row);
	if (!map)
		return (1);
	while (i < lay->n_row)
	{
		map[i] = NULL;
		i++;
	}
	i = 0;
	while (i < lay->n_row - 1)
	{
		map[i] = ft_strdup(lay->map[i]);
		if (!map[i])
		{
			map_free(map, i);
			return (1);
		}
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
	check_interactibles(lay, i, j, map);
	if (lay->path_nb == 0)
	{
		ft_printf("Error\nInteractible is closed by walls\n");
		map_free(map, lay->n_row);
		return (1);
	}
	if (path_loop(lay, map) == 1)
	{
		map_free(map, lay->n_row);
		return (1);
	}
	ft_printf("There is a viable path\n");
	map_free(map, lay->n_row);
	return (0);	
}
