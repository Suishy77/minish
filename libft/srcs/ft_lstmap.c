/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:32 by aminko            #+#    #+#             */
/*   Updated: 2023/10/27 18:52:41 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*head;
	t_list	*curr;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	head = ft_lstnew((*f)(lst->content));
	if (!head)
		return (NULL);
	curr = head;
	tmp = lst -> next;
	while (tmp)
	{
		curr -> next = ft_lstnew((*f)(tmp->content));
		if (!curr -> next)
			return (ft_lstclear(&head, del), NULL);
		tmp = tmp -> next;
		curr = curr -> next;
	}
	return (head);
}
