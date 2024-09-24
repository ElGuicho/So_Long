/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:18:02 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/24 18:51:32 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	last_line_err(char *line, t_map *lay, int i)
{
	if (line[gnl_strlen(line) - 1] != '\n' && line[gnl_strlen(line)] == '\0')
	{
		while (line[i] != '\0')
		{
			if (line[i] != '1')
			{
				ft_printf("Error\nMap is not closed\n");
				return (0);
			}
			i++;
		}
		if (lay->n_col == gnl_strlen(line))
			return (2);
		else
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (0);
		}
	}
	return (1);
}

int	mid_line_err(char *line, t_map *lay, int i)
{
	if (line[0] != '1' || (line[gnl_strlen(line) - 2] != '1'
			|| line[gnl_strlen(line) - 1] != '\n'))
	{
		ft_printf("Error\nMap is not closed\n");
		return (0);
	}
	if (lay->n_col != gnl_strlen(line) - 1)
	{
		ft_printf("Error\nMap is not rectangular\n");
		return (0);
	}
	while (i < gnl_strlen(line) - 1)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
		{
			ft_printf("Error\nInvalid character in map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_err(char *line, t_map *lay, int i)
{
	if (last_line_err(line, lay, 0) == 0)
		return (0);
	if (last_line_err(line, lay, 0) == 2)
		return (2);
	if (lay->n_row == 0)
	{
		i = 0;
		lay->n_col = gnl_strlen(line) - 1;
		while (i < gnl_strlen(line) - 1)
		{
			if (line[i] != '1')
			{
				if (line[gnl_strlen(line) - 1] == '\n' && line[i] == '\n')
					break ;
				ft_printf("Error\nMap is not closed\n");
				return (0);
			}
			i++;
		}
	}
	else if (mid_line_err(line, lay, 0) == 0)
		return (0);
	return (1);
}

char	*check_char(char *line, t_map *lay, int i, char *map)
{
	char	*tmp;

	while (i < gnl_strlen(line))
	{
		if (line[i] == 'P')
		{
			lay->player_x = i;
			lay->player_y = lay->n_row;
			lay->player++;
		}
		if (line[i] == 'C')
			lay->collect++;
		if (line[i] == 'E')
			lay->exit++;
		i++;
	}
	lay->n_row++;
	tmp = gnl_strjoin(map, line);
	if (!tmp)
		return (NULL);
	return (tmp);
}
