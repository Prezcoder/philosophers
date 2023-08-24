/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:29:14 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/24 13:02:13 by fbouchar         ###   ########.fr       */
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
}

void	*whose_starving(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (data->philo[i].id == 0)
				return (NULL);
			pthread_mutex_lock(&data->meal);
			if (data->philo[i].last_meal != 0 && whats_the_time()
				- data->philo[i].last_meal >= data->philo[i].ttd)
			{
				mutex_print(&data->philo[i], DEAD);
				data->dead = true;
				data->philo[i].id = 0;
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

bool	mutex_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->meal);
	if (*philo->dead == true)
		return (true);
	pthread_mutex_unlock(philo->meal);
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
		usleep(50);
	}
}
