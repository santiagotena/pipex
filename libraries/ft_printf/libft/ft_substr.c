/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 09:23:12 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/04 10:32:33 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the 
 * string ’s’. The substring begins at index ’start’ and is of maximum 
 * size ’len’.
 * 
 * Returns the substring or NULL if the allocation fails.
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	substr_len;
	size_t	output_index;

	if (s == NULL)
		return (NULL);
	substr_len = ft_strlen(s) - start + 1;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (substr_len > len)
		substr_len = len;
	output = (char *)malloc((substr_len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output_index = 0;
	while (output_index < len)
	{
		output[output_index] = s[start];
		output_index++;
		start++;
	}
	output[output_index] = '\0';
	return (output);
}
