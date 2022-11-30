/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:24:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/30 02:11:39 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	pipe_setup(int argc, char **argv, char **envp)
{
	int fd[1024][2];
	int	pid;
	int	file_in;
	int file_out;
	int	i;
	int j;
	int	k;
	
	file_in = 0;
	file_out = 0;
	
	// Start
	i = 1;
	j = 0;
	if (pipe(fd[j]) < 0)
			return (2); // pipe error
	pid = fork();
	if (pid < 0)
		return (3); // fork error
	if (pid == 0)
	{
		file_in = open(argv[i], O_RDONLY, 0666);
		dup2(file_in, STDIN_FILENO);
		dup2(fd[j][1], STDOUT_FILENO);
		close(file_in);

		k = 0;
		while (k < (argc - 4))
		{
			close(fd[k][0]);
			close(fd[k][1]);
			k++;
		}

		do_cmd(argv[i + 1], envp);
	}
	i = i + 2;
	j++;
	waitpid(pid, NULL, 0);

	// Middle
	if (argc > 5)
	{
		while (i < (argc - 2))
		{
			if (pipe(fd[j]) < 0)
				return (2); // pipe error
			pid = fork();
			if (pid < 0)
				return (3); // fork error
			if (pid == 0)
			{
				dup2(fd[j - 1][0], STDIN_FILENO);
				dup2(fd[j][1], STDOUT_FILENO);
				
				k = 0;
				while (k < (argc - 4))
				{
					close(fd[k][0]);
					close(fd[k][1]);
					k++;
				}
				
				do_cmd(argv[i], envp);
			}
			// waitpid(pid, NULL, 0);
			i++;
			j++;
		}
	}

	// Last
	pid = fork();
	if (pid < 0)
		return (3); // fork error
	if (pid == 0)
	{
		file_out = open(argv[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
		dup2(fd[j - 1][0], STDIN_FILENO);
		dup2(file_out, STDOUT_FILENO);
		close(file_out);
		
		k = 0;
		while (k < (argc - 4))
		{
			close(fd[k][0]);
			close(fd[k][1]);
			k++;
		}
	
		do_cmd(argv[i], envp);
	}
	
	k = 0;
	while (k < (argc - 4))
	{
		close(fd[k][0]);
		close(fd[k][1]);
		k++;
	}
	waitpid(pid, NULL, 0);
	return (0);
}