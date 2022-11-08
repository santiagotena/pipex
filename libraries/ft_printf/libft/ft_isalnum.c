/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:50:30 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 17:38:36 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for any character for which isalpha(3) or isdigit(3) is true. 
 * The value of the argument must be representable as an unsigned char or 
 * the value of EOF. Returns zero if the character tests false and returns 
 * non-zero if the character tests true.
 * 
 * @param c 
 * @return int 
 */
int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
