/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:32:53 by aminko            #+#    #+#             */
/*   Updated: 2023/10/29 00:16:37 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_out_in(t_file *in, t_file *out)
{
	t_file	*tmp;

	while (out)
	{
		// printf("out\n");
		tmp = out;
		out = out->next;
		ft_free_elem((void **)&(tmp->file));
		ft_free_elem((void **)&(tmp));
	}
	while (in)
	{
		tmp = in;
		in = in->next;
		ft_free_elem((void **)&(tmp->file));
		ft_free_elem((void **)&(tmp));
	}
}

void	free_all(t_cmdtab *tab)
{
	while (tab)
	{
		ft_free_tab(tab->opt);
		//ft_free_elem((void **)&(tab->cmd)); // $PWD marche pas avec
		free_out_in(tab->in, tab->out);
		tab = tab->next;
	}
	free_gc();
}
