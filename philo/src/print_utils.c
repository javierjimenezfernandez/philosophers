/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:08:24 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/28 19:37:15 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_fd(int fd, const char *log_info)
{
	if (log_info)
		write(fd, log_info, ft_strlen(log_info));
}

void	print_state(char *str, t_philo *philo)
{
	time_t	timestamp;

	pthread_mutex_lock(philo->print_lock);
	timestamp = gettime_in_ms() - philo->init_timestamp;
	if (!is_dead(philo))
		printf("%ld %d %s\n", timestamp, philo->philo_id, str);
	pthread_mutex_unlock(philo->print_lock);
}

void	print_philo_part1(const t_philo *philo)
{
	printf("=== Philosopher Info ===\n");
	printf("Philosopher ID        : %u\n", philo->philo_id);
	printf("Number of Philosophers: %u\n", philo->n_of_philos);
	printf("Time to die           : %u ms\n", philo->time_to_die);
	printf("Time to eat           : %u ms\n", philo->time_to_eat);
	printf("Time to sleep         : %u ms\n", philo->time_to_sleep);
	printf("Num times must eat    : %u\n", philo->num_times_must_eat);
	printf("Meals eaten           : %u\n", philo->meals_eaten);
	printf("Init timestamp        : %ld\n", (long)philo->init_timestamp);
	printf("Last meal timestamp   : %ld\n", (long)philo->last_meal);
	if (philo->is_eating)
		printf("Is eating             : %s\n", "true");
	else
		printf("Is eating             : %s\n", "false");
}

void	print_philo(const t_philo *philo)
{
	if (!philo)
	{
		printf("philo is NULL\n");
		return ;
	}
	print_philo_part1(philo);
	printf("Is dead (ptr)         : %p", (void *)philo->is_dead);
	if (philo->is_dead)
	{
		if (*philo->is_dead)
			printf(" -> %s\n", "true");
		else
			printf(" -> %s\n", "false");
	}
	else
		printf("\n");
	printf("Thread ID             : %lu\n", (unsigned long)philo->thread);
	printf("Left fork mutex       : %p\n", (void *)philo->l_fork);
	printf("Right fork mutex      : %p\n", (void *)philo->r_fork);
	printf("Print lock            : %p\n", (void *)philo->print_lock);
	printf("Last meal lock        : %p\n", (void *)philo->last_meal_lock);
	printf("Is dead lock          : %p\n", (void *)philo->is_dead_lock);
	printf("=======================\n");
}

void	print_all_philos(const t_philo *philo_array)
{
	unsigned int	i;

	i = 0;
	while (i < philo_array[0].n_of_philos)
	{
		print_philo(&philo_array[i]);
		i++;
	}
}
