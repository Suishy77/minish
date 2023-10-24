/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:54:48 by aminko            #+#    #+#             */
/*   Updated: 2023/10/25 00:40:09 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_garbage **singleton(void)
{
	static t_garbage *collect;

	return (&collect);
}

void *collect(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	add_front(singleton(), ptr, NBR);
	return (ptr);
}

int lstsize_garb(t_garbage *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void add_front(t_garbage **lst, void *ptr, enum PTR_TYPE type)
{
	t_garbage *collect;

	collect = malloc(sizeof(t_garbage));
	if (!collect)
		return;
	collect->type = type;
	collect->ptr = ptr;
	collect->next = *lst;
	*lst = collect;
	return;
}

void free_gc(void)
{
	t_garbage *collect;
	t_garbage *next;

	collect = (*singleton());

	while (collect)
	{
		next = collect->next;
		if (collect->type == DATA)
		{
			ft_free_tab(((t_data *)collect->ptr)->env);
			free((t_data *)(collect->ptr));
		}
		else if (collect->type == NBR || collect->type == CHAR_PTR)
			free(collect->ptr);
		else if (collect->type == D_CHAR_PTR)
			ft_free_tab((char **)collect->ptr);
		collect->ptr = NULL;
		free(collect);
		collect = next;
	}
}
