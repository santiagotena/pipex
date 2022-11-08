/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:50:46 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 18:27:27 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for a decimal digit character. The value of the argument 
 * must be representable as an unsigned char or the value of EOF. Returns 
 * zero if the character tests false and returns non-zero if the 
 * character tests true.
 * 
 * @param c 
 * @return int 
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
