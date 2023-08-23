/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:29:14 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/23 11:49:19 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_a_while(int duration)
{
	time_t	start;

	start = whats_the_time();
	while (1)
	{
		if (whats_the_time() - start >= duration)
			break;
		usleep(50);
	}
}
