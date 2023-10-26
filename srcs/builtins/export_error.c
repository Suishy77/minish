/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:31:01 by aminko            #+#    #+#             */
/*   Updated: 2023/10/26 01:41:30 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arg_err(char c)
{
	char	*invalid;
	int		i;

	i = 0;
	invalid = allocate_str(".!?+/<>*-");
	while (invalid && invalid[i])
	{
		if (c == invalid[i])
			return (free(invalid), 1);
		i++;
	}
	return (free(invalid), 0);
}

int	error_export(char *var_exp)
{
	int	i;
	int	j;

	i = 0;
	while (var_exp && var_exp[i] && var_exp[i] != '=')
	{
		j = 0;
		if (is_char_num(var_exp[j]))
			return (1);
		if (arg_err(var_exp[i]))
			return (1);
		i++;
	}
	if (i == 0)
		return (1);
	return (0);
}

void	error_export_print(char *var_exp)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(var_exp, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	g_status = 1;
}
