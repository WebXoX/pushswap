/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:55:13 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/15 15:36:20 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (lst != NULL)
	{
		temp = lst->next;
		i++;
		lst = temp;
	}
	return (i);
}

t_list	*ft_lstnew(int content)
{
	t_list	*cont;

	cont = (t_list *)malloc(sizeof(t_list));
	if (!cont)
	{
		return (NULL);
	}
	cont->content = content;
	cont->next = NULL;
	return (cont);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	while (lst != NULL)
	{
		temp = lst->next;
		if (temp == NULL)
			break ;
		lst = temp;
	}
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst)
	{
		temp = *lst;
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}
