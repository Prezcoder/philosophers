/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:15:23 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/28 13:02:52 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>

# define PARAMERROR "You must have between 5 and 6 parameters : ./philo \
[number_of_philosophers][time_to_die][time_to_eat][time_to_sleep]\
[number_of_times_each_philosopher_must_eat(optionnal)]"
# define WRONGTYPE "All the arguments must contains only digits."
# define WRONGNBR "Parameters must be between 1 and 200 philosophers, \
between 60 and 1000000 ms and between 1 and 10000 times."\

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEAD "died\n"

typedef struct s_philo
{
	int				id;
	int				nb_philo;
	time_t			ttd;
	time_t			tte;
	time_t			tts;
	int				times;
	bool			*dead;
	time_t			start_time;
	time_t			last_meal;
	pthread_mutex_t	leftfork;
	pthread_mutex_t	*rightfork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*meal;
	pthread_mutex_t	*death;
}				t_philo;

typedef struct s_data
{
	int				nb_philo;
	time_t			ttd;
	time_t			tte;
	time_t			tts;
	int				times_philo;
	bool			dead;
	time_t			start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	meal;
	pthread_mutex_t	death;
	t_philo			philo[200];
}				t_data;

int		mess_error(char *mess, int flag);
int		all_digits(char **argv);
t_data	*welcoming_the_guests(t_data *data, char **argv);
void	mutex_init(t_data *data);
int		ft_atoi(const char *str);
void	sitting_the_philosophers(t_data *data);
void	enjoying_the_meal(t_data *data, pthread_t *thread);
time_t	whats_the_time(void);
void	*routine(void *philoptr);
void	*mutex_print(t_philo *philo, char *message);
void	wait_a_while(int duration);
void	*philos_are_eating(t_philo *philo);
void	*whose_starving(t_data *data);
void	philo_dead(t_data *data, time_t time, int i);
bool	mutex_dead(t_philo *philo);
void	enjoying_each_other(t_data *data, pthread_t *thread);
void	cleaning_the_table(t_data *data);

#endif