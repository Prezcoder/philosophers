/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:41:10 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/24 13:01:48 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*mutex_print(t_philo *philo, char *message)
{
	time_t	time;

	if (*philo->dead == true)
		return (NULL);
	if (*philo->dead == false)
	{
		time = whats_the_time() - philo->start_time;
		pthread_mutex_lock(philo->print);
		if (*philo->dead == false)
			printf("%ld %d %s", time, philo->id, message);
		pthread_mutex_unlock(philo->print);
	}
	return (NULL);
}

time_t	whats_the_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	mess_error(char *mess, int flag)
{
	printf("%s\n", mess);
	if (flag == 1)
		exit (1);
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
		while (argv[j][i])
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
