/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:17 by aminko            #+#    #+#             */
/*   Updated: 2023/10/24 20:24:39 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* renvoie un pointeur sur la première occurrence
 du caractère c dans la chaîne s.  */

int	ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}


/*
int main(void)
{
    char buffer[80];
    char *str;

    strcpy(buffer, "hello");
    str = ft_strchr(buffer, 'l');
    if (str == NULL)
        printf("not found\n");
    else
        printf("found: %s\n", str);
    return (0);
}
 */
