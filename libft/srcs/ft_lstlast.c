/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:25:01 by aminko            #+#    #+#             */
/*   Updated: 2022/11/18 15:58:30 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp -> next)
		tmp = tmp->next;
	return (tmp);
}
/*
int main ()
{
	t_list* node1;
	t_list *node2;
	t_list *node3;

	int a = 4;
	int b =20;
	int c = 3;
	void *p = &a;
	void *x = &b;
	void *y = &c;
	node1 = ft_lstnew(p);
	node2 = ft_lstnew(x);
	node3 = ft_lstnew(y);
	node1->next = node2;
	node2->next = node3;

	t_list* tmp = node1;
	while(tmp != NULL)
	{
		printf("content value is : %d\n", *(int*)tmp->content);
		tmp = tmp -> next;
	}


}
 */
