/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:33:07 by stena-he          #+#    #+#             */
/*   Updated: 2022/07/03 20:56:57 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer(unsigned long int ptr)
{
	write(1, "0x", 2);
	if (ptr == 0)
		write(1, "0", 1);
	else
		ft_put_low_hexadec_nb(ptr);
}

int	ft_put_ptr(va_list args)
{
	unsigned long int	value;

	value = va_arg(args, unsigned long int);
	ft_put_pointer(value);
	return (2 + ft_hexadec_length(value));
}
