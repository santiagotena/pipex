/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:18:27 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/07 00:16:19 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rowcounter(char const *s, char c, size_t length)
{
	size_t	index;
	int		rows;

	index = 0;
	rows = 0;
	while (index < length)
	{
		if (s[index] != c && index == 0)
			rows++;
		if (index != 0)
		{
			if (s[index] != c && s[index - 1] == c)
			rows++;
		}
		index++;
	}
	return (rows);
}

static void	ft_arrfill(char const *s, char **array, char c, size_t length)
{
	size_t	index;
	int		rows;
	int		end_index;

	index = 0;
	rows = 0;
	while (index < length)
	{
		if (s[index] != c)
		{
			end_index = index;
			while (s[end_index] != c && s[end_index] != '\0')
				end_index++;
			array[rows] = ft_substr(s, index, (end_index - index));
			index = index + (end_index - index);
			rows++;
		}
		index++;
	}
}

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings
 * obtained by splitting ’s’ using the character ’c’ as a delimiter. The
 * array must end with a NULL pointer.
 *
 * The array of new strings resulting from the split. NULL if the
 * allocation fails.
 *
 * @param s
 * @param c
 * @return char**
 */
char	**ft_split(char const *s, char c)
{
	char	**array;
	int		rows;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	rows = ft_rowcounter(s, c, length);
	array = (char **) malloc((rows + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ft_arrfill(s, array, c, length);
	array[rows] = 0;
	return (array);
}
