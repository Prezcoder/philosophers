/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:30:19 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/24 15:20:45 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_time_to(time_t *time_to, char *argv)
{
	if (ft_atoi(argv) >= 60 && ft_atoi(argv) <= 1000000)
		*time_to = (time_t)ft_atoi(argv);
	else
		*time_to = -1;
}

void	welcoming_the_guests(t_data *data, char **argv)
{
	data->times_philo = -2;
	if (ft_atoi(argv[1]) >= 1 && ft_atoi(argv[1]) <= 200)
		data->nb_philo = ft_atoi(argv[1]);
	else
		data->nb_philo = -1;
	check_time_to(&data->ttd, argv[2]);
	check_time_to(&data->tte, argv[3]);
	check_time_to(&data->tts, argv[4]);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) >= 0 && ft_atoi(argv[5]) <= 10000)
			data->times_philo = ft_atoi(argv[5]);
		else
			data->times_philo = -1;
	}
	if (data->ttd == -1 || data->tte == -1 || data->tts == -1
		|| data->times_philo == -1 || data->nb_philo == -1)
		mess_error(WRONGNBR, 1);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->meal, NULL);
	pthread_mutex_init(&data->death, NULL);
	data->dead = false;
}

void	sitting_the_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_philo = data->nb_philo;
		data->philo[i].ttd = data->ttd;
		data->philo[i].tte = data->tte;
		data->philo[i].tts = data->tts;
		data->philo[i].times = data->times_philo;
		data->philo[i].print = &data->print;
		data->philo[i].meal = &data->meal;
		data->philo[i].death = &data->death;
		data->philo[i].dead = &data->dead;
		pthread_mutex_init(&data->philo[i].leftfork, NULL);
		if (i == data->nb_philo - 1)
			data->philo[0].rightfork = &data->philo[i].leftfork;
		else
			data->philo[i + 1].rightfork = &data->philo[i].leftfork;
		i++;
	}
	data->start_time = whats_the_time();
}
