/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:43:52 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/10 19:24:40 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_exit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	exec_error(char *full_cmd)
{
	write(2, "pipex: command not found: ", 26);
	write(2, full_cmd, ft_strlen(full_cmd));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
