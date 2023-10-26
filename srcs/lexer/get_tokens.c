/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:53:20 by aminko            #+#    #+#             */
/*   Updated: 2023/10/26 01:01:15 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	between_squotes(int *q, int len, int i)
{
	int	j;

	j = 0;
	while (q && j < len)
	{
		if (i > q[j] && i < q[j + 1])
			return (1);
		j += 2;
	}
	return (0);
}

int	between_dquotes(int *dq, int len, int i)
{
	int	j;

	j = 0;
	while (dq && j < len)
	{
		if (i > dq[j] && i < dq[j + 1])
			return (1);
		j += 2;
	}
	return (0);
}

void	fill_tks(t_tks **tks, char c, int active, int j)
{
	if (c == '|' && (*tks)->p)
		(*tks)->p[j] = active;
	else if (c == '<' && (*tks)->in)
		(*tks)->in[j] = active;
	else if (c == '>' && (*tks)->out)
		(*tks)->out[j] = active;
	else if (c == '$' && (*tks)->dol)
		(*tks)->dol[j] = active;
	else if (c == '?' && (*tks)->qst)
		(*tks)->qst[j] = active;
	else if (c == 1 && (*tks)->ap)
		(*tks)->ap[j] = active;
	else if (c == 2 && (*tks)->d_in)
		(*tks)->d_in[j] = active;
}

t_actok	*init_actok(void)
{
	t_actok	*tok;

	tok = malloc(sizeof(t_actok));
	if (!tok)
		return (NULL);
	tok->i = 0;
	tok->j = 0;
	return (tok);
}

void	active_s_tokens(char *line, t_tks *tks, char c)
{
	t_actok	*ind;

	ind = init_actok();
	while (line && line[ind->i])
	{
		if (line[ind->i] == c && (not_quotes(tks, ind->i, '"'))
			&& not_quotes(tks, ind->i, '\''))
		{
			if (line[ind->i + 1] && line[ind->i + 1] == c)
				ind->i++;
			else
				fill_tks(&tks, c, 1, ind->j++);
		}
		else if (line[ind->i] == c)
		{
			if (line[ind->i + 1] && line[ind->i + 1] == c)
				ind->i++;
			else
				fill_tks(&tks, c, 0, ind->j++);
		}
		if (line[ind->i])
			ind->i++;
	}
	free(ind);
}
