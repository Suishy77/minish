/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:30:52 by aminko            #+#    #+#             */
/*   Updated: 2022/11/09 13:51:23 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* int main (void)
{
	char c = '	';
	if (ft_isascii(c))
		printf("yes");
	return (0);
}
 */
