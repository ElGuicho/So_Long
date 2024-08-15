/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:40 by gmunoz            #+#    #+#             */
/*   Updated: 2024/08/15 14:33:05 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	init_vars(t_vars *vars, t_map *lay, t_data *img)
{
	img->x = 128;
	img->y = 128;
	vars->steps = 0;
	lay->collect = 0;
	lay->exit = 0;
	lay->player = 0;
	lay->n_row = 0;
	lay->map = NULL;
}

int	map_err(char *line, t_map *lay, int i)
{
	if (!line)
	{
		ft_printf("map is empty\n");
		return (0);
	}
	if (line[gnl_strlen(line) - 1] != '\n')
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
	map = gnl_strjoin(map, line);
	if (!map)
	{
		ft_printf("gnl_strjoin failed\n");
		return (NULL);
	}
	return (map);
}

char	**sort_map(char const *argv, t_map *lay)
{
	int		fd;
	int		i;
	char	*line;
	char	*map;

	map = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("open failed\n");
		return (NULL);
	}
	line = get_next_line(fd);
	
	while (1)
	{
		i = 0;
		if (map_err(line, lay, i) == 0)
			return (NULL);
		map = check_char(line, lay, i, map);
		if (map == NULL)
			return (NULL);
		if (map_err(line, lay, i) == 2)
			break ;
		line = get_next_line(fd);
	}
	while (line[i] < gnl_strlen(line))
	{
		if (line[i] != '1')
		{
			if (line[gnl_strlen(line) - 1] == '\n')
				break ;
			ft_printf("map is not closed\n");
			return (NULL);
		}
		i++;
	}
	close(fd);
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
		return (NULL);
	return (map);
}

int main(int argc, char const **argv)
{
	t_data	*img;
	t_vars	*vars;
	t_map	*lay;
	char	*relative_path = "sprites/char_trial.xpm";
	char	*relative_path2 = "sprites/floor-tileset.xpm";
	int		img_width;
	int		img_height;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
	{
		ft_printf("vars malloc failed\n");
		return 1;
	}
	img = malloc(sizeof(t_data));
	if (img == NULL)
	{
		ft_printf("img malloc failed\n");
		free(vars);
		return 1;
	}
	lay = malloc(sizeof(t_map));
	if (lay == NULL)
	{
		ft_printf("lay malloc failed\n");
		free(vars);
		free(img);
		return 1;
	}
	if (vars->img == NULL)
		vars->img = malloc(sizeof(t_data));
	if (vars->img == NULL)
	{
		ft_printf("vars img malloc failed\n");
		free(vars);
		free(img);
		free(lay);
		return 1;
	}
	if (vars->lay == NULL)
		vars->lay = malloc(sizeof(t_map));
	if (vars->lay == NULL)
	{
		ft_printf("vars lay malloc failed\n");
		free(vars);
		free(img);
		free(lay);
		free(vars->img);
		return 1;
	}
	init_vars(vars, lay, img);
	lay->map = map_check(argc, argv, lay);
	if (lay->map == NULL)
	{
		ft_printf("map_check failed\n");
		return 1;
	}
	if (lay->player == 0 || lay->collect == 0 || lay->exit == 0 ||
		lay->n_row < 3 || lay->n_col < 5)
	{
		ft_printf("map is invalid\n");
		return 1;
	}
	else
		ft_printf("map is read and valid\n");
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
	    ft_printf("mlx_init failed\n");
		return 1;
	}
	ft_printf("lay n_row = %d\n", lay->n_row);
	ft_printf("lay n_col = %d\n", lay->n_col);
	vars->win = mlx_new_window(vars->mlx, lay->n_col * 64, \
		lay->n_row * 128, "Tudi Gaimu");
	//vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Tudi Gaimu"); 2176 x 768
	if (!vars->win)
	{
	    ft_printf("mlx_new_window failed\n");
	    return 1;
	}
	mlx_hook(vars->win, 2, 1L<<0, close_win, vars);
	mlx_hook(vars->win, 17, 1L<<0, close_window, vars);
	mlx_do_sync(vars->mlx);
	mlx_key_hook(vars->win, key_hook, vars);
	img->img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
	if (!img->img)
	{
	    ft_printf("mlx_xpm_file_to_image failed\n");
	    return 1;
	}

	img->img2 = mlx_xpm_file_to_image(vars->mlx, relative_path2, &img_width, &img_height);
	if (!img->img2)
	{
	    ft_printf("mlx_xpm_file_to_image2 failed\n");
	    return 1;
	}

	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->addr)
	{
		ft_printf("mlx_get_data_addr failed\n");
	    return 1;
	}
	//mlx_put_image_to_window(vars->mlx, vars->win, img->img, img->x, img->y);
	vars->img = img;
	mlx_do_sync(vars->mlx);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
	return 0;
}

/* 
img->img = mlx_new_image(mlx, 1920, 1080);
ft_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} */


/*
mlx_mouse_hook(vars->win, mouse_hook, &vars);

int mouse_hook(int button, int x, int y, t_vars *vars)
{
	ft_printf("Mouse button %d pressed at position %d, %d\n", button, x, y);
	(void)vars;
	return (0);
} */

