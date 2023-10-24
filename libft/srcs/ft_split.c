/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:14 by aminko            #+#    #+#             */
/*   Updated: 2023/10/07 20:44:58 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** retourne un tableau de chaînes de caractères obtenu
** en séparant ’s’ à l’aide du caractère ’c’, utilisé comme délimiteur.
*/

static char	*get_word(char const *s, char c, int *index)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (s[(*index)] == c && s[(*index)])
		(*index)++;
	while (s[(*index) + len] != c && s[(*index) + len])
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[(*index)];
		i++;
		(*index)++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < count_word(s, c))
	{
		tab[i] = get_word(s, c, &j);
		if (!tab[i])
		{
			while (i >= 0)
				free(tab[i++]);
			return (NULL);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}

/* #include <stdlib.h>
#include <stdio.h>


int main(void)
{
	char	**tab;
	int	 i;

	tab = ft_split("  abcdefghijk	", 'h');
	i = 0;
	while (tab[i])
	{
		printf("tab[%d] = %s\n", i, tab [i]);
		i++;
	}
	return 0;
} */
