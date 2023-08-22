/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:15:23 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/22 13:09:48 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <limits.h>
# include <pthread.h>

# define PARAMERROR "You must have between 5 and 6 parameters : ./philo \
[number_of_philosophers][time_to_die][time_to_eat][time_to_sleep]\
[number_of_times_each_philosopher_must_eat(optionnal)]"
# define WRONGTYPE "All the arguments must contains only digits"
# define WRONGNBR "Parameters must be between 1 and 200 philosophers and \
between 60 and 1000000 ms."

typedef struct s_philo
{
	int		nb_philo;
	time_t	ttd;
	time_t	tte;
	time_t	tts;
}			t_philo;

typedef struct s_data
{
	time_t	ttd;
	time_t	tte;
	time_t	tts;
	int		times_philo;
	t_philo	philo[1000];
}			t_data;


int		main(int argc, char **argv);
int		mess_error(char *mess);
int		all_digits(char **argv);
void	init_data(t_data *data, char **argv);
int		ft_atoi(const char *str);

#endif