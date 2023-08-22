/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:41:10 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/22 11:10:22 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	mess_error(char *mess)
{
	printf("%s\n", mess);
	return (-1);
}

int	all_digits(char **argv)
{
	int	i;
	int	j;
	
	j = 1;
	while (argv[j])
	{
		i = 0;
		while(argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	num;

	i = 0;
	s = 1;
	num = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (s * num);
}
