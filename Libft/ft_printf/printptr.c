/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:08:28 by gmunoz            #+#    #+#             */
/*   Updated: 2024/04/17 14:46:18 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ifptr(va_list args, int i)
{
	unsigned long	ptr;
	char			*hexa_str;

	ptr = va_arg(args, unsigned long);
	if (ptr == (unsigned long)LONG_MIN)
		return (printf_putstr_fd("0x8000000000000000", 1));
	if (ptr == (unsigned long)LONG_MAX)
		return (printf_putstr_fd("0x7fffffffffffffff", 1));
	if (ptr == ULONG_MAX)
		return (printf_putstr_fd("0xffffffffffffffff", 1));
	if (ptr == 0)
		return (printf_putstr_fd("0x0", 1));
	hexa_str = ptr_to_hexa(ptr);
	if (!hexa_str)
		return (-1);
	i = printf_strlen(hexa_str) + 2;
	if ((write(1, "0x", 2) == -1) || (printf_putstr_fd(hexa_str, 1) == -1))
		i = -1;
	free (hexa_str);
	return (i);
}
