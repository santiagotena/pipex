/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:47:42 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/10 19:27:33 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	get_paths(t_path *vars, char **envp)
{
	while (envp[vars->i])
	{
		vars->envp_path = ft_strnstr(envp[vars->i], "PATH=", 5);
		if (vars->envp_path)
		{
			vars->envp_path = ft_substr(vars->envp_path, 5, 200);
			if (!envp)
				error_exit("PATH not found");
			break ;
		}
		vars->i++;
	}
	vars->paths = ft_split(vars->envp_path, ':');
	if (!vars->paths)
		error_exit("env_path parsing failed");
	free(vars->envp_path);
}

void	correct_path(t_path *vars)
{
	vars->i = 0;
	while (vars->paths[vars->i])
	{
		vars->tmp = vars->paths[vars->i];
		vars->paths[vars->i] = ft_strjoin(vars->tmp, "/");
		free(vars->tmp);
		vars->i++;
	}
}

void	free_edge(t_path *vars)
{
	vars->temp = vars->paths;
	while (*vars->paths)
	{
		free(*vars->paths);
		vars->paths++;
	}
	free(vars->temp);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	t_path	vars;

	vars.i = 0;
	get_paths(&vars, envp);
	correct_path(&vars);
	vars.i = 0;
	while (vars.paths[vars.i])
	{
		vars.cmd_path = ft_strjoin(vars.paths[vars.i], cmd);
		if (access(vars.cmd_path, F_OK | X_OK) == 0)
			return (vars.cmd_path);
		free(vars.cmd_path);
		vars.i++;
	}
	free_edge(&vars);
	exec_error(cmd);
	return (NULL);
}

void	do_cmd(char *full_cmd, char **envp)
{
	char	*cmd_path;
	char	*options[3];
	char	**split_cmd;

	split_cmd = ft_split(full_cmd, ' ');
	if (!split_cmd)
		error_exit("Invalid command");
	options[0] = split_cmd[0];
	options[1] = split_cmd[1];
	options[2] = NULL;
	cmd_path = get_cmd_path(options[0], envp);
	if (!cmd_path)
		error_exit("The command path could not be determined");
	execve(cmd_path, options, envp);
	return ;
}
