/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:58:02 by aminko            #+#    #+#             */
/*   Updated: 2023/10/24 20:44:04 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/*  retourne une chaîne de
caractères issue de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’ et
a pour taille maximale ’len’. */

char	*ft_substr(const char *s, int start, int len)
{
	int	i;
	int	len_s;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str = ft_calloc(1, sizeof(char)));
	i = 0;
	len_s = ft_strlen(s);
	if (start + len > len_s)
		len = len_s - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while ((i < len) && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int main(void)
{
	char str[] = "hello";
	printf("%s", ft_substr(str, 3, 7));
	return(0);
}
 */
