/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:52:04 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/29 19:00:07 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the last occurrence of c (converted to a char) in the 
 * string pointed to by s. The terminating null character is considered to 
 * be part of the string; therefore if c is `\0', the functions locate the 
 * terminating `\0'.
 * 
 * Returns a pointer to the located character, or NULL if the character 
 * does not appear in the string.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*ptr;
	void	*output;

	ptr = (char *)s;
	index = 0;
	output = NULL;
	while (ptr[index] != '\0')
	{
		if (ptr[index] == (unsigned char) c)
		{
			output = &ptr[index];
		}
		index++;
	}
	if (c == '\0' && ptr[index] == '\0')
		return (&ptr[index]);
	return (output);
}
