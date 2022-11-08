/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:43:17 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/22 09:09:12 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(int digit, int fd)
{
	int		out;

	out = digit + '0';
	write(fd, &out, 1);
}

void	recursion(int n, int fd)
{
	if (n > 9)
	{
		n = n / 10;
		recursion(n, fd);
		ft_putchar(n % 10, fd);
	}
}

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * 
 * @param n 
 * @param fd 
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	recursion(n, fd);
	ft_putchar(n % 10, fd);
}
