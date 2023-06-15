/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:53:55 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/15 15:37:17 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunck(int size, int iterator, int i)
{
	int	loop;
	int	diff;

	loop = size / i - 1;
	diff = size - loop * 3;
	return (i * (loop - iterator));
}

int	distance(t_list *a, int i)
{
	t_list	*b;
	int		count;
	int		diff;
	int		size;

	count = 0;
	diff = 0;
	b = a;
	size = ft_lstsize(a);
	while (a)
	{
		if (a->amount == i)
		{
			break ;
		}
		count++;
		a = a->next;
	}
	diff = size - count;
	if (count < diff)
		return (1);
	else
		return (0);
}

void	calc(t_list *a)
{
	t_list	*b;
	t_list	*c;
	int		count;

	c = a;
	while (a != NULL)
	{
		count = 0;
		b = c;
		while (b != NULL)
		{
			if ((a)->content > b->content)
				count++;
			b = b->next;
		}
		(a)->amount = count;
		(a) = (a)->next;
	}
}

int	validate(t_list *i)
{
	t_list	*j;

	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->content > j->content)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

void	init(t_list *a)
{
	int	i;
	int	j;

	j = 1;
	i = ft_lstsize(a);
	while (j <= i)
	{
		a->status = j;
		a = a->next;
		j++;
	}
}
