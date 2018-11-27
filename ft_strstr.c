/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:53:33 by hrice             #+#    #+#             */
/*   Updated: 2018/11/26 19:32:48 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == needle[i])
			i++;
		else
			i = 0;
		if (!needle[i])
			return ((char *)haystack - i + 1);
		haystack++;
	}
	return (0);
}
