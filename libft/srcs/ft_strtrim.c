/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:57 by aminko            #+#    #+#             */
/*   Updated: 2023/10/27 18:53:28 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* retourne une copie de
la chaîne ’s1’, sans les caractères spécifiés
dans ’set’ au début et à la fin de la chaîne de
caractères. */

int	ft_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_subtrim(char const *str, int start, int end)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(sizeof(char) * (end - start) + 2);
	if (!s)
		return (NULL);
	while (str[i] && start + i <= end)
	{
		s[i] = str[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		start;
	int		len;
	char	*str;

	if (!s || s == 0)
		return (NULL);
	i = 0;
	start = 0;
	if (*s == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s);
	while (s[i] && ft_charset(s[i], set))
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	start = i;
	len--;
	while (s[i] && ft_charset(s[len], set))
		len--;
	str = ft_subtrim(s, start, len);
	if (!str)
		return (NULL);
	return (str);
}
