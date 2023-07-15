/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:24:38 by aminko            #+#    #+#             */
/*   Updated: 2023/05/13 15:20:53 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long n, int *count)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, count);
		ft_puthex(n % 16, count);
	}
	else
	{
		if (n < 10)
			ft_putchar((n + '0'), count);
		else
			ft_putchar((n + 87), count);
	}
}

void	ft_putuphex(unsigned long n, int *count)
{
	if (n >= 16)
	{
		ft_putuphex(n / 16, count);
		ft_putuphex(n % 16, count);
	}
	else
	{
		if (n < 10)
			ft_putchar((n + '0'), count);
		else
			ft_putchar((n + 55), count);
	}
}

void	ft_putptr(void *n, int *count)
{
	if (!n)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_puthex((unsigned long long)n, count);
}
