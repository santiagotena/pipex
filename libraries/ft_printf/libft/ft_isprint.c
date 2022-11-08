/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:49:47 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 18:27:07 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for any printing character, including space
 * (` ').  The value of the argument must be representable as an 
 * unsigned char or the value of EOF. Returns zero if the character tests 
 * false and returns non-zero if the character tests true.
 * 
 * @param c 
 * @return int 
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
