/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:05:45 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 18:15:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an upper-case letter to the corresponding lower-case 
 * letter. The argument must be representable as an unsigned char or the 
 * value of EOF.
 * 
 * If the argument is an upper-case letter, the function returns 
 * the corresponding lower-case letter if there is one; otherwise, the 
 * argument is returned unchanged.
 * 
 * @param c 
 * @return int 
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}
