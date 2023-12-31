/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:53:41 by aminko            #+#    #+#             */
/*   Updated: 2023/10/27 23:50:14 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tks	*init_tokens(char *str)
{
	t_tks	*tks;

	tks = collect(sizeof(t_tks), NBR);
	if (!tks)
		return (NULL);
	tks->q = collect(sizeof(int) * (count_elem(str, '\'')), NBR);
	tks->dq = collect(sizeof(int) * (count_elem(str, '"')), NBR);
	tks->q_on = collect(sizeof(int) * (count_elem(str, '\'')), NBR);
	tks->dq_on = collect(sizeof(int) * (count_elem(str, '"')), NBR);
	tks->p = collect(sizeof(int) * (count_elem(str, '|')), NBR);
	tks->in = collect(sizeof(int) * count_elem(str, '<'), NBR);
	tks->out = collect(sizeof(int) * count_elem(str, '>'), NBR);
	tks->ap = collect(sizeof(int) * count_d_elem(str, ">>"), NBR);
	tks->d_in = collect(sizeof(int) * count_d_elem(str, "<<"), NBR);
	tks->dol = collect(sizeof(int) * count_elem(str, '$'), NBR);
	tks->qst = collect(sizeof(int) * count_elem(str, '?'), NBR);
	tks->prompt = ft_strdup(str);
	add_front(singleton(), tks->prompt, CHAR_PTR);
	return (tks);
}

void	init_active_tokens(t_tks **tks, char *line)
{
	char	*tokens;
	int		i;

	tokens = "<>|?";
	i = 0;
	if (count_elem(line, '\''))
		get_squotes(line, (*tks)->q);
	if (count_elem(line, '"'))
		get_dquotes(line, (*tks)->dq);
	active_quotes(line, (*tks));
	while (tokens[i])
		active_s_tokens(line, (*tks), tokens[i++]);
	active_dol_token(line, (*tks));
	active_d_tokens(line, (*tks), ">>");
	active_d_tokens(line, (*tks), "<<");
}
