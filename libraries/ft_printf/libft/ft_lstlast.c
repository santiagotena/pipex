/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:18:22 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/26 19:43:31 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last node of the list.
 * 
 * @param lst The beginning of the list.
 * @return t_list* 
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temporary;

	temporary = lst;
	while (temporary != NULL)
	{
		if (temporary->next == NULL)
			return (temporary);
		temporary = temporary->next;
	}
	return (NULL);
}
