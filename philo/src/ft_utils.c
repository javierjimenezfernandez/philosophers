/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:55:04 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/28 19:35:00 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

bool	ft_isalldigit(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || '9' < str[i])
			return (false);
		i++;
	}
	return (true);
}

size_t	ft_uintlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

unsigned int	ft_atoui(const char *str)
{
	int				i;
	unsigned int	num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

char	*ft_uitoa(unsigned int n, char *str)
{
	size_t	num_len;

	num_len = ft_uintlen(n);
	str[num_len] = '\0';
	if (num_len == 0)
		return (str);
	while (num_len--)
	{
		str[num_len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
