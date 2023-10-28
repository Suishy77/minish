/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_prompt3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:54:18 by aminko            #+#    #+#             */
/*   Updated: 2023/10/27 23:55:30 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	compute_final_len(char *prompt, t_tks *tks)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (prompt && prompt[i])
	{
		if (i > 0 && prompt[i] && prompt[i - 1]
			&& (prompt[i] == '>' || prompt[i] == '<')
			&& (prompt[i - 1] != '<' && prompt[i - 1] != '>'))
		{
			if (!in_quotes(tks, prompt, i))
				if (prompt[i - 1] && prompt[i - 1] != ' '
					&& prompt[i - 1] != '\t')
				len++;
		}
		i++;
		len++;
	}
	return (len);
}

void	loop_2_ouf(char *clean, char *final, t_tks *tks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (clean && clean[i])
	{
		if (i > 0 && clean[i] && clean[i - 1]
			&& (clean[i] == '<' || clean[i] == '>')
			&& (clean[i - 1] != '<' && clean[i - 1] != '>')
			&& (!in_quotes(tks, clean, i)))
		{
			if (clean[i] && clean[i - 1]
				&& clean[i - 1] != ' ' && clean[i - 1] != '\t')
			{
				final[j++] = ' ';
				final[j++] = clean[i++];
			}
		}
		if (i < ft_strlen(clean))
			final[j++] = clean[i++];
	}
	final[j] = '\0';
}

char	*prompt_2_ouf(char *clean, t_tks *tks)
{
	char	*final;

	final = collect(sizeof(char) * (compute_final_len(clean, tks) + 1), CHAR_PTR);
	if (!final)
		return (NULL);
	loop_2_ouf(clean, final, tks);
	return (final);
}

void	final_loop(char *final, char *ret, t_tks *tks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (final && final[i])
	{
		if (i > 0 && !in_quotes(tks, final, i) && final[i] && final[i + 1])
		{
			if (final[i] && final[i] == '>' && final[i + 1] == '<')
			{
				ret[j++] = final[i++];
				ret[j++] = ' ';
			}
			else if (final[i] && final[i] == '<' && final[i + 1] == '>')
			{
				ret[j++] = final[i++];
				ret[j++] = ' ';
			}
		}
		if (i < ft_strlen(final))
			ret[j++] = final[i++];
	}
	ret[j] = '\0';
}

char	*final_treat(char *final, t_tks *tks)
{
	char	*ret;

	ret = collect(sizeof(char) * (last_len(final, tks) + 1), CHAR_PTR);
	if (!ret)
		return (NULL);
	final_loop(final, ret, tks);
	return (ret);
}
