/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:58:39 by aminko            #+#    #+#             */
/*   Updated: 2023/05/13 15:20:41 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
		ft_putchar(n + '0', count);
}

void	ft_putunbr(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10, count);
		ft_putunbr(n % 10, count);
	}
	else
		ft_putchar(n + '0', count);
}
