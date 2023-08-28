/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:29:14 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/28 12:01:01 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	cleaning_the_table(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philo[i].leftfork);
		i++;
	}
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
}

void	*whose_starving(t_data *data)
{
	int		i;
	time_t	time;

	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			pthread_mutex_lock(&data->meal);
			if (data->philo[i].last_meal != 0 && whats_the_time()
				- data->philo[i].last_meal >= data->philo[i].ttd)
			{
				time = whats_the_time() - data->start_time;
				philo_dead(data, time, i);
				pthread_mutex_unlock(&data->meal);
				return (NULL);
			}
			pthread_mutex_unlock(&data->meal);
			i++;
		}
		usleep(50);
	}
	return (NULL);
}

void	philo_dead(t_data *data, time_t time, int i)
{
	pthread_mutex_lock(&data->death);
	pthread_mutex_lock(&data->print);
	if (data->philo[i].id)
		printf("%ld %d %s", time, data->philo[i].id, DEAD);
	pthread_mutex_unlock(&data->print);
	data->dead = true;
	pthread_mutex_unlock(&data->death);
}

bool	mutex_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->death);
	if (*philo->dead == true)
	{
		pthread_mutex_unlock(philo->death);
		return (true);
	}
	pthread_mutex_unlock(philo->death);
	return (false);
}

void	wait_a_while(int duration)
{
	time_t	start;

	start = whats_the_time();
	while (1)
	{
		if (whats_the_time() - start >= duration)
			break ;
		usleep(40);
	}
}
