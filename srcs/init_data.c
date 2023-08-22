/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:30:19 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/22 13:01:16 by fbouchar         ###   ########.fr       */
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

// void	parsing(t_data *data, char **argv)
// {
	
// }

void	init_data(t_data *data, char **argv)
{
	data->times_philo = -2;
	if (ft_atoi(argv[1]) >= 0 &&  ft_atoi(argv[1]) <= 200)
		data->philo->nb_philo = ft_atoi(argv[1]);
	else
		data->philo->nb_philo = -1;
	check_time_to(&data->ttd, argv[2]);
	check_time_to(&data->tte, argv[3]);
	check_time_to(&data->tts, argv[4]);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) >= 0 &&  ft_atoi(argv[5]) <= 10000)
			data->times_philo = ft_atoi(argv[5]);
		else
			data->times_philo = -1;
	}
	if (data->ttd == -1 || data->tte == -1 || data->tts == -1
		|| data->times_philo == -1 || data->philo->nb_philo == -1)
	{
		mess_error(WRONGNBR);
		exit(1);
	}
	printf("%d\n", data->philo->nb_philo);
	printf("%ld\n", data->ttd);
	printf("%ld\n", data->tte);
	printf("%ld\n", data->tts);
	printf("%d\n", data->times_philo);
}