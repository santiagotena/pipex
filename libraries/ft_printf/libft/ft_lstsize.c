/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:47:44 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/26 19:12:53 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of nodes in a list. Returns the lenght of the list.
 * 
 * @param lst The beginning of the list.
 * @return int 
 */
int	ft_lstsize(t_list *lst)
{
	t_list	*temporary;
	int		counter;

	temporary = lst;
	counter = 0;
	while (temporary != NULL)
	{
		temporary = temporary->next;
		counter++;
	}
	return (counter);
}
