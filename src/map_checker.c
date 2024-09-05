/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:29:46 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/05 20:01:49 by gmunoz           ###   ########.fr       */
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
				ft_printf("map is not closed\n");
				return (0);
			}
			i++;
		}
		if (lay->n_col == gnl_strlen(line))
		{
			ft_printf("map is read\n");
			return (2);
		}
		else
		{
			ft_printf("map is not rectangular\n");
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
				if (line[gnl_strlen(line) - 1] == '\n')
					break ;
				ft_printf("map is not closed\n");
				return (0);
			}
			i++;
		}
	}
	else if (line[0] != '1' || (line[gnl_strlen(line) - 2] != '1' &&
		line[gnl_strlen(line) - 1] != '\n'))
	{
		ft_printf("map is not closed\n");
		return (0);
	}
	if (lay->n_col != gnl_strlen(line) - 1)
	{
		ft_printf("map is not rectangular\n");
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
			lay->player = 1;
		}
		if (line[i] == 'C')
			lay->collect++;
		if (line[i] == 'E')
			lay->exit = 1;
		i++;
	}
	lay->n_row++;
	tmp = gnl_strjoin(map, line);
	if (!tmp)
	{
		ft_printf("gnl_strjoin failed\n");
		return (NULL);
	}
	return (tmp);
}

char	**sort_map(char const *argv, t_map *lay)
{
	int		i;
	char	*line;
	char	*map;

	map = NULL;
	lay->map_fd = open(argv, O_RDONLY);
	if (lay->map_fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(lay->map_fd);
		if (!line)
			return (NULL);
		i = 0;
		if (map_err(line, lay, i) == 0)
			return (free(line), NULL);
		map = check_char(line, lay, i, map);
		if (map == NULL)
			return (free(line), NULL);
		if (map_err(line, lay, i) == 2)
			break ;
		free(line);
	}
	free(line);
	return (ft_split(map, '\n'));
}

char	**map_check(int argc, char const **argv, t_map *lay)
{
	char	**map;
	
	if (argc != 2)
	{
		ft_printf("wrong number of arguments\n");
		return (NULL);
	}
	if (ft_strnstr(argv[1], ".ber", gnl_strlen(argv[1])) == NULL)
	{
		ft_printf("wrong file extension\n");
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
	{
		ft_printf("map_check failed\n");
		return (1);
	}
	if (lay->player == 0 || lay->collect == 0 || lay->exit == 0 ||
		lay->n_row < 3 || lay->n_col < 5)
	{
		ft_printf("map is invalid\n");
		return (1);
	}
	else
		ft_printf("map is read and valid\n");
	return (0);
}
