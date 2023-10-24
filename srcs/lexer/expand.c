/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopenas- <dopenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:53:08 by aminko            #+#    #+#             */
/*   Updated: 2023/10/24 17:07:48 by dopenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_expand(char *prompt, t_tks *tks, char **env)
{
	t_expand	*id;
	int			len;

	id = init_expand(env);
	len = 0;
	while (prompt && prompt[id->i])
	{
		if (prompt[id->i] == '$' && tks->dol[id->j++]
			&& no_expand_hd(prompt, id->i, tks))
		{
			id->start = ++id->i;
			while (prompt[id->i] && prompt[id->i] != ' '
				&& !is_token(prompt[id->i]))
				id->i++;
			id->var = get_var(prompt, env, id->start, id->i);
			len += ft_strlen(id->var);
		}
		else
		{
			id->i++;
			len++;
		}
	}
	return (len);
}

t_expand	*init_expand(char **env)
{
	t_expand	*exp;

	exp = collect(sizeof(t_expand));
	if (!exp)
		return (NULL);
	exp->env = env;
	exp->i = 0;
	exp->j = 0;
	exp->k = 0;
	exp->l = 0;
	exp->var = NULL;
	exp->start = 0;
	return (exp);
}

int	no_expand_hd(char *prompt, int dol, t_tks *tks)
{
	if (dol > 0)
		dol--;
	while (prompt && prompt[dol] && dol > 0)
	{
		if (prompt[dol] == '<' && prompt[dol - 1] && prompt[dol - 1] == '<'
			&& (!in_quotes(tks, prompt, dol)))
			return (0);
		else if (prompt[dol] != ' ' && prompt[dol] != '\t')
			return (1);
		dol--;
	}
	return (1);
}

char	*expand(char *pro, char **env, t_tks *tks)
{
	char		*expanded;
	t_expand	*id;

	id = init_expand(env);
	expanded = collect(sizeof(char) * (len_expand(pro, tks, env) * 2 + 1));
	if (!expanded)
		return (NULL);
	while (pro && pro[id->i])
	{
		id->k = 0;
		if (pro[id->i] == '$' && tks->dol[id->l++]
			&& no_expand_hd(pro, id->i, tks))
			process_dollar(pro, id, expanded, env);
		else
			expanded[id->j++] = pro[id->i++];
	}
	expanded[id->j] = '\0';
	return (expanded);
}

/*char	*expand(char *pro, char **env, t_tks *tks)
{
	char		*expanded;
	t_expand	*id;

	id = init_expand(env);
	expanded = collect(sizeof(char) * (len_expand(pro, tks, env) * 2 + 1));
	if (!expanded)
		return (NULL);
	while (pro && pro[id->i])
	{
		id->k = 0;
		if (pro[id->i] == '$' && tks->dol[id->l++]
			&& no_expand_hd(pro, id->i, tks))
		{
			if (pro[id->i + 1] == '\0' || pro[id->i + 1] == ' '
				|| is_token(pro[id->i + 1]))
			{
				expanded[id->j++] = '$';
				id->i++;
			}
			else
			{
				id->start = ++id->i;
				while (pro[id->i] && pro[id->i] != ' ' && !is_token(pro[id->i]))
				{
					id->i++;
				}
				id->var = get_var(pro, env, id->start, id->i);
				while (id->var && id->var[id->k])
					expanded[id->j++] = id->var[id->k++];
			}
		}
		else
			expanded[id->j++] = pro[id->i++];
	}
	expanded[id->j] = '\0';
	return (expanded);
}
*/