/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:56:32 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/09 19:07:43 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the 
 * content of each node.  Creates a new list resulting of the successive 
 * applications of the function ’f’.  The ’del’ function is used to delete 
 * the content of a node if needed.
 * 
 * Returns the new list or NULL if the allocation fails.
 * 
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a 
 * node if needed.
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_head;

	new_head = NULL;
	if (!lst)
		return (NULL);
	new_head = ft_lstnew(f(lst->content));
	if (!new_head)
		del(new_head->content);
	if (!new_head)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
			del(new_node->content);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}
