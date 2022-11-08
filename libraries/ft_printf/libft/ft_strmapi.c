/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:25:16 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/07 00:16:56 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function ’f’ to each character of the string ’s’, 
 * and passing its index as first argument to create a new string 
 * (with malloc(3)) resulting from successive applications of ’f’.
 * 
 * Returns the string created from the successive applications of ’f’. 
 * Returns NULL if the allocation fails.
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		index;

	if (!s)
		return (NULL);
	output = (char *) malloc ((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!output)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		output[index] = f(index, s[index]);
		index++;
	}
	output[index] = '\0';
	return (output);
}
