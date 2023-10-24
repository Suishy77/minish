/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopenas- <dopenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:31:12 by aminko            #+#    #+#             */
/*   Updated: 2023/10/24 16:23:38 by dopenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_n(char **cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd && cmd[i])
	{
		if (!ft_strncmp(cmd[i], "-n", 2))
		{
			j = 1;
			while (cmd[i][j])
			{
				if (cmd[i][j] != 'n')
					return (i + 1);
				j++;
			}
		}
		else
			return (i + 1);
		i++;
	}
	return (i + 1);
}

int	ft_echo(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write(fd, &str[i], 1) < 0)
		{
			g_status = 1;
			ft_putstr_fd("bash: echo: write error: No space left on device\n",
				2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_quoted(char *str)
{
	return ((str[0] == '"' || str[0] == '\'')
		&& str[ft_strlen(str) - 1] == str[0]);
}

void	echo(char **cmd, int fd)
{
	int	i;
	int	flag;

	g_status = 0;
	flag = find_n(cmd + 1);
	i = flag;
	while (cmd && cmd[i])
	{
		if (i > flag)
			ft_putstr_fd(" ", fd);
		if (is_quoted(cmd[i]))
		{
			ft_putstr_fd(cmd[i] + 1, fd);
			cmd[i][ft_strlen(cmd[i]) - 1] = '\0';
		}
		else
		{
			ft_putstr_fd(cmd[i], fd);
		}
		i++;
	}
	if (flag == 1)
		write(fd, "\n", 1);
	if (fd > 1)
		close(fd);
}
