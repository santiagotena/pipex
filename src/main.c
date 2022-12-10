/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:51:11 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/10 00:58:36 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char **argv, char **envp) 
{	
	if (argc < 5)
		error_exit("Not enough arguments");
	pipes_setup(argc, argv, envp);
	return (0);
}