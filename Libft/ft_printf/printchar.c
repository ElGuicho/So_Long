/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:59:08 by gmunoz            #+#    #+#             */
/*   Updated: 2024/01/15 16:39:07 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ifchar(va_list args, int i)
{
	char	letter;

	letter = va_arg(args, int);
	i = 1;
	if (write(1, &letter, 1) == -1)
		return (-1);
	return (i);
}
