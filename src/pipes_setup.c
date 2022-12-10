/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:24:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/10 14:45:59 by stena-he         ###   ########.fr       */
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
	return (node);
}

void	first_pipe(t_data **inputs, int fd[MAX_FD][2])
{
	int	pid;
	int	file_in;

	file_in = 0;
	if (pipe(fd[(*inputs)->j]) < 0)
		error_exit("Pipe error");
	pid = fork();
	if (pid < 0)
		error_exit("Fork error");
	if (pid == 0)
	{
		file_in = open((*inputs)->argv[(*inputs)->i], O_RDONLY, 0666);
		if (file_in < 0)
			error_exit((*inputs)->argv[(*inputs)->i]);
		dup2(file_in, STDIN_FILENO);
		dup2(fd[(*inputs)->j][1], STDOUT_FILENO);
		close(file_in);
		close_fds((*inputs)->argc, fd);
		do_cmd((*inputs)->argv[(*inputs)->i + 1], (*inputs)->envp);
	}
	waitpid(pid, NULL, 0);
	(*inputs)->i = (*inputs)->i + 2;
	(*inputs)->j++;
}

void	mid_pipes(t_data **inputs, int fd[MAX_FD][2])
{
	int	pid;

	while ((*inputs)->i < ((*inputs)->argc - 2))
	{
		if (pipe(fd[(*inputs)->j]) < 0)
			error_exit("Pipe error");
		pid = fork();
		if (pid < 0)
			error_exit("Fork error");
		if (pid == 0)
		{
			dup2(fd[(*inputs)->j - 1][0], STDIN_FILENO);
			dup2(fd[(*inputs)->j][1], STDOUT_FILENO);
			close_fds((*inputs)->argc, fd);
			do_cmd((*inputs)->argv[(*inputs)->i], (*inputs)->envp);
		}
		(*inputs)->i++;
		(*inputs)->j++;
	}
}

void	last_pipe(t_data **inputs, int fd[MAX_FD][2])
{
	int	pid;
	int	file_out;

	file_out = 0;
	pid = fork();
	if (pid < 0)
		error_exit("Fork error");
	if (pid == 0)
	{
		file_out = open((*inputs)->argv[(*inputs)->i + 1], \
			O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (file_out < 0)
			error_exit((*inputs)->argv[(*inputs)->i + 1]);
		dup2(fd[(*inputs)->j - 1][0], STDIN_FILENO);
		dup2(file_out, STDOUT_FILENO);
		close(file_out);
		close_fds((*inputs)->argc, fd);
		do_cmd((*inputs)->argv[(*inputs)->i], (*inputs)->envp);
	}
	waitpid(pid, NULL, WNOHANG);
}

int	pipes_setup(int argc, char **argv, char **envp)
{
	t_data	*inputs;
	int		fd[MAX_FD][2];

	inputs = assign_inputs(argc, argv, envp);
	first_pipe(&inputs, fd);
	if (inputs->argc > 5)
		mid_pipes(&inputs, fd);
	last_pipe(&inputs, fd);
	return (0);
}
