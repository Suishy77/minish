/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:52:24 by aminko            #+#    #+#             */
/*   Updated: 2023/10/26 03:01:27 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_builtin(t_cmdtab *tab)
{
	if (tab && tab->opt && tab->opt[0])
	{
		if (!ft_strcmp(tab->opt[0], "echo"))
			return (1);
		else if (!ft_strcmp(tab->opt[0], "pwd"))
			return (1);
		else if (!ft_strcmp(tab->opt[0], "cd"))
			return (1);
		else if (!ft_strcmp(tab->opt[0], "export"))
			return (1);
		else if (!ft_strcmp(tab->opt[0], "unset"))
			return (1);
		else if (!ft_strcmp(tab->opt[0], "env"))
			return (1);
		else if (!ft_strcmp(tab->opt[0], "exit"))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

char *get_pwd(char **env)
{
	int i;
	char *pwd;

	i = 0;
	pwd = NULL;
	while (env && env[i])
	{
		pwd = ft_strnstr(env[i], "PWD=", 4);
		if (pwd)
			break;
		i++;
	}
	if (pwd)
		return (pwd + 4);
	else
		return (NULL);
}

char **prepare_pwd(char **env)
{
	char **pwds;
	char *pwd;
	char *oldpwd;

	pwds = malloc(sizeof(char *) * 4);
	if (!pwds)
		return (NULL);
	pwd = NULL;
	oldpwd = NULL;
	if (env && env[0])
	{
		oldpwd = get_pwd(env);
		pwd = getcwd(NULL, 0);
		if (oldpwd && pwd)
		{
			pwds[0] = NULL;
			pwds[1] = ft_strjoin("PWD=", pwd);
			pwds[2] = ft_strjoin("OLDPWD=", oldpwd);
			pwds[3] = NULL;
		}
		else
			return (free(pwd), NULL);
	}
	return (free(pwd), pwds);
}

char **conditions_cd(t_cmdtab *tab, t_data *data, char **var_exp)
{
	if (tab->opt[1] && tab->opt[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		g_status = 1;
	}
	else if (!tab->opt[1] || !ft_strcmp(tab->opt[1], "~"))
	{
		change_dir(getenv("HOME"));
		var_exp = prepare_pwd(data->env);
		if (var_exp)
			data->env = export(data->env, var_exp);
	}
	else if (tab->opt[1])
	{
		if (change_dir(tab->opt[1]) != -1)
		{
			var_exp = prepare_pwd(data->env);
			if (var_exp)
				data->env = export(data->env, var_exp);
		}
	}
	return var_exp;
}

void launch_cd(t_cmdtab *tab, t_data *data)
{
	char **var_exp;
	char *str;

	var_exp = NULL;
	str = getcwd(0, 0);
	if (!str)
	{
		if (!tab->opt[1] || !ft_strcmp(tab->opt[1], "~"))
		{
			change_dir(getenv("HOME"));
			var_exp = prepare_pwd(data->env);
			if (var_exp)
				data->env = export(data->env, var_exp);
		}
		else
			getcwd_error("chdir");
	}
	else
		var_exp = conditions_cd(tab, data, var_exp);
	free(str);
	prep_pwd(var_exp);
}
