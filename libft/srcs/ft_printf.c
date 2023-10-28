/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:58:45 by aminko            #+#    #+#             */
/*   Updated: 2023/10/27 18:52:56 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flag(char *fmt, va_list args, int *count, int *i)
{
	if (fmt[*i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (fmt[*i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (fmt[*i] == 'd' || fmt[*i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (fmt[*i] == 'u')
		ft_putunbr(va_arg(args, unsigned int), count);
	else if (fmt[*i] == 'x')
		ft_puthex((unsigned int )va_arg(args, unsigned long), count);
	else if (fmt[*i] == 'X')
		ft_putuphex((unsigned int )va_arg(args, unsigned long), count);
	else if (fmt[*i] == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (fmt[*i] == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			ft_flag((char *)fmt, args, &count, &i);
		}
		else
			ft_putchar(fmt[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
