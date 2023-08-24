/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watching.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:35:22 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/24 11:03:28 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*looking_for_death(t_data *data)
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