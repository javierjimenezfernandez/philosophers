/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:44:13 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/14 20:30:50 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_init_cond	init_cond;

	if (argc >= 5 && argc <= 6)
	{
		if (!is_input_correct(argc, argv))
			return (0);
		printf("flow control debug: valid input\n");
		init_cond = parse_input(argc, argv);
		/* start "philosophing" */
		(void)init_cond;
	}
	else
	{
		/* wrong usage */
	}
	return (0);
}
