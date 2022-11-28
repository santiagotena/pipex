/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:24:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/28 22:32:27 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	pipe_setup(char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	file_in;
	int file_out;
	
	file_in = 0;
	file_out = 0;
	if (pipe(fd) == -1)
		return (2); // pipe error
	
	pid1 = fork();
	if (pid1 < 0)
		return (3); // fork error

	if (pid1 == 0)
	{
		file_in = open(argv[1], O_RDONLY, 0666);
		dup2(file_in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		do_cmd(argv[2], envp);
	}

	pid2 = fork();
	if (pid2 < 0)
		return (3); // fork error
	
	if (pid2 == 0)
	{
		file_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
		dup2(fd[0], STDIN_FILENO);
		dup2(file_out, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		do_cmd(argv[3], envp);
	}
	close(fd[0]);
	close(fd[1]);
	
	close(file_in);
	close(file_out);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}