/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:52:48 by aminko            #+#    #+#             */
/*   Updated: 2023/10/28 19:08:39 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_status;

void minishell_exec(t_data *data, t_cmdtab *tab)
{
	if (is_builtin(tab))
	{
		close_pipes(data);
		launch_builtin(tab, data);
		free_all(tab);
		exit(0);
	}
	else
	{
		close_final_fd(tab);
		close_pipes(data);
		if (execve(tab->cmd, tab->opt, data->env) == -1)
		{
			free_all(tab);
			exit(0);
		}
	}
}

void minishell(t_data *data, t_cmdtab *tab, int i)
{
	t_cmdtab *last;

	last = lstlast(tab);
	if (check_redir(tab))
	{
		redir(data, tab, i);
		minishell_exec(data, tab);
	}
	else
	{
		close_fds_hd(last);
		close_pipes(data);
		free_all(tab);
		exit(1);
	}
}

void	exec(t_cmdtab *tab, t_data *data)
{

	int i;
	t_cmdtab *tmp;

	i = 0;
	tmp = tab;
	init_pipes(data);
	while (tab && i < data->p_count)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			return;
		signal(SIGINT, child_signal);
		signal(SIGQUIT, child_signal);
		if (data->pid[i] == 0)
			if (!check_access(data, tab))
				minishell(data, tab, i);
		close_final_fd(tab);
		tab = tab->next;
		i++;
	}
	close_pipes(data);
	wait_all(data, tmp);
}

void	mini_loop(char ***env)
{
	char		*prompt;
	char		**lex;
	t_data		*data;
	t_cmdtab	*tab;

	tab = NULL;
	while (1)
	{
		signal(SIGINT, signal_nl);
		signal(SIGQUIT, SIG_IGN);
		prompt = readline("minishell> ");
		if (!prompt)
			break ;
		if (prompt[0])
			add_history(prompt);
		lex = lexer(prompt, *env);
		free(prompt);
		init_par_data(lex, &tab, &data, env);
		if (!lex || !tab || !data)
			continue;
		exec_final(tab, data);
		*env = ft_strdup_tab(data->env);
		free_all(tab);
	}
}

int main(int argc, char **argv, char **envp)
{
	char	**env;

	/* if (!isatty(STDIN_FILENO))
		return (ft_putstr_fd("OOPS! Error !\n", 2), 2); */
	env = ft_strdup_tab(envp);
	(void)argc;
	(void)argv;
	mini_loop(&env);
	if (env)
		ft_free_tab(env);
	rl_clear_history();
	ft_putstr_fd("exit\n", 2);
	return (g_status);
}
