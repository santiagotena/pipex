/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:59:58 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/24 01:09:42 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Computes the length of the string s.  The strnlen() function 
 * attempts to compute the length of s, but never scans beyond the first 
 * maxlen bytes of s. Returns the number of characters that precede the 
 * terminating NUL character.
 * 
 * @param str 
 * @return size_t 
 */
size_t	ft_strlen(const char *str)
{
	size_t		counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter += 1;
	}
	return (counter);
}
