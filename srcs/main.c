/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:09:13 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/22 10:49:13 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	*routine(void *philoptr)
// {
	// t_philo	*philo;
	
	// philo = (t_philo *)philoptr;
// }

int	main(int argc, char **argv)
{
	t_data	data;
	// pthread_t thread;
	// pthread_mutex_t mutex;
	if (argc < 5 || argc > 6)
		return (mess_error(PARAMERROR));
	if (all_digits(argv))
		return (mess_error(WRONGTYPE));
	init_data(&data, argv);
	// parsing(argc, argv);
	// pthread_mutex_init(&mutex, NULL);
	// pthread_create(&thread, NULL, &routine, &data.philo);
	// pthread_mutex_lock(&mutex);
	// pthread_mutex_unlock(&mutex);
	// pthread_join(&mutex, NULL);
	return (0);
}
