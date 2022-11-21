/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:51:11 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/21 23:16:52 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char **argv, char **envp) 
{	
	char	*cmd_path;
	char	*options[3] = {argv[1], argv[2], NULL};
	char	*cmd = argv[1];
	
	if (argc < 2)
		return (1); // Not enough arguments
	cmd_path = get_cmd_path(cmd, envp);
	if (!cmd_path)
	{
		perror(cmd_path);
		return(-1);
	}
	execve(cmd_path, options, envp);
	free(cmd_path);
	return (0);
}