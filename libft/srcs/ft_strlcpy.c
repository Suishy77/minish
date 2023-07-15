/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:14:07 by aminko            #+#    #+#             */
/*   Updated: 2022/11/09 13:53:54 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Copies up to size - 1 characters from the string src to dst,
** NUL-terminating the result if dstsize is not 0.
** Returns ft_strlen(src);
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int main(void)
{
	char str[32];
	char s2[] = "333333";

	ft_strlcpy(str, s2, 10);
	printf("%s", str);
	return (0);
}
 */
