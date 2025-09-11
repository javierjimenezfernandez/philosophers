/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:44:11 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/14 20:51:11 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>

# ifndef MAX_THREADS
#  define MAX_THREADS "200"
# endif /* MAX_THREADS */
/* max for usleep = 1000000. source: man usleep */
# define MAX_USECONDS "1000000"
# define MAX_UNSIGNEDINT "4294967295"

typedef enum e_arguments
{
	number_of_philosophers = 1,
	time_to_die = 2,
	time_to_eat = 3,
	time_to_sleep = 4,
	number_of_times_each_philosopher_must_eat = 5
}			t_arguments;

typedef struct s_init_cond
{
	unsigned int	number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	number_of_times_each_philosopher_must_eat;
}			t_init_cond;

/* utils.c */
size_t		ft_strlen(const char *s);
int			ft_isdigit(const int c);
int			ft_isalldigit(const char *str);
int			ft_isspace(const int c);
int			ft_atoi(const char *str);

/* error_handler.c */
void		input_errors(t_arguments argument_type);

/* input_control.c */
int			is_out_of_range(char *num, char *range, t_arguments argument);
int			is_input_correct(int argc, char **argv);
t_init_cond	parse_input(int argc, char **argv);

/* philosophers.c */
int			main(int argc, char **argv);

#endif /* PHILOSOPHERS_H */
