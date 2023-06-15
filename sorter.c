/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:37:29 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/15 15:37:57 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	same(t_list *a)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		count;

	tmp = a;
	while (tmp)
	{
		count = 0;
		tmp1 = a;
		while (tmp1)
		{
			if (tmp->content == tmp1->content)
				count++;
			if (count == 2)
			{
				write(1, "Error\n", 6);
				return (1);
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	sort3(t_list **a)
{
	if (ft_lstsize((*a)) == 3 && (*a)->amount == 1 && (*a)->next->amount == 0
		&& (*a)->next->next->amount == 2)
		sab(&(*a), ft_lstsize((*a)), 1);
	else if (ft_lstsize((*a)) == 3 && (*a)->amount == 2
		&& (*a)->next->amount == 1 && (*a)->next->next->amount == 0)
	{
		sab(&(*a), ft_lstsize((*a)), 1);
		rrab(&(*a), 1);
	}
	else if ((ft_lstsize((*a)) == 2 && (*a)->amount == 1) || ((*a)->amount == 2
			&& (*a)->next->amount == 0 && (*a)->next->next->amount == 1))
		rab(&(*a), 1);
	else if ((*a)->amount == 0 && (*a)->next->amount == 2
		&& (*a)->next->next->amount == 1)
	{
		sab(&(*a), ft_lstsize((*a)), 1);
		rab(&(*a), 1);
	}
	else if ((*a)->amount == 1 && (*a)->next->amount == 2
		&& (*a)->next->next->amount == 0)
		rrab(&(*a), 1);
}

void	sort(t_list **a, t_list **b)
{
	int	k;
	int	start;

	start = 0;
	while (ft_lstsize(*a) > 3)
	{
		k = distance((*a), start);
		if ((*a)->amount == start)
		{
			pab(&(*a), &(*b), 2);
			start++;
		}
		else
		{
			if (k == 1)
				rab(&(*a), 1);
			else
				rrab(&(*a), 1);
		}
	}
	calc((*a));
	sort3(&(*a));
	while ((*b))
		pab(&(*b), &(*a), 1);
}
