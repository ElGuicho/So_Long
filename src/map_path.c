/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:31:17 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/11 19:39:01 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

char	**follow_path(t_map *lay, int i, int j, char **map)
{
	if (lay->path_nb == 0)
	{
		ft_printf("Error\nInteractible is closed by walls\n");
		return (NULL);
	}
	else if (lay->path_nb == 1)
	{
		if (lay->path_right != 0)
		{
			lay->path_right++;
			lay->path_nb = 0;
			j++;
		}
		else if (lay->path_left != 0)
		{
			lay->path_left = 0;
			lay->path_nb = 0;
			j--;
		}
		else if (lay->path_up != 0)
		{
			lay->path_up = 0;
			lay->path_nb = 0;
			i--;
		}
		else if (lay->path_down != 0)
		{
			lay->path_down = 0;
			lay->path_nb = 0;
			i++;
		}
	}
	else if (lay->path_nb == 2)
	{
		if (lay->path_right != 0)
		{
			lay->path_right++;
			lay->path_nb = 0;
			j++;
		}
		else if (lay->path_left != 0)
		{
			lay->path_left = 0;
			lay->path_nb = 0;
			j--;
		}
		else if (lay->path_up != 0)
		{
			lay->path_up = 0;
			lay->path_nb = 0;
			i--;
		}
		else if (lay->path_down != 0)
		{
			lay->path_down = 0;
			lay->path_nb = 0;
			i++;
		}
	}
	return (map);
}

int	check_path(t_map *lay)
{
	int	i;
	int	j;
	char	**map;

	i = 1;
	map = lay->map;
	j = 1;
	lay->path_nb = 4;
	while (i < lay->n_row - 1)
	{
		while (j < lay->n_col - 1)
		{
			while (map[i][j] == '1' || map[i][j] == '0')
				j++;
		}
		i++;
	}
	while (lay->player != 0 && lay->collect != 0 && lay->exit != 0)
	{
		if (map[i][j] == 'P')
			lay->player--;
		else if (map[i][j] == 'C')
			lay->collect--;
		else if (map[i][j] == 'E')
			lay->exit--;
		if (map[i][j - 1] == '1')
		{
			lay->path_nb--;
			lay->path_left++;
		}
		if (map[i][j + 1] == '1')
		{
			lay->path_nb--;
			lay->path_right++;
		}
		if (map[i - 1][j] == '1')
		{
			lay->path_nb--;
			lay->path_up++;
		}
		if (map[i + 1][j] == '1')
		{
			lay->path_nb--;
			lay->path_down++;
		}
		map = follow_path(lay, i, j, map);
		if (!map)
			return (1);
	}
	return (0);	
}
