/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:28:54 by aminko            #+#    #+#             */
/*   Updated: 2022/11/18 15:13:27 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*next;

	if (!lst || !(*del))
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr -> next;
		ft_lstdelone(curr, (*del));
		curr = next;
	}
	*lst = 0;
}
