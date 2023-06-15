/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:26:28 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/15 15:34:53 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	spacexsign(const char *nptr, int i, int *sign)
{
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr, int move)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	i = spacexsign(nptr, i, &sign);
	while (nptr[i] != '\0')
	{
		if (sign == -1 && i == 10 && result == 214748364 && nptr[i] > '8')
			return (move);
		if (sign == 1 && i == 9 && result == 214748364 && nptr[i] >= '7')
			return (move);
		if (nptr[i] >= '0' && nptr[i] <= '9')
			result = result * 10 + (nptr[i] - '0');
		else
			break ;
		i++;
	}
	return (result * sign);
}
