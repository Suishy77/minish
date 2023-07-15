/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:56:12 by aminko            #+#    #+#             */
/*   Updated: 2022/11/18 14:29:09 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	if (len <= 0)
		return (NULL);
	while (*haystack && needle_len <= len)
	{
		if (*haystack == *needle && !(ft_memcmp(haystack, needle, needle_len)))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

/* int main(void)
{
	char s1[] = "hello";
	char s2[] = "ll";
	printf("%s", ft_strnstr(s1, s2, 10));
	return (0);
}
 */
