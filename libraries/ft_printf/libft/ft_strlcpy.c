/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:32:48 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/29 19:07:22 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy and concatenate strings with the same input parameters and 
 * output result as snprintf(3).  Takes the full size of the destination 
 * buffer and guarantees NUL-termination if there is room.  Note that room 
 * for the NUL should be included in dstsize.
 * 
 * Copies up to dstsize - 1 characters from the string src to dst, 
 * NUL-terminating the result if dstsize is not 0.
 * 
 * If the src and dst strings overlap, the behavior is undefined.
 * 
 * Returns the length of src.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	counter;

	index = 0;
	counter = 0;
	if (!dst || !src)
		return (0);
	while (src[counter] != '\0')
	{
		counter++;
	}
	if (dstsize == 0)
		return (counter);
	while (index < dstsize - 1 && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (counter);
}
