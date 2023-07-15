/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:31:08 by aminko            #+#    #+#             */
/*   Updated: 2022/11/17 18:20:42 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* int main (void)
{
	char c = 'a';
	if (ft_isdigit(c))
		printf("yes");
	return (0);
}
 */
