/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:32 by aminko            #+#    #+#             */
/*   Updated: 2022/11/15 17:20:38 by aminko           ###   ########.fr       */
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

/* void *return_hello(void *yo)
{
	printf("in function: %s\n", (char *)yo);
	return "Hello";
}

void do_nothing(void *)
{
}

int main(void)
{
	t_list *lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("1"));
	ft_lstadd_back(&lst, ft_lstnew("2"));
	ft_lstadd_back(&lst, ft_lstnew("3"));
	ft_lstadd_back(&lst, ft_lstnew("4"));

{

	t_list *t = lst;
	while (t)
	{
		printf("%s\n", (char *)t->content);
		t = t->next;
	}
}

	printf("\n");


	t_list *lst2 = ft_lstmap(lst, return_hello, do_nothing);

	{

	t_list *t = lst2;
	while (t)
	{
		printf("%s\n", (char *)t->content);
		t = t->next;
	}

	ft_lstclear(&lst, do_nothing);
	ft_lstclear(&lst2, do_nothing);
}


}
 */
