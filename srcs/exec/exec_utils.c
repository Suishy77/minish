/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:52:43 by aminko            #+#    #+#             */
/*   Updated: 2023/10/26 02:28:14 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data *init_data_struct(t_cmdtab *tab, char ***env)
{
	t_data *data;
	int i;

	i = 0;
	data = calloc(sizeof(t_data), 1);
	if (!data)
		return (NULL);
	data->p_count = lstsize(tab);
	data->pid = collect(sizeof(int) * data->p_count);
	if (!data->pid)
		return (NULL);
	data->fd = collect(sizeof(int *) * data->p_count);
	if (!data->fd)
		return (NULL);
	while (i < data->p_count)
	{
		data->fd[i] = collect(sizeof(int) * 2);
		if (!data->fd[i])
			return (NULL);
		i++;
	}
	if (env)
	{
		printf("env: %p\n", data->env);
		data->env = ft_strdup_tab(*env);
		*env = ft_free_tab(*env);
	}
	return (data);
}

void close_all_fds(t_cmdtab *tab)
{
	t_file *tab_in;
	t_file *tab_out;

	tab_in = tab->in;
	tab_out = tab->out;
	while (tab)
	{
		while (tab_in)
		{
			close(tab_in->fd);
			if (tab_in->op == HERE_DOC && tab_in->file)
				unlink(tab_in->file);
			tab_in = tab_in->next;
		}
		while (tab_out && tab_out->fd > 1)
		{
			close(tab_out->fd);
			tab_out = tab_out->next;
		}
		tab = tab->next;
	}
}

void init_par_data(char **lex, t_cmdtab **tab, t_data **data, char ***env)
{
	if (lex)
		*tab = parser(lex);
	if (tab)
	{
		*data = init_data_struct(*tab, env);
		add_front(singleton(), *data, DATA);
	}
	if (!*data || !*tab || !*lex)
	{
		free_all(*tab);
		return;
	}
}

void exec_final(t_cmdtab *tab, t_data *data)
{
	if (is_builtin(tab) && data->p_count == 1 && check_redir(tab))
		launch_builtin(tab, data);
	else if (tab->opt && tab->opt[0] && data)
		exec(tab, data);
	close_all_fds(tab);

}

void wait_all(t_data *data, t_cmdtab *tab)
{
	int i;

	i = 0;

	while (tab && waitpid(data->pid[i], &g_status, 0) > 0)
	{
		if (WTERMSIG(g_status) == 2)
		{
			ft_putstr_fd("\n", 2);
			g_status = 130;
		}
		else if (WTERMSIG(g_status) == 3)
		{
			ft_putstr_fd(" Quit (core dumped)\n", 2);
			g_status = 131;
		}
		if (WIFEXITED(g_status))
			g_status = WEXITSTATUS(g_status);
		check_status(tab->opt[0]);
		close_final_fd(tab);
		tab = tab->next;
		i++;
	}
}
