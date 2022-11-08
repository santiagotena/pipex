/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 11:34:09 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/06 22:17:32 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates enough space for count objects that are size bytes of 
 * memory each and returns a pointer to the allocated memory.  The 
 * allocated memory is filled with bytes of value zero. If there is an 
 * error, they return a NULL pointer and set errno to ENOMEM.
 * 
 * @param count 
 * @param size Use sizeof(<data_type>)
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*output;

	if (count >= 4294967295 || size >= 4294967295)
		return (NULL);
	output = malloc(count * size);
	if (!output)
		return (NULL);
	ft_bzero(output, count * size);
	return (output);
}
