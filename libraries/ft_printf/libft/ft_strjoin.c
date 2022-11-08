/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:27:37 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/09 21:52:00 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is 
 * the result of the concatenation of ’s1’ and ’s2’.
 * 
 * Returns the new string or NULL if the allocation fails.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	output_index;
	size_t	index;

	if (!s1 || !s2)
		return (NULL);
	output = (char *)malloc(ft_strlen(s1) \
			+ ft_strlen(s2) + 1 * sizeof(char));
	if (!output)
		return (NULL);
	output_index = 0;
	index = 0;
	while (output_index < ft_strlen(s1))
	{
		output[output_index++] = s1[index++];
	}
	index = 0;
	while (output_index < ft_strlen(s1) + ft_strlen(s2))
	{
		output[output_index++] = s2[index++];
	}
	output[output_index] = '\0';
	return (output);
}
