/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:54:15 by aminko            #+#    #+#             */
/*   Updated: 2022/11/19 14:22:57 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applique la fonction ’f’ à chaque caractère de la
chaîne de caractères passée en argument pour créer
une nouvelle chaîne de caractères */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s || !(*f))
		return (NULL);
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
