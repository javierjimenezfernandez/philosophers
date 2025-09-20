/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:44:13 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/28 19:52:37 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophize(t_init_cond init_cond)
{
	t_main_data_struct	main_data;
	t_philo				philo_array[MAX_THREADS];
	pthread_mutex_t		fork_array[MAX_THREADS];

	init_main_data_struct(&main_data, philo_array);
	init_forks(init_cond.number_of_philosophers, fork_array);
	init_philos(init_cond, &main_data, philo_array, fork_array);
	threads_create(&main_data, philo_array, fork_array);
	if (!*philo_array[0].is_dead)
		printf("All the philosphers survived!\n");
	destroy_all_mutexes(NULL, &main_data, fork_array);
}

int	main(int argc, char **argv)
{
	t_init_cond	init_cond;

	if (argc == 5 || argc == 6)
	{
		if (!is_input_correct(argc, argv))
			return (0);
		init_cond = parse_input(argc, argv);
		if (argc == 6
			&& init_cond.number_of_times_each_philosopher_must_eat == 0)
			return (0);
		philosophize(init_cond);
	}
	else
		wrong_usage();
	return (0);
}
