/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:11:03 by stena-he          #+#    #+#             */
/*   Updated: 2022/07/03 21:34:16 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	int		index;
	va_list	args;

	count = 0;
	index = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			if (str[index] == '\0')
				return (0);
			count = count + percent_func(args, str[index]);
		}
		else
		{
			write(1, &str[index], 1);
			count++;
		}
		index++;
	}
	va_end(args);
	return (count);
}

int	percent_func(va_list args, char flag)
{
	if (flag == 'c')
		return (ft_put_char(args));
	else if (flag == 's')
		return (ft_put_str(args));
	else if (flag == 'p')
		return (ft_put_ptr(args));
	else if (flag == 'i' || flag == 'd')
		return (ft_put_nbr(args));
	else if (flag == 'u')
		return (ft_put_unsign(args));
	else if (flag == 'x')
		return (ft_put_low_hexadec(args));
	else if (flag == 'X')
		return (ft_put_upp_hexadec(args));
	else if (flag == '%')
	{
		write(1, &flag, 1);
		return (1);
	}
	return (0);
}
