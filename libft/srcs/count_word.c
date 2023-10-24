/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countf_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:44:32 by aminko            #+#    #+#             */
/*   Updated: 2023/10/07 20:44:42 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			res++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (res);
}
