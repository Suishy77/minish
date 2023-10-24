/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopenas- <dopenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:30:49 by aminko            #+#    #+#             */
/*   Updated: 2023/10/24 16:24:05 by dopenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_unseted(char **env, char *varname)
{
	char	**unseted;

	if (existing_var(env, varname) && varname[ft_strlen(varname) - 1] != '=')
		unseted = collect(sizeof(char *) * (len_tab(env)));
	else
		unseted = collect(sizeof(char *) * (len_tab(env) + 1));
	g_status = 0;
	if (!unseted)
		return (NULL);
	return (unseted);
}

char	**unset(char **env, char *varname)
{
	int		i;
	int		j;
	char	**unseted;

	i = 0;
	j = 0;
	unseted = init_unseted(env, varname);
	if (!unseted)
		return (NULL);
	while (env && env[i])
	{
		if (!ft_strncmp(varname, env[i], ft_strchr(env[i], '='))
			&& ft_strlen(varname) == ft_strchr(env[i], '='))
			i++;
		else if (!ft_strchr(env[i], '=')
			&& ft_strlen(varname) == ft_strlen(env[i]))
			i++;
		if (env[i])
		{
			unseted[j++] = ft_strdup(env[i]);
			i++;
		}
	}
	unseted[j] = NULL;
	return (unseted);
}
