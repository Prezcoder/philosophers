/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:09:13 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/23 12:37:48 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *philoptr)
{
	t_philo	*philo;

	philo = (t_philo *)philoptr;
	if (philo->id % 2 == 0)
	{
		mutex_print(philo, THINK);
		wait_a_while(philo->tte);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->leftfork);
		pthread_mutex_lock(philo->rightfork);
		mutex_print(philo, FORKL);
		mutex_print(philo, FORKR);
		mutex_print(philo, EAT);
		pthread_mutex_lock(philo->meal);
		philo->last_meal = whats_the_time();
		pthread_mutex_unlock(philo->meal);
		pthread_mutex_unlock(&philo->leftfork);
		pthread_mutex_unlock(philo->rightfork);
		wait_a_while(philo->tte);
		mutex_print(philo, SLEEP);
		wait_a_while(philo->tts);
		mutex_print(philo, THINK);
		if (philo->times-- == 0)
			philo->id = 0;
		if (philo->id == 0)
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (mess_error(PARAMERROR, 0));
	if (all_digits(argv))
		return (mess_error(WRONGTYPE, 0));
	init_data(&data, argv);
	init_philo(&data);
	while (i < data.nb_philo)
	{
		pthread_create(&data.thread[i], NULL, &routine, &data.philo[i]);
		i++;
	}
	i = 0;
	while (i < data.nb_philo)
	{
		pthread_join(data.thread[i], NULL);
		i++;
	}
	return (0);
}
