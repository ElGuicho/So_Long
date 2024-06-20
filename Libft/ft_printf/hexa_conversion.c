/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:47:54 by gmunoz            #+#    #+#             */
/*   Updated: 2024/04/17 14:49:39 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countlhexa(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	counthexa(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ptr_to_hexa(unsigned long str)
{
	int		temp;
	char	*ptr;
	int		i;

	i = countlhexa(str);
	ptr = printf_calloc(i + 1, 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	i--;
	while (str != 0)
	{
		temp = str % 16;
		ptr[i] = HEXALOWER[temp];
		i--;
		str /= 16;
	}
	return (ptr);
}

char	*dec_to_hexalower(unsigned int str)
{
	int		temp;
	char	*ptr;
	int		i;

	i = counthexa(str);
	ptr = printf_calloc(i + 1, 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	i--;
	while (str != 0)
	{
		temp = str % 16;
		ptr[i] = HEXALOWER[temp];
		i--;
		str /= 16;
	}
	return (ptr);
}

char	*dec_to_hexaupper(unsigned int str)
{
	int		temp;
	char	*ptr;
	int		i;

	i = counthexa(str);
	ptr = printf_calloc(i + 1, 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	i--;
	while (str != 0)
	{
		temp = str % 16;
		ptr[i] = HEXAUPPER[temp];
		i--;
		str /= 16;
	}
	return (ptr);
}
