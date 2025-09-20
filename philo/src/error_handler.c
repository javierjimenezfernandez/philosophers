/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:54:00 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/20 20:46:20 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_fd(int fd, const char *log_info)
{
	if (log_info)
		write(fd, log_info, ft_strlen(log_info));
}

void	wrong_usage(void)
{
	log_fd(STDERR_FILENO,
		"Wrong usage. Please do:\n\n\
\t./philo number_of_philosophers time_to_die time_to_eat\
time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n\
Where [number_of_times_each_philosopher_must_eat] is optional.\n\
\nAll the arguments must be unsigned numbers and:\n\
\tnumber_of_philosophers:\tmax 200 and different from zero.\n\
\ttime_to_die:\t\tmax 1000000 and different from zero.\n\
\ttime_to_eat:\t\tmax 1000000 and different from zero.\n\
\ttime_to_sleep:\t\tmax 1000000 and different from zero.\n\
\t[number_of_times_each_philosopher_must_eat]: max UINT_MAX.\n\
\nTip: if you want the program to run endlessly, leave\n\
[number_of_times_each_philosopher_must_eat] argument undefined.\n");
}

void	init_times_must_eat_is_zero(void)
{
	log_fd(STDOUT_FILENO,
		"All the philosphers survived!\n\n\
[number_of_times_each_philosopher_must_eat] was zero.\n\
\nTip: if you want the program to run endlessly, leave\n\
[number_of_times_each_philosopher_must_eat] argument undefined.\n");
}

void	destroy_all_mutexes(const char *log_info,
			t_main_data_struct *main_data, pthread_mutex_t *forks)
{
	unsigned int	i;

	log_fd(STDERR_FILENO, log_info);
	pthread_mutex_destroy(&main_data->print_log_lock);
	pthread_mutex_destroy(&main_data->time_to_die_lock);
	pthread_mutex_destroy(&main_data->kill_philo_lock);
	i = 0;
	while (i < main_data->philo_array[0].n_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
