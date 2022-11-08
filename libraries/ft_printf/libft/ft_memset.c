/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:41:23 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 17:50:20 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes len bytes of value c (converted to an unsigned char) to 
 * the string b. Returns its first argument.
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*ptr;

	ptr = (char *)b;
	counter = 0;
	while (counter < len)
	{
		ptr[counter] = c;
		counter++;
	}
	return (b);
}
