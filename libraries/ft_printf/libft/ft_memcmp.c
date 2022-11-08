/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:08:36 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/23 14:20:45 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares byte string s1 against byte string s2.  Both strings are 
 * assumed to be n bytes long. Returns zero if the two strings are identical, 
 * otherwise returns the difference between the first two differing bytes 
 * (treated as unsigned char values, so that `\200' is greater than `\0', 
 * for example).  Zero-length strings are always identical.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	counter;
	char	*ptr1;
	char	*ptr2;

	counter = 0;
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (counter < n)
	{
		if (ptr1[counter] != ptr2[counter])
		{
			return ((unsigned char)ptr1[counter]
				- (unsigned char)ptr2[counter]);
		}
		counter++;
	}
	return (0);
}
