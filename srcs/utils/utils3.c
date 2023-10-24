/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:53:08 by aminko            #+#    #+#             */
/*   Updated: 2023/10/25 00:47:52 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_single_dollar(t_expand *id, char *expanded)
{
	expanded[id->j++] = '$';
	id->i++;
}

void	expand_variable(char *pro, t_expand *id, char *expanded, char **env)
{
	id->start = ++id->i;
	while (pro[id->i] && pro[id->i] != ' ' && !is_token(pro[id->i]))
		id->i++;
	id->var = get_var(pro, env, id->start, id->i);
	while (id->var && id->var[id->k])
		expanded[id->j++] = id->var[id->k++];
	free(id->var);
}

void	process_dollar(char *pro, t_expand *id, char *expanded, char **env)
{
	if (pro[id->i + 1] == '\0' || pro[id->i + 1] == ' '
		|| is_token(pro[id->i + 1]))
		handle_single_dollar(id, expanded);
	else
		expand_variable(pro, id, expanded, env);
}
