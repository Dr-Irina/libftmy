/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:05:49 by hrice             #+#    #+#             */
/*   Updated: 2018/12/01 21:43:50 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_wordlen(char *str, int st, char c)
{
	size_t			count;

	count = 0;
	if (!str)
		return (0);
	while (str[st] && str[st] != c)
	{
		st++;
		count++;
	}
	return (count);
}

static int			ft_countword(char *s, char c)
{
	int				cw;
	int				count;
	char			*str;

	str = (char *)s;
	cw = 0;
	count = 0;
	while (str[count])
	{
		if (str[count] != c && (str[count + 1] == c || str[count + 1] == '\0')) 
			cw++;
		count++;
	}
	return (cw);
}

char				**ft_strsplit(char const *s, char c)
{
	char			*str;
	char			**arr;
	unsigned int	count;
	int				cw;
	int				i;

	str = (char *)s;
	if (!str)
		return (NULL);
	count = 0;
	cw = ft_countword(str, c);
	if (!(arr = (char**)ft_memalloc(sizeof(char*) * (cw + 1))))
		return (NULL);
	i = 0;
	while (i < cw)
	{
		while (str[count] && str[count] == c)
			count++;
		arr[i] = ft_strsub(str, count, ft_wordlen(str, count, c));
		while (str[count] && str[count] != c)
			count++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
