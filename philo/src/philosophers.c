/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:44:13 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/20 21:37:09 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_philosophing(t_init_cond init_cond)
{
	t_main_data_struct	main_data;
	t_philo				philo_array[MAX_THREADS];
	pthread_mutex_t		fork_array[MAX_THREADS];

	init_main_data_struct(&main_data, philo_array);
	init_forks(fork_array, init_cond.number_of_philosophers);
	init_philos(init_cond, philo_array, &main_data, fork_array);
	destroy_all_mutexes(NULL, &main_data, fork_array);
}

int	main(int argc, char **argv)
{
	t_init_cond	init_cond;

	if (argc >= 5 && argc <= 6)
	{
		if (!is_input_correct(argc, argv))
			return (0);
		init_cond = parse_input(argc, argv);
		start_philosophing(init_cond);
	}
	else
		wrong_usage();
	return (0);
}
