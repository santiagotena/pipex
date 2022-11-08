/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:08:45 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/27 14:36:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new node. The member 
 * variable ’content’ is initialized with the value of the parameter 
 * ’content’. The variable ’next’ is initialized to NULL.
 * 
 * Returns the new node.
 * @param content The content to create the node with.
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*output;

	output = malloc(sizeof(t_list));
	if (!output)
		return (NULL);
	output->content = content;
	output->next = NULL;
	return (output);
}
