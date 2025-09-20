/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:54:00 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/20 14:28:53 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	wrong_usage(void)
{
	printf("Wrong usage. Please do:\n\n");
	printf("\t./philo number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n");
	printf("Where [number_of_times_each_philosopher_must_eat] is optional.\n");
	printf("\nAll the arguments must be unsigned numbers and:\n");
	printf("\tnumber_of_philosophers:\tmax 200 and different from zero.\n");
	printf("\ttime_to_die:\t\tmax 1000000 and different from zero.\n");
	printf("\ttime_to_eat:\t\tmax 1000000 and different from zero.\n");
	printf("\time_to_sleep:\t\tmax 1000000 and different from zero.\n");
	printf("\t[number_of_times_each_philosopher_must_eat]: max UINT_MAX.\n");
	printf("\nTip: if you want the program to run endlessly, leave\n");
	printf("[number_of_times_each_philosopher_must_eat] argument undefined.\n");
	return (0);
}

void	init_times_must_eat_is_zero(void)
{
	printf("All the philosphers survived!\n\n");
	printf("[number_of_times_each_philosopher_must_eat] was zero.\n");
	printf("Tip: if you want the program to run endlessly, don't define\n");
	printf("its value.\n");
}
