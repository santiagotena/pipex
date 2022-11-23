/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:51:11 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/24 00:15:51 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char **argv, char **envp) 
{	
	int	fd[2];
	int	pid1;
	int	pid2;
	
	if (argc < 2)
		return (1); // Not enough arguments
	
	if (pipe(fd) == -1)
		return (2); // Pipe error
	
	pid1 = fork();
	if (pid1 < 0)
		return (3); // fork error

	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		do_cmd(argv[1], argv[2], envp);
	}

	pid2 = fork();
	if (pid2 < 0)
		return (3); // fork error
	
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		do_cmd(argv[3], argv[4], envp);
	}
	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	
	return (0);
}