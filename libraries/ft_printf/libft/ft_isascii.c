/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:04:42 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 18:27:29 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for an ASCII character, which is any character between 0 
 * and octal 0177 inclusive.
 * 
 * @param c 
 * @return int 
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
