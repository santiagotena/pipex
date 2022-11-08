/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:16:56 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 17:17:23 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts the initial portion of the string pointed to by str to 
 * int representation.
 * 
 * @param str 
 * @return int 
 */
int	ft_atoi(const char *str)
{
	int		output;
	int		sign;
	int		index;

	output = 0;
	sign = 1;
	index = 0;
	while (str[index] != '\0' && ((str[index] >= 9 && str[index] <= 13)
			|| str[index] == 32))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
			return (sign * output);
		output = output * 10 + (str[index] - '0');
		index++;
	}
	return (sign * output);
}
