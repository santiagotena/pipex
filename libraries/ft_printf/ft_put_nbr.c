/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:22:05 by stena-he          #+#    #+#             */
/*   Updated: 2022/07/03 19:23:37 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_length(int x)
{
	int		index;

	index = 0;
	if (x < 0)
		index++;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 10;
		index++;
	}
	return (index);
}

void	ft_putnbr(int nb)
{	
	int		out;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		out = nb + '0';
		write(1, &out, 1);
	}
}

int	ft_put_nbr(va_list args)
{
	int		value;

	value = va_arg(args, int);
	ft_putnbr(value);
	return (ft_int_length(value));
}
