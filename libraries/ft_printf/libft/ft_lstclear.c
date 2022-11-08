/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:14:46 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/28 11:54:15 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and every successor of that node, 
 * using the function ’del’ and free(3). 
 * Finally, the pointer to the list must be set to NULL.
 * 
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of 
 * the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temporary;
	t_list	*prev;

	temporary = *lst;
	prev = NULL;
	while (temporary != NULL)
	{		
		del(temporary->content);
		prev = temporary;
		temporary = temporary->next;
		free(prev);
	}
	*lst = NULL;
}
