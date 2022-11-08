/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:54:01 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/28 12:16:37 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.
 * 
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on 
 * the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temporary;

	temporary = lst;
	while (temporary != NULL)
	{
		f(temporary->content);
		temporary = temporary->next;
	}
}
