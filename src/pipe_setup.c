/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:24:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/30 00:30:10 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	pipe_setup(int argc, char **argv, char **envp)
{
	int prev[2];
	int	next[2];
	int	pid;
	int	file_in;
	int file_out;
	int	i;
	
	file_in = 0;
	file_out = 0;
	i = 1;
	// Start
	if (pipe(next) == -1)
		return (2); // pipe error
	pid = fork();
	if (pid < 0)
		return (3); // fork error
	if (pid == 0)
	{
		file_in = open(argv[i], O_RDONLY, 0666);
		dup2(file_in, STDIN_FILENO);
		dup2(next[1], STDOUT_FILENO);
		close(next[1]);
		close(next[0]);
		close(file_in);
		do_cmd(argv[i + 1], envp);
	}
	i = i + 2;
	waitpid(pid, NULL, 0);

	// Middle
	if (argc > 5)
	{
		// while (i < (argc - 2))
		// {
		// 	if (pipe(fd) == -1)
		// 		return (2); // pipe error
		// 	pid = fork();
		// 	if (pid < 0)
		// 		return (3); // fork error
		// 	if (pid == 0)
		// 	{
		// 		dup2(fd[0], STDIN_FILENO);
		// 		dup2(fd[1], STDOUT_FILENO);
		// 		close(fd[0]);
		// 		close(fd[1]);
		// 		do_cmd(argv[i], envp);
		// 	}
		// 	waitpid(pid, NULL, 0);
		// 	i++;
		// }
		return (0);
	}

	// Last
	prev[0] = next[0];
	prev[1] = next[1];
	pid = fork();
	if (pid < 0)
		return (3); // fork error
	if (pid == 0)
	{
		file_out = open(argv[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
		dup2(prev[0], STDIN_FILENO);
		dup2(file_out, STDOUT_FILENO);
		close(prev[0]);
		close(prev[1]);
		close(next[0]);
		close(next[1]);
		close(file_out);
		do_cmd(argv[i], envp);
	}
	close(prev[0]);
	close(prev[1]);
	close(next[0]);
	close(next[1]);
	
	waitpid(pid, NULL, 0);
	return (0);
}