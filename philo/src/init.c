/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:17:32 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/20 20:52:46 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_main_data_struct(t_main_data_struct *main_data, t_philo *philos)
{
	main_data->kill_philo_flag = 0;
	pthread_mutex_init(&main_data->print_lock, NULL);
	pthread_mutex_init(&main_data->time_to_die_lock, NULL);
	pthread_mutex_init(&main_data->kill_philo_lock, NULL);
	main_data->philo_array = philos;
}

void	init_forks(pthread_mutex_t *fork_array, unsigned int num_of_philos)
{
	unsigned int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_init(&fork_array[i], NULL);
		i++;
	}
}

void	assign_forks(t_philo *philo_array, pthread_mutex_t *fork_array,
			unsigned int i)
{
	philo_array[i].l_fork = &fork_array[i];
	if (i == 0)
		philo_array[i].r_fork = &fork_array[philo_array[i].n_of_philos - 1];
	else
		philo_array[i].r_fork = &fork_array[i - 1];
}

void	init_philos(t_init_cond init_cond, t_philo *philo_array,
			t_main_data_struct *main_data, pthread_mutex_t *fork_array)
{
	unsigned int	i;

	i = 0;
	while (i < init_cond.number_of_philosophers)
	{
		philo_array[i].n_of_philos = init_cond.number_of_philosophers;
		philo_array[i].time_to_die = init_cond.time_to_die;
		philo_array[i].time_to_eat = init_cond.time_to_eat;
		philo_array[i].time_to_sleep = init_cond.time_to_sleep;
		philo_array[i].num_times_must_eat = \
			init_cond.number_of_times_each_philosopher_must_eat;
		philo_array[i].philo_id = i + 1;
		philo_array[i].init_timestamp = gettime_in_ms();
		philo_array[i].last_meal = philo_array[i].init_timestamp;
		philo_array[i].meals_eaten = 0;
		philo_array[i].is_eating = 0;
		philo_array[i].is_dead = &main_data->kill_philo_flag;
		assign_forks(philo_array, fork_array, i);
		philo_array[i].print_lock = &main_data->print_lock;
		philo_array[i].time_to_die_lock = &main_data->time_to_die_lock;
		philo_array[i].kill_philo_lock = &main_data->kill_philo_lock;
		i++;
	}
}
