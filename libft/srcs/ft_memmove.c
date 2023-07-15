/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:43:48 by aminko            #+#    #+#             */
/*   Updated: 2022/11/19 14:04:44 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copie n octets depuis la zone mémoire src vers la zone mémoire dest.
**  Les deux zones peuvent se chevaucher : la copie se passe comme si
**  les octets de src étaient d'abord copiés dans une zone temporaire
** qui ne chevauche ni src ni dest, et les octets sont
** ensuite copiés de la zone temporaire vers dest.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len)
		{
			--len;
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	return (dst);
}

/*
int main(void)
{
	char buffer[32] = "World";
	ft_memmove(buffer, buffer + 1, 5);
	printf("%s\n", buffer);

	return (0);
}
 */
