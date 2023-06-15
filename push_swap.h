/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:50:24 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/15 15:40:18 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				amount;
	int				status;
	int				content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstclear(t_list **lst, void (*del)(void *));

char				*ft_strchr(const char *s, int c);
char				**ft_split(char const *s, char c);
char				*ft_substr(const char *s, unsigned int start, size_t len);
int					ft_atoi(const char *nptr, int move);
void				freed(char **a);
size_t				ft_strlen(const char *s);
t_list				*split(char *argc);
int					wordcheck(char const *s, char c);

int					sab(t_list **ab, int size, int flag);
void				ss(t_list **a, t_list **b);
void				pab(t_list **source, t_list **distance, int flag);
void				rab(t_list **first, int flag);
void				rr(t_list **a, t_list **b, int flag);
void				rrab(t_list **first, int flag);
void				rrr(t_list **a, t_list **b);
int					chunck(int size, int iterator, int i);
int					distance(t_list *a, int i);
void				calc(t_list *a);
int					checker(char *str);
void				init(t_list *a);
int					validate(t_list *i);
int					same(t_list *a);
void				sort3(t_list **a);
void				sort(t_list **a, t_list **b);

#endif
