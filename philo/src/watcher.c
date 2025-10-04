/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:36:36 by javjimen          #+#    #+#             */
/*   Updated: 2025/10/04 21:50:12 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->is_dead_lock);
	if (*philo->is_dead == true)
		return (pthread_mutex_unlock(philo->is_dead_lock), true);
	return (pthread_mutex_unlock(philo->is_dead_lock), false);
}

bool	is_time_to_die(t_philo *philo)
{
	pthread_mutex_lock(philo->last_meal_lock);
	if ((gettime_in_ms() - philo->last_meal >= philo->time_to_die)
		&& (philo->is_eating == false))
		return (pthread_mutex_unlock(philo->last_meal_lock), true);
	return (pthread_mutex_unlock(philo->last_meal_lock), false);
}

bool	philo_just_died(t_philo *philo_array)
{
	unsigned int	i;

	i = 0;
	while (i < philo_array[0].n_of_philos)
	{
		if (is_time_to_die(&philo_array[i]))
		{
			pthread_mutex_lock(philo_array[i].is_dead_lock);
			*philo_array[i].is_dead = true;
			pthread_mutex_unlock(philo_array[i].is_dead_lock);
			print_died(&philo_array[i]);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	nobody_is_hungry(t_philo *philo_array)
{
	unsigned int	i;

	i = 0;
	if (philo_array[i].num_times_must_eat == 0)
		return (false);
	while (i < philo_array[0].n_of_philos)
	{
		if (philo_array[i].meals_eaten < philo_array[i].num_times_must_eat)
			return (false);
		i++;
	}
	return (true);
}

void	*watcher(void *ptr)
{
	t_philo	*philo_array;

	philo_array = (t_philo *)ptr;
	while (1)
	{
		if (philo_just_died(philo_array) || nobody_is_hungry(philo_array))
			break ;
	}
	return (ptr);
}
