/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:22:36 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 18:08:18 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Lexicographically compares the null-terminated strings s1 and s2.
 * 
 * The strncmp() function compares not more than n characters.  Because 
 * strncmp() is designed for comparing strings rather than binary data, 
 * characters that appear after a `\0' character are not compared.
 * 
 * Returns an integer greater than, equal to, or less than 0, 
 * according as the string s1 is greater than, equal to, or less than the 
 * string s2. The comparison is done using unsigned characters, so 
 * that `\200' is greater than `\0'.
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		counter;

	counter = 0;
	while (counter < n)
	{
		if (s1[counter] != s2[counter])
		{
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		}		
		if (s1[counter] == '\0' && s2[counter] == '\0')
		{
			return (0);
		}
		counter++;
	}
	return (0);
}
