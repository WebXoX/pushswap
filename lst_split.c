/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:06:24 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/15 14:31:50 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[0] == '-') || (str[i] >= '0' && str[i] <= '9')))
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

t_list	*split(char *argc)
{
	char	**str;
	int		i;
	t_list	*first;
	int		move;

	move = 0;
	first = NULL;
	i = 0;
	str = ft_split(argc, ' ');
	while (str[i] != (void *)0)
	{
		if (checker(str[i]) == 1)
		{
			printf("Error\n");
			freed(str);
			ft_lstclear(&first, free);
			return (NULL);
		}
		move = ft_atoi(str[i], move);
		ft_lstadd_back(&first, ft_lstnew(move));
		i++;
	}
	freed(str);
	return (first);
}
