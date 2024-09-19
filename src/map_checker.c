/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:29:46 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/19 17:57:20 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	map_err(char *line, t_map *lay, int i)
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
	else if (line[0] != '1' || (line[gnl_strlen(line) - 2] != '1' ||
		line[gnl_strlen(line) - 1] != '\n'))
	{
		ft_printf("Error\nMap is not closed\n");
		return (0);
	}
	if (lay->n_col != gnl_strlen(line) - 1)
	{
		ft_printf("Error\nMap is not rectangular\n");
		return (0);
	}
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

char	**sort_map(char const *argv, t_map *lay)
{
	int		i;
	char	*line;
	char	*map;
	char	**real_map;
	char	*temp_map;

	map = NULL;
	lay->map_fd = open(argv, O_RDONLY);
	if (lay->map_fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(lay->map_fd);
		if (!line)
		{
			if (temp_map)
				free(temp_map);
			if (map)
				free(map);
			return (NULL);
		}
		i = 0;
		if (map_err(line, lay, i) == 0)
		{
			if (map)
				free(map);
			return (free(line), NULL);
		}
		temp_map = map;
		map = check_char(line, lay, i, map);
		if (map == NULL)
		{
			if (temp_map)
				free(temp_map);
			return (free(line), NULL);
		}
		if (map_err(line, lay, i) == 2)
		{
			free(line);
			break ;
		}
		free(line);
	}
	real_map = ft_split(map, '\n');
	free(map);
	return (real_map);
}

char	**map_check(int argc, char const **argv, t_map *lay)
{
	char	**map;
	
	if (argc != 2)
	{
		ft_printf("Error\nProgram only needs 1 extra argument\n");
		return (NULL);
	}
	if (ft_strnstr(argv[1], ".ber", gnl_strlen(argv[1])) == NULL)
	{
		ft_printf("Error\nWrong file extension: needs to be \".ber\"\n");
		return (NULL);
	}
	map = sort_map(argv[1], lay);
	if (map == NULL)
	{
		close(lay->map_fd);
		return (NULL);
	}
	close(lay->map_fd);
	return (map);
}

int	create_map(int argc, const char **argv, t_map *lay)
{
	lay->map = map_check(argc, argv, lay);
	if (lay->map == NULL)
		return (1);
	if (lay->player == 0 || lay->player > 1 || lay->collect == 0 ||
	lay->exit == 0 || lay->exit > 1 || (lay->n_row < 3 && lay->n_col < 5) ||
	(lay->n_row < 5 && lay->n_col < 3))
	{
		ft_printf("Error\nThe map is invalid\n");
		return (1);
	}
	return (0);
}
