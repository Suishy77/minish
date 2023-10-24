/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:04:38 by aminko            #+#    #+#             */
/*   Updated: 2023/10/07 21:16:40 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_elem(void **elem)
{
	if ((*elem) == NULL)
		return ;
	free((*elem));
	(*elem) = NULL;
}

char	**ft_free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return (NULL);
	i = -1;
	while (tab[++i])
		ft_free_elem((void **)&tab[i]);
	free(tab);
	return (NULL);
}
