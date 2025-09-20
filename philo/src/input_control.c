/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:06:39 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/20 14:27:26 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_out_of_range(char *num, char *range, t_arguments argument)
{
	if (ft_strlen(num) > ft_strlen(range))
		return (1);
	if (ft_strlen(num) == ft_strlen(range))
	{
		if (ft_atoi(num) > ft_atoi(range))
			return (1);
	}
	if (argument == number_of_philosophers
		|| argument == time_to_die
		|| argument == time_to_eat
		|| argument == time_to_sleep)
	{
		if (ft_atoi(num) == 0)
			return (1);
	}
	return (0);
}

int	is_input_correct(int argc, char **argv)
{
	t_arguments	i;
	char		range[MAX_UINT_LENGHT];

	i = number_of_philosophers;
	while ((int)i < argc)
	{
		if (!ft_isalldigit(argv[i]))
			return (wrong_usage());
		if (i == number_of_philosophers)
			ft_uitoa(MAX_THREADS, range);
		else if (i >= time_to_die && i <= time_to_sleep)
			ft_uitoa(MAX_USECONDS, range);
		else if (i == number_of_times_each_philosopher_must_eat)
			ft_uitoa(MAX_UNSIGNEDINT, range);
		if (is_out_of_range(argv[i], range, i))
			return (wrong_usage());
		i++;
	}
	return (1);
}

t_init_cond	parse_input(int argc, char **argv)
{
	t_init_cond	init_cond;

	init_cond.number_of_philosophers = ft_atoi(argv[number_of_philosophers]);
	init_cond.time_to_die = ft_atoi(argv[time_to_die]);
	init_cond.time_to_eat = ft_atoi(argv[time_to_eat]);
	init_cond.time_to_sleep = ft_atoi(argv[time_to_sleep]);
	if (argc == 5)
		init_cond.number_of_times_each_philosopher_must_eat = 0;
	else if (argc == 6)
	{
		init_cond.number_of_times_each_philosopher_must_eat = \
			ft_atoi(argv[number_of_times_each_philosopher_must_eat]);
		if (init_cond.number_of_times_each_philosopher_must_eat == 0)
			init_times_must_eat_is_zero();
	}
	return (init_cond);
}
