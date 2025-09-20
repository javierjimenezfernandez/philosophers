/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:51:14 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/20 14:24:25 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_uitoa(unsigned int n, char *str)
{
	size_t	num_len;

	num_len = ft_uintlen(n);
	str[num_len] = '\0';
	while (num_len--)
	{
		str[num_len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
