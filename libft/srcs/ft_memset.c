/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:35 by aminko            #+#    #+#             */
/*   Updated: 2022/11/19 14:06:17 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**  remplit les n premiers octets de la zone mémoire
**  pointée par s avec l'octet c.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = ((unsigned char)c);
	return (b);
}

/* #include <string.h>
#include <stdio.h>

int main(void)
{
	char buffer[10];

	ft_memset(buffer, '=', 10);
	buffer[9] = '\0';

	puts(buffer);
	return (0);
} */
