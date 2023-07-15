/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:26:00 by aminko            #+#    #+#             */
/*   Updated: 2023/07/14 17:37:14 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*dup_quotes(char *env)
{
	int		i;
	int		j;
	char	*s;
	int		flag;

	i = -1;
	j = 0;
	flag = 1;
	s = collect(sizeof(char) * (ft_strlen(env) + 3));
	if (!s)
		return (NULL);
	while (env && env[++i])
	{
		s[j] = env[i];
		if (env[i] == '=' && flag)
		{
			s[++j] = '"';
			flag = 0;
		}
		j++;
	}
	if (!flag)
		s[j++] = '"';
	s[j] = '\0';
	return (s);
}

char	**converted_env(char **env)
{
	int		i;
	char	**converted;

	i = -1;
	converted = collect(sizeof(char *) * (len_tab(env) + 1));
	if (!converted)
		return (NULL);
	while (env && env[++i])
		converted[i] = dup_quotes(env[i]);
	converted[i] = NULL;
	return (converted);
}

void	print_export(t_cmdtab *tab, char **env)
{
	int		i;
	int		fd;
	char	**env_export;

	i = 0;
	fd = 1;
	if (tab->out && tab->out->fd)
		fd = tab->out->fd;
	env_export = converted_env(env);
	while (env_export && env_export[i])
	{
		ft_putstr_fd("export ", fd);
		ft_putstr_fd(env_export[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
	g_status = 0;
	if (fd > 1)
		close(fd);
}
