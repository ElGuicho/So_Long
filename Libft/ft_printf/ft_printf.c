/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:04:57 by gmunoz            #+#    #+#             */
/*   Updated: 2024/04/17 14:42:19 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(va_list args, const char *str, int nbytes)
{
	int	i;

	i = 0;
	nbytes++;
	if (str[nbytes] == 'c')
		i = ifchar(args, i);
	else if (str[nbytes] == 's')
		i = ifstr(args, i);
	else if (str[nbytes] == 'p')
		i = ifptr(args, i);
	else if (str[nbytes] == 'd' || str[nbytes] == 'i')
		i = ifdec(args, i);
	else if (str[nbytes] == 'u')
		i = ifdecns(args, i);
	else if (str[nbytes] == 'x')
		i = ifhexa(args, i);
	else if (str[nbytes] == 'X')
		i = ifhexa_caps(args, i);
	else if (str[nbytes] == '%')
		i = printf_putstr_fd("%", 1);
	return (i);
}

int	total_nbytes(va_list args, const char *str, int nbytes, int i)
{
	int	format_bytes;

	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			format_bytes = format(args, str, i);
			if (format_bytes == -1)
				return (-1);
			nbytes = nbytes + format_bytes;
			if (format_bytes == -2)
				nbytes += 2;
			if (format_bytes != 0)
				i++;
		}
		else
		{
			if (write(1, &str[i], 1) == -1)
				return (-1);
			nbytes++;
		}
		i++;
	}
	return (nbytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nbytes;
	int		i;

	i = 0;
	nbytes = 0;
	va_start(args, str);
	nbytes = total_nbytes(args, str, nbytes, i);
	va_end(args);
	return (nbytes);
}
