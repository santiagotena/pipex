/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:51:11 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/30 13:01:09 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char **argv, char **envp) 
{	
	if (argc < 5)
		return (1); // Not enough arguments
	
	pipes_setup(argc, argv, envp);
	return (0);
}