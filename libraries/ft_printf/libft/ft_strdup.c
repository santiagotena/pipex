/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:05:02 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/24 15:22:13 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates sufficient memory for a copy of the string s1, does the 
 * copy, and returns a pointer to it.  The pointer may subsequently be used 
 * as an argument to the function free(3).
 * 
 * @param s1 
 * @return char* 
 */
char	*ft_strdup(const char *s1)
{
	size_t	count;
	char	*output;
	size_t	index;

	index = 0;
	count = 0;
	while (s1[index] != '\0')
	{
		count++;
		index++;
	}
	output = (char *)malloc((count + 1) * sizeof(char));
	if (!output)
		return (NULL);
	index = 0;
	while (index < count)
	{
		output[index] = s1[index];
		index++;
	}
	output[index] = '\0';
	return (output);
}
