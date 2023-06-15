/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:31:27 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/15 15:41:51 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ms;
	size_t	i;

	i = 0;
	ms = (char *)s;
	while (i <= ft_strlen(s))
	{
		if (ms[0] == (unsigned char)c)
			return (ms);
		i++;
		ms++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		len = 0;
	news = (char *)malloc((len + 1) * sizeof(char));
	if (!news)
		return (NULL);
	while (*(s + start) && i < len && s[i] != '\0')
	{
		news[i] = *(s + start + i);
		i++;
	}
	news[i] = '\0';
	return (news);
}

int	lchecker(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		co;
	int		l;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	co = 0;
	a = (char **)malloc((wordcheck(s, c) + 1) * sizeof(char *));
	if (!a)
		return (0);
	while (co < wordcheck(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		l = lchecker(s, c, i);
		a[co] = ft_substr(s, i, l);
		i += l;
		if (!(a))
			freed(a);
		co++;
	}
	a[co] = 0;
	return (a);
}
