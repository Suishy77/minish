/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:49:45 by aminko            #+#    #+#             */
/*   Updated: 2023/10/27 23:01:09 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	numlen(long long int num)
{
	int	i;

	i = 0;
	if (num == LONG_MIN)
		return (20);
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		i = 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_char_num(char c)
{
	char	*nums;
	int		i;

	i = 0;
	nums = allocate_str("0123456789");
	if (!nums)
		return (0);
	while (nums && nums[i])
	{
		if (c == nums[i])
			return (free(nums), 1);
		i++;
	}
	free(nums);
	return (0);
}

char	*ft_strjoin_hd(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*dest;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len + 1)); // ici
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i++] = s2[j];
	dest[i] = '\0';
	return (dest);
}

long long int	ft_atol(const char *nptr)
{
	long long int	i;
	long long int	neg;
	long long int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13)))
		i++;
	if (nptr[i] && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		result = result * 10 + (nptr[i++] - '0');
	return (result * neg);
}
