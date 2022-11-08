/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:40:23 by stena-he          #+#    #+#             */
/*   Updated: 2022/07/03 18:58:54 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(va_list args)
{
	int		index;
	char	*value;

	index = 0;
	value = va_arg(args, char *);
	if (value == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (value[index])
	{
		write(1, &value[index], 1);
		index++;
	}
	return (ft_strlen(value));
}
