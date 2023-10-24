/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopenas- <dopenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:31:07 by aminko            #+#    #+#             */
/*   Updated: 2023/10/24 16:24:00 by dopenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_exit(t_cmdtab *tab)
{
	if (is_numeric(tab->opt[1]) && len_tab(tab->opt) > 2)
	{
		g_status = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	}
	else if (!is_numeric(tab->opt[1]) && len_tab(tab->opt) >= 2)
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		free_gc();
		exit(2);
	}
	else if (is_numeric(tab->opt[1]) && len_tab(tab->opt) == 2)
	{
		g_status = ft_atoi(tab->opt[1]) % 256;
		free_gc();
		exit(g_status);
	}
}

void	exit_bin(t_cmdtab *tab, t_data *data)
{
	if (data->p_count == 1)
		ft_putstr_fd("exit\n", 1);
	if (tab->opt && tab->opt[1])
		check_exit(tab);
	else
	{
		free_gc();
		exit(g_status);
	}
}
