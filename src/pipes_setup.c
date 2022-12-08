/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:24:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/09 00:04:49 by stena-he         ###   ########.fr       */
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

void	first_pipe(t_data **inputs)
{
	printf("Enter First pipe \n");
	int	pid;
	int	file_in;
	int fd[MAX_FD][2];
	
	file_in = 0;
	if (pipe(fd[(*inputs)->j]) < 0)
			return; // pipe error
	pid = fork();
	if (pid < 0)
		return; // fork error
	if (pid == 0)
	{
		file_in = open((*inputs)->argv[(*inputs)->i], O_RDONLY, 0666);
		dup2(file_in, STDIN_FILENO);
		dup2(fd[(*inputs)->j][1], STDOUT_FILENO);
		close(file_in);

		close_fds((*inputs)->argc, fd);

		do_cmd((*inputs)->argv[(*inputs)->i + 1], (*inputs)->envp);
	}
	waitpid(pid, NULL, 0);
	(*inputs)->i = (*inputs)->i + 2;
	(*inputs)->j++;
	printf("Exit First pipe \n");
}

void	mid_pipes(t_data **inputs)
{
	printf("Enter Middle pipe \n");
	int	pid;
	int fd[MAX_FD][2];
	
	while ((*inputs)->i < ((*inputs)->argc - 2))
	{
		if (pipe(fd[(*inputs)->j]) < 0)
			return ; // pipe error
		pid = fork();
		if (pid < 0)
			return ; // fork error
		if (pid == 0)
		{
			dup2(fd[(*inputs)->j - 1][0], STDIN_FILENO);
			dup2(fd[(*inputs)->j][1], STDOUT_FILENO);
			
			close_fds((*inputs)->argc, fd);
			
			do_cmd((*inputs)->argv[(*inputs)->i], (*inputs)->envp);
		}
		// waitpid(pid, NULL, 0);
		(*inputs)->i++;
		(*inputs)->j++;
	}
	printf("Exit Middle pipe \n");
}

void	last_pipe(t_data **inputs)
{
	printf("Enter Last pipe \n");
	int	pid;
	int	file_out;
	int fd[MAX_FD][2];
	
	file_out = 0;
	pid = fork();
	if (pid < 0)
		return ; // fork error
	if (pid == 0)
	{
		// printf("Checkpoint 2 Last pipe \n");
		file_out = open((*inputs)->argv[(*inputs)->i + 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
		// printf("Checkpoint 2.5 Last pipe \n");
		dup2(fd[(*inputs)->j - 1][0], STDIN_FILENO);
		// printf("Checkpoint 3 Last pipe \n");
		dup2(file_out, STDOUT_FILENO);
		// fprintf(stderr, "Checkpoint 4 Last pipe \n");
		close(file_out);
		// fprintf(stderr, "Checkpoint 5 Last pipe \n");
		close_fds((*inputs)->argc, fd);
		// fprintf(stderr, "Checkpoint 6 Last pipe \n");

	
		do_cmd((*inputs)->argv[(*inputs)->i], (*inputs)->envp);
	}
	waitpid(pid, NULL, WNOHANG);
	printf("Exit Last pipe \n");
}

int	pipes_setup(int argc, char **argv, char **envp)
{
	t_data	*inputs;
		
	inputs = assign_inputs(argc, argv, envp);
	first_pipe(&inputs);
	if (inputs->argc > 5)
		mid_pipes(&inputs);
	last_pipe(&inputs);
	return (0);
}