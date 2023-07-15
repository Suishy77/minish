/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:08:31 by aminko            #+#    #+#             */
/*   Updated: 2022/11/19 14:02:19 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** copie n octets depuis la zone mémoire src vers la zone mémoire dest.
**  Les deux zones ne doivent pas se chevaucher.
*/

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

/* int main(void)
{
	char s2[] = "333333";

	ft_memcpy(0, s2, 10);
	return (0);
} */
