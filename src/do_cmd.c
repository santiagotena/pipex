/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:47:42 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/09 01:24:29 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	*envp_path;
	char	**paths;
	char	*tmp;
	char	*cmd_path;
	char	**temp;

	i = 0;
	while (envp[i])
	{
		envp_path = ft_strnstr(envp[i], "PATH=", 5);
		if (envp_path)
		{
			envp_path = ft_substr(envp_path, 5, 200);
			if (!envp)
				return (NULL); //Malloc Error
			break;
		}
		i++;
	}

	paths = ft_split(envp_path, ':');
	if (!paths)
		return (NULL); //Malloc Error
	free(envp_path);
	
	i = 0;
	while(paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	
	temp = paths;
	while (*paths)
	{
		free(*paths);
		paths++;
	}
	free(temp);
	return (NULL); //No path found
}

int	do_cmd(char *full_cmd, char **envp)
{
	char	*cmd_path;
	char	*options[3];
	char	**split_cmd;
	
	split_cmd = ft_split(full_cmd, ' ');
	if (!split_cmd)
		return (9); //Malloc Error
	options[0] = split_cmd[0];
	options[1] = split_cmd[1];
	options[2] = NULL;
	
	cmd_path = get_cmd_path(options[0], envp);
	if (!cmd_path)
	{
		perror(cmd_path);
		return(-1);
	}
	execve(cmd_path, options, envp);
	return (69); // Execution failed RIP
}
