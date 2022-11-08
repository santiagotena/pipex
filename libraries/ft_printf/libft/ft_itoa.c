/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:26:33 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/21 12:08:50 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_length(int x)
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

char	*ft_char_output(int length, int minus, char *output, int n)
{
	while (length + minus >= 0)
	{
		output[length + minus] = n % 10 + '0';
		n = n / 10;
		if (length == 0 && minus == 1)
		{
			output[0] = '-';
			break ;
		}
		length--;
	}
	return (output);
}

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the 
 * integer received as an argument. Negative numbers must be handled.
 * 
 * Returns the string representing the integer. NULL if the allocation fails.
 * 
 * @param n 
 * @return char* 
 */
char	*ft_itoa(int n)
{
	char	*output;
	int		minus;
	int		length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		n = n * -1;
	}
	length = ft_int_length(n);
	output = (char *) malloc((length + minus + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output[length + minus] = '\0';
	length--;
	output = ft_char_output(length, minus, output, n);
	return (output);
}
