/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:44:12 by hrice             #+#    #+#             */
/*   Updated: 2018/11/26 21:02:15 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		if (*haystack == needle[i])
			i++;
		else
			i = 0;
		if (!needle[i])
			return ((char *)haystack - i + 1);
		haystack++;
	}
	return (NULL);
}
