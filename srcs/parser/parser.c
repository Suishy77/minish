/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:54:43 by aminko            #+#    #+#             */
/*   Updated: 2023/10/27 23:20:53 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	detect_hd(char **lexer, t_cmdtab *tab)
{
	int			i;
	int			count;
	char		**spl;
	t_cmdtab	*tmp;

	i = 0;
	count = 0;
	spl = NULL;
	tmp = tab;
	while (lexer && lexer[i] && tmp)
	{
		spl = split(lexer[i]);
		if (!detect_hd_loop(spl, tmp, &count))
		{
			ft_free_elem((void **)&spl);
			return (0);
		}
		ft_free_elem((void **)&spl);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	throw_error(t_file *f)
{
	if (f && f->fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		if (access(f->file, F_OK | X_OK) == -1)
			perror(f->file);
		g_status = 1;
	}
}

void	fill_files(t_cmdtab **tab, char **lexer)
{
	int			i;
	t_cmdtab	*temp;
	char		**spl;

	temp = *tab;
	i = 0;
	spl = NULL;
	if (detect_hd(lexer, temp))
	{
		while (lexer && lexer[i] && temp)
		{
			spl = split(lexer[i]);
			if (g_status != 130)
				init_files(temp, spl);
			ft_free_elem((void **)&spl);
			i++;
			temp = temp->next;
		}
	}
}

t_cmdtab	*lstlast(t_cmdtab *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_cmdtab	*parser(char **lexer)
{
	int			i;
	char		**spl;
	t_cmdtab	*tab;
	t_cmdtab	*tmp;

	i = 0;
	tab = NULL;
	tmp = NULL;
	spl = NULL;
	g_status = 0;
	while (lexer && lexer[i])
	{
		spl = split(lexer[i]);
		if (!syntax_err_redir(spl))
			return (ft_free_elem((void **)&spl), NULL);
		tmp = lstnew_cmd(spl, i);
		lst_addback_cmd(&tab, tmp);
		ft_free_elem((void **)&spl);
		i++;
	}
	if (lexer && tab)
		fill_files(&tab, lexer);
	if (g_status == 130)
		return (close_final_fd(lstlast(tab)), NULL);
	return (tab);
}
