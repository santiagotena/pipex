/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:58:07 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 18:16:11 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lower-case letter to the corresponding upper-case 
 * letter. The argument must be representable as an unsigned char or the 
 * value of EOF.
 * 
 * If the argument is a lower-case letter, the function returns the 
 * corresponding upper-case letter if there is one; otherwise, the 
 * argument is returned unchanged.
 * 
 * @param c 
 * @return int 
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}
