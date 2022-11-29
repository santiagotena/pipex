/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:51:45 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/29 20:17:30 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
//Stacks 
// typedef struct s_stack
// {
// 	int				value;
// 	int				index;
// 	int				pos;
// 	int				target_pos;
// 	int				cost_a;
// 	int				cost_b;
// 	struct s_stack	*next;
// }					t_stack;

/* Functions */

// Pipe Setup //
int		pipe_setup(int argc, char **argv, char **envp);

// Execute commands //
int		do_cmd(char *full_cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);

// Title //
//Subtitle


#endif
