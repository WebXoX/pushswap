/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:43:51 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/15 14:07:47 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sab(t_list **ab, int size, int flag)
{
	t_list	*index2;
	t_list	*index1;

	if (flag == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	if (!(*ab)->next)
		return (1);
	index1 = (*ab);
	index2 = (*ab)->next;
	if (size > 2)
		(*ab) = (*ab)->next->next;
	index1->next = NULL;
	index2->next = NULL;
	if (size != 2)
	{
		ft_lstadd_front(ab, index1);
		ft_lstadd_front(ab, index2);
	}
	else
		ft_lstadd_front(ab, index2);
	return (0);
}

void	ss(t_list **a, t_list **b)
{
	if (sab(&(*a), ft_lstsize((*a)), 1) == 1)
		write(1, "failed", 6);
	if (sab(&(*b), ft_lstsize((*b)), 2) == 1)
		write(1, "failed", 6);
	write(1, "ss\n", 3);
}

void	pab(t_list **source, t_list **distance, int flag)
{
	t_list	*temp;

	temp = *source;
	if ((*source)->next != NULL)
		*source = (*source)->next;
	else
		*source = NULL;
	ft_lstadd_front(distance, temp);
	if (flag == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	rab(t_list **first, int flag)
{
	t_list	*tmp;

	tmp = (*first);
	*first = (*first)->next;
	tmp->next = NULL;
	ft_lstadd_back(first, tmp);
	if (flag == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rrab(t_list **first, int flag)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = ft_lstlast((*first));
	tmp1 = (*first);
	while (tmp1->next->next)
	{
		tmp1 = tmp1->next;
	}
	tmp1->next = NULL;
	ft_lstadd_front(&(*first), tmp);
	if (flag == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

// void	rrr(t_list **a, t_list **b)
// {
// 	rrab(a);
// 	rrab(b);
// }

// void	rr(t_list **a, t_list **b)
// {
// 	rab(a);
// 	rab(b);
// }