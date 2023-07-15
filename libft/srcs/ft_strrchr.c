/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:30 by aminko            #+#    #+#             */
/*   Updated: 2022/11/14 17:05:04 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* renvoie un pointeur sur la dernière occurrence
du caractère c dans la chaîne s. */

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/* #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

int main(void)
{
	char		*str;
	char	str3[] = "";
		if (!(str = ft_strrchr(str3, '\0')))
			printf("NUL");
		else
		{
			printf("%s", str);
			if (str != str3)
				printf("\nReturn value is false");
		}
	return (0);
}
 */
