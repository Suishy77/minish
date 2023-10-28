/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_par_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:54:26 by aminko            #+#    #+#             */
/*   Updated: 2023/10/28 00:57:08 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_paths(char **env)
{
	int		i;
	char	*path_var;
	char	**env_path;
	char	*tmp;

	i = -1;
	env_path = NULL;
	while (env && env[++i])
	{
		path_var = ft_strnstr(env[i], "PATH=", 6);
		if (path_var)
		{
			env_path = ft_split(path_var + 5, ':');
			break ;
		}
	}
	i = -1;
	while (env_path && env_path[++i]
		&& env_path[i][ft_strlen(env_path[i]) - 1] != '/')
	{
		tmp = env_path[i];
		env_path[i] = ft_strjoin(env_path[i], "/");
		free(tmp);
	}
	return (env_path);
}

int	len_cmd(char **split)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (split && split[i])
	{
		if (is_redir(split[i]))
			i += 2;
		if (split[i])
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	**get_opt(char **split)
{
	int		i;
	int		j;
	char	**opt;

	i = 0;
	j = 0;
	opt = ft_calloc(sizeof(char *), (len_cmd(split) + 100));
	if (!opt)
		return (NULL);
	while (split && split[i] && opt)
	{
		if (is_redir(split[i]))
			i += 2;
		else if (split[i])
			opt[j++] = ft_strdup(split[i++]);
	}
	return (opt);
}

int	check_abs(char *str)
{
	int	i;

	i = 0;
	if (access(str, X_OK) == 0)
		return (1);
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

char	*get_abs_path(char **paths, char **opt)
{
	int		i;
	char	*abs;
	char	*tmp;

	i = 0;
	abs = NULL;
	tmp = NULL;
	if (!check_abs(opt[0]))
		return (abs);
	while (paths && paths[i] && opt[0])
	{
		tmp = ft_strdup(paths[i]);
		abs = ft_strjoin(tmp, opt[0]);
		if (access(abs, F_OK | X_OK) == 0)
		{
			ft_free_elem((void **)&tmp);
			break ;
		}
		ft_free_elem((void **)&tmp);
		ft_free_elem((void **)&abs);
		i++;
	}
	ft_free_tab(paths);
	return (abs);
}
