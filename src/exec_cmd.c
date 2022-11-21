/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:47:42 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/21 22:47:43 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_cmd_path(char *cmd, char **envp) 
{
	int		i;
	char	*envp_PATH;
	char	**paths;
	char	*tmp;
	char	*cmd_path;
	char	**temp;

	i = 0;
	while (envp[i])
	{
		envp_PATH = ft_strnstr(envp[i], "PATH=", 5);
		if (envp_PATH)
		{
			envp_PATH = ft_substr(envp_PATH, 5, 200); //Might need less
			if (!envp)
				return (NULL); //Malloc Error
			break;
		}
		i++;
	}

	paths = ft_split(envp_PATH, ':');
	if (!paths)
		return (NULL); //Malloc Error
	free(envp_PATH);
	
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