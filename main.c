/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:40 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/19 18:45:22 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(int argc, char const *argv[])
{
	void *mlx;
	void *win;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "Ventanita");
	(void)win;

	mlx_loop(mlx);
	return 0;
}
