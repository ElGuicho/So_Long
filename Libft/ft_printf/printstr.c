/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:07:35 by gmunoz            #+#    #+#             */
/*   Updated: 2024/04/17 14:46:47 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ifstr(va_list args, int i)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == (char *) NULL)
	{
		if (printf_putstr_fd("(null)", 1) == -1)
			return (-1);
		return (6);
	}
	if (str[0] == '\0')
		return (-2);
	i = printf_strlen(str);
	if (printf_putstr_fd(str, 1) == -1)
		return (-1);
	return (i);
}
