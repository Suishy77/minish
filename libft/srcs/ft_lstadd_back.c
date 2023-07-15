/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:32:23 by aminko            #+#    #+#             */
/*   Updated: 2022/11/18 15:52:32 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *lst;
	if (!tmp)
		*lst = new;
	else
	{
		last = ft_lstlast(tmp);
		last -> next = new;
	}
}

/* int main ()
{
	t_list* node;
	ft_lstadd_back(&node);
} */
