/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:14:04 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 17:18:03 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes n zeroed bytes to the string s. 
 * If n is zero, bzero() does nothing.
 * 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*ptr;

	ptr = (char *)s;
	counter = 0;
	while (counter < n)
	{
		if (ptr[counter] != 0)
			ptr[counter] = 0;
		counter++;
	}
}
