/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:51:29 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/07 00:22:00 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function ’f’ on each character of the string passed 
 * as argument, passing its index as first argument.  Each character is passed 
 * by address to ’f’ to be modified if necessary.
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		index;

	index = 0;
	if (!s)
		return ;
	while (s[index] != '\0')
	{
		f(index, &s[index]);
		index++;
	}
}
