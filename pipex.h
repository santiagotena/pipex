/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:51:45 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/10 19:26:53 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define MAX_FD 1024

/* Libraries */
//Std libraries
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

//Custom libraries
# include "libraries/ft_printf/libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"

/* Structs */
//Input data 
typedef struct s_data
{
	int				argc;
	char			**argv;
	char			**envp;
	int				i;
	int				j;
}					t_data;

typedef struct s_path 
{
	int		i;
	char	*envp_path;
	char	**paths;
	char	*tmp;
	char	*cmd_path;
	char	**temp;
}					t_path;

/* Functions */
// Pipe setup //
int		pipes_setup(int argc, char **argv, char **envp);

// Execute commands //
void	do_cmd(char *full_cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);

// Error management //
void	error_exit(char *message);
void	exec_error(char *full_cmd);

// Utils //
void	close_fds(int argc, int fd[MAX_FD][2]);

#endif
