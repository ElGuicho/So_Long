/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:40 by gmunoz            #+#    #+#             */
/*   Updated: 2024/04/17 14:51:16 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ifdec(va_list args, int i)
{
	int		n;
	char	*str;

	n = va_arg(args, int);
	if (n < 0)
		i++;
	if (n == -2147483648)
		return (printf_putstr_fd("-2147483648", 1));
	if (n == 0)
		return (printf_putstr_fd("0", 1));
	str = printf_itoa(n);
	if (!str)
		return (-1);
	i = i + printf_strlen(str);
	if (printf_putstr_fd(str, 1) == -1)
		i = -1;
	free (str);
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, (const void *)&c, 1) == -1)
		return (-1);
	return (0);
}

int	ft_put_unsigned(unsigned int n)
{
	long	nb;

	nb = (long)n;
	if (nb >= 10)
	{
		if (ft_put_unsigned(nb / 10) == -1)
			return (-1);
		if (ft_putchar_fd((nb % 10) + '0', 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd(nb + '0', 1) == -1)
			return (-1);
	}
	return (0);
}

int	ifdecns(va_list args, int i)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (ft_put_unsigned(n) == -1)
		return (-1);
	i = countn(n);
	return (i);
}
