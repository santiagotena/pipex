/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:16:07 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/31 02:36:18 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string needle 
 * in the string haystack, where not more than len characters are searched. 
 * Characters that appear after a `\0' character are not searched.
 * 
 * If needle is an empty string, haystack is returned; if needle occurs 
 * nowhere in haystack, NULL is returned; otherwise a pointer to the first 
 * character of the first occurrence of needle is returned.
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* 
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_index;
	size_t	needle_index;
	char	*output;

	haystack_index = 0;
	needle_index = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack_index < len && haystack[haystack_index] != '\0')
	{
		if (haystack[haystack_index] == needle[needle_index])
		{
			output = (char *) &haystack[haystack_index];
			while ((needle_index + haystack_index) < len && \
				haystack[haystack_index + needle_index] == needle[needle_index])
			{
				needle_index++;
				if (needle_index == ft_strlen(needle))
					return (output);
			}
		}
		needle_index = 0;
		haystack_index++;
	}
	return (NULL);
}
