/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:51 by aminko            #+#    #+#             */
/*   Updated: 2022/11/18 19:07:25 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La fonction memchr() examine les n premiers octets de
la zone mémoire pointée par s à la recherche du caractère c.
Le premier octet correspondant à c (interprété comme
un unsigned char) arrête l'opération.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char	buffer[80];
// 	char	*str;

// 	strcpy(buffer, "hello");

// 	str = (char *)ft_memchr(buffer, 'z', 25);
// 	if (str == NULL)
// 		printf("not found\n");
// 	else
// 		printf("%s\n", str);
// 	return (0);
// }
