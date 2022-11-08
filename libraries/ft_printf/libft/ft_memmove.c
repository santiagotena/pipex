/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 02:23:27 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/06 23:57:00 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_overlap(size_t len, char *ptr_dst, char *ptr_src)
{
	size_t	counter;
	int		rev_index;

	counter = 0;
	rev_index = len - 1;
	while (counter < len)
	{
		ptr_dst[rev_index] = ptr_src[rev_index];
		counter++;
		rev_index--;
	}
}

/**
 * @brief Copies len bytes from string src to string dst.  The two strings 
 * may overlap; the copy is always done in a non-destructive manner.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* 
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	counter;
	char	*ptr_dst;
	char	*ptr_src;

	counter = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		while (counter < len)
		{
			ptr_dst[counter] = ptr_src[counter];
			counter++;
		}
		return (dst);
	}
	ft_overlap(len, ptr_dst, ptr_src);
	return (dst);
}
