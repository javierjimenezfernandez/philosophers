/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:39:58 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/28 19:46:19 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_think(t_philo *philo)
{
	print_state(IS_THINKING, philo);
}

void	to_sleep(t_philo *philo)
{
	print_state(IS_SLEEPING, philo);
	accurate_msleep(philo->time_to_sleep);
}

void	to_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_state(HAS_TAKEN_A_FORK, philo);
	pthread_mutex_lock(philo->r_fork);
	print_state(HAS_TAKEN_A_FORK, philo);
	philo->is_eating = true;
	print_state(IS_EATING, philo);
	pthread_mutex_lock(philo->last_meal_lock);
	philo->last_meal = gettime_in_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->last_meal_lock);
	accurate_msleep(philo->time_to_eat);
	philo->is_eating = false;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	one_philo_logic(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_state(HAS_TAKEN_A_FORK, philo);
	accurate_msleep(philo->time_to_die);
	pthread_mutex_unlock(philo->l_fork);
}

void	*philo_actions(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->n_of_philos == 1)
		one_philo_logic(philo);
	if (philo->philo_id % 2 == 0)
		accurate_msleep(1);
	while (!is_dead(philo))
	{
		to_eat(philo);
		to_sleep(philo);
		to_think(philo);
		if (philo->num_times_must_eat != 0
			&& philo->meals_eaten >= philo->num_times_must_eat)
			break ;
	}
	return (ptr);
}
