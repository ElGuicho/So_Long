/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:29:46 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/25 17:38:12 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

char	*char_n_err(char *line, t_map *lay, char *map)
{
	char	*temp_map;

	if (map_err(line, lay, 0) == 0)
	{
		free_gnl(lay, line, map);
		return (NULL);
	}
	temp_map = map;
	map = check_char(line, lay, 0, map);
	if (map == NULL)
	{
		free_gnl(lay, line, temp_map);
		return (NULL);
	}
	return (map);
}

char	*map_loop(t_map *lay)
{
	char	*line;
	char	*map;

	map = NULL;
	while (1)
	{
		line = get_next_line(lay->map_fd);
		if (!line)
		{
			if (map)
				free(map);
			return (NULL);
		}
		map = char_n_err(line, lay, map);
		if (map == NULL)
			return (NULL);
		if (map_err(line, lay, 0) == 2)
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (map);
}

char	**sort_map(char const *map_file, t_map *lay)
{
	char	*map;
	char	**real_map;

	lay->map_fd = open(map_file, O_RDONLY);
	if (lay->map_fd == -1)
		return (NULL);
	map = map_loop(lay);
	close(lay->map_fd);
	if (map == NULL)
		return (NULL);
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
		return (NULL);
	return (map);
}

int	create_map(int argc, const char **argv, t_map *lay)
{
	lay->map = map_check(argc, argv, lay);
	if (lay->map == NULL)
		return (1);
	if (lay->player == 0 || lay->player > 1 || lay->collect == 0
		|| lay->exit == 0 || lay->exit > 1 || (lay->n_row < 3 && lay->n_col < 5)
		|| (lay->n_row < 5 && lay->n_col < 3))
	{
		ft_printf("Error\nThe map is invalid\n");
		return (1);
	}
	return (0);
}
