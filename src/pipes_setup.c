/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:24:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/08 20:26:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_data	*assign_inputs(int argc, char **argv, char **envp)
{
	t_data	*node;
	
	node = malloc(sizeof(t_data));
	if (!node)
		return (NULL);
	node->argc = argc;
	node->argv = argv;
	node->envp = envp;
	node->i = 1;
	node->j = 0;
	node->next = NULL;
	return (node);	
}

void	close_fds(int argc, int fd[MAX_FD][2])
{
	int	k;
	
	k = 0;
	while (k < (argc - 4))
	{
		close(fd[k][0]);
		close(fd[k][1]);
		k++;
	}
}

void	first_pipe(int argc, char **argv, char **envp, int fd[MAX_FD][2], int *i, int *j)
{
	int	pid;
	int	file_in;
	
	file_in = 0;
	if (pipe(fd[*j]) < 0)
			return; // pipe error
	pid = fork();
	if (pid < 0)
		return; // fork error
	if (pid == 0)
	{
		file_in = open(argv[*i], O_RDONLY, 0666);
		dup2(file_in, STDIN_FILENO);
		dup2(fd[*j][1], STDOUT_FILENO);
		close(file_in);

		close_fds(argc, fd);

		do_cmd(argv[*i + 1], envp);
	}
	waitpid(pid, NULL, 0);
}

int	pipes_setup(int argc, char **argv, char **envp)
{
	int fd[MAX_FD][2]; //keep
	int	pid; //remove
	int file_out; //remove
	int	i; //keep
	int j; //keep
	t_data	*inputs;
	
	file_out = 0; //remove
	i = 1; //keep
	j = 0; //keep
	
	inputs = assign_inputs(argc, argv, envp);
	first_pipe(argc, argv, envp, fd, &i, &j);
	i = i + 2;
	j++;
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
				
				close_fds(argc, fd);
				
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
		
		close_fds(argc, fd);
	
		do_cmd(argv[i], envp);
	}
	
	close_fds(argc, fd);
	
	waitpid(pid, NULL, 0);
	return (0);
}