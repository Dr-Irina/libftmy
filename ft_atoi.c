/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:24:34 by hrice             #+#    #+#             */
/*   Updated: 2018/11/28 19:57:26 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(const char *str)
{
	int			flag;
	long long	res;
	int			i;
	long long	check;

	flag = 0;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		flag = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = res;
		res = (res * 10) + str[i++] - '0';
		if (res < check)
		return (flag ? 0 : -1);
	}
	return (flag ? -res : res);
}
