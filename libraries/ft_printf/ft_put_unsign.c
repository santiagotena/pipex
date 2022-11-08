/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:28:00 by stena-he          #+#    #+#             */
/*   Updated: 2022/07/03 19:47:48 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(unsigned int digit)
{
	int		d;

	d = digit + '0';
	write(1, &d, 1);
}

int	ft_unsign_length(unsigned int x)
{
	int		index;

	index = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 10;
		index++;
	}
	return (index);
}

void	unsign_recursion(unsigned int nb)
{
	if (nb > 9)
	{
		nb = nb / 10;
		unsign_recursion(nb);
		ft_putchar(nb % 10);
	}
}

void	ft_put_unsign_nb(unsigned int nb)
{	
	unsign_recursion(nb);
	ft_putchar(nb % 10);
}

int	ft_put_unsign(va_list args)
{
	int unsigned	value;

	value = va_arg(args, unsigned int);
	ft_put_unsign_nb(value);
	return (ft_unsign_length(value));
}
