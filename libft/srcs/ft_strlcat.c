/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:52:08 by aminko            #+#    #+#             */
/*   Updated: 2022/11/19 14:19:54 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* concatene et renvoie longueur de la chaine */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	i = 0;
	if (size <= dlen)
		return (slen + size);
	while (src[i] && (i < size - dlen - 1))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (slen + dlen);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <bsd/string.h>

// int		main(void)
// {
//  	char	dest[15]  = "rrrrrrrrrrrrrrr";

// 	// if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		// return (0);
// 	// memset(dest, 0, 15);
// 	// memset(dest, 'r', 6);
// 	// memset(dest, 'r', 15);
// 	char *src = "lorem ipsum dolor sit amet";
// 	printf("%ld", strlcat(dest, src, 5));
// 	printf("\n%s", dest);
// 	printf("\n%s", src);
// 	// write(1, "\n", 1);
// 	// write(1, dest, 15);

// 	return (0);
// }
