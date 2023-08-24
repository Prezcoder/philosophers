/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:09:13 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/24 13:01:03 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (mess_error(PARAMERROR, 0));
	if (all_digits(argv))
		return (mess_error(WRONGTYPE, 0));
	welcoming_the_guests(&data, argv);
	sitting_the_philosophers(&data);
	enjoying_the_meal(&data);
	whose_starving(&data);
	enjoying_each_other(&data);
	cleaning_the_table(&data);
	return (0);
}

void	*philos_are_eating(t_philo *philo)
{
	if (mutex_dead(philo) == false)
	{
		pthread_mutex_lock(&philo->leftfork);
		pthread_mutex_lock(philo->rightfork);
		mutex_print(philo, FORK);
		mutex_print(philo, FORK);
		mutex_print(philo, EAT);
		if (mutex_dead(philo) == true)
			return (NULL);
		else
		{
			pthread_mutex_lock(philo->meal);
			philo->last_meal = whats_the_time();
			pthread_mutex_unlock(philo->meal);
			wait_a_while(philo->tte);
			mutex_print(philo, SLEEP);
		}
		pthread_mutex_unlock(&philo->leftfork);
		pthread_mutex_unlock(philo->rightfork);
	}
	return (NULL);
}

void	*routine(void *philoptr)
{
	t_philo	*philo;

	philo = (t_philo *)philoptr;
	if (philo->id % 2 == 1)
	{
		mutex_print(philo, THINK);
		wait_a_while(philo->tte);
	}
	while (1)
	{
		philos_are_eating(philo);
		wait_a_while(philo->tts);
		mutex_print(philo, THINK);
		if (philo->times-- == 1)
			philo->id = 0;
		if (philo->id == 0 || mutex_dead(philo) == true)
			return (NULL);
	}
	return (NULL);
}

void	enjoying_the_meal(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].last_meal = data->start_time;
		data->philo[i].start_time = data->start_time;
		pthread_create(&data->thread[i], NULL, &routine, &data->philo[i]);
		i++;
	}
}

void	enjoying_each_other(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo && mutex_dead(&data->philo[i]) == false)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
}
