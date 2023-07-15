/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:29:58 by aminko            #+#    #+#             */
/*   Updated: 2022/11/17 18:21:26 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/* int main (void)
{
	char c = ' ';
	if (ft_isprint(c))
		printf("yes");
	return (0);
}
 */
