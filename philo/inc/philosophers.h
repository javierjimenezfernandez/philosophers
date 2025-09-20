/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:44:11 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/20 21:09:46 by javjimen         ###   ########.fr       */
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
#  define MAX_THREADS 200
# endif /* MAX_THREADS */
/* max for usleep = 1000000. source: man usleep */
# define MAX_USECONDS 1000000
# define MAX_UNSIGNEDINT 4294967295
# define MAX_UINT_LENGHT 11

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

typedef struct s_philo
{
	unsigned int	n_of_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	num_times_must_eat;
	unsigned int	philo_id;
	time_t			init_timestamp;
	time_t			last_meal;
	unsigned int	meals_eaten;
	int				is_eating;
	int				*is_dead;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*time_to_die_lock;
	pthread_mutex_t	*kill_philo_lock;
}			t_philo;

typedef struct s_main_data_struct
{
	int				kill_philo_flag;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	time_to_die_lock;
	pthread_mutex_t	kill_philo_lock;
	t_philo			*philo_array;
}			t_main_data_struct;

/* utils.c */
size_t		ft_strlen(const char *s);
int			ft_isdigit(const int c);
int			ft_isalldigit(const char *str);
int			ft_isspace(const int c);
size_t		ft_uintlen(unsigned int n);

/* ft_atoi.c */
int			ft_atoi(const char *str);

/* ft_uitoa.c */
char		*ft_uitoa(unsigned int n, char *str);

/* time_utils.c */
time_t		gettime_in_ms(void);

/* error_handler.c */
void		log_fd(int fd, const char *log_info);
void		wrong_usage(void);
void		init_times_must_eat_is_zero(void);
void		destroy_all_mutexes(const char *log_info,
				t_main_data_struct *main_data, pthread_mutex_t *forks);

/* input_control.c */
int			is_out_of_range(char *num, char *range, t_arguments argument);
int			is_input_correct(int argc, char **argv);
t_init_cond	parse_input(int argc, char **argv);

/* init.c */
void		init_main_data_struct(t_main_data_struct *main_data,
				t_philo *philos);
void		init_forks(pthread_mutex_t *fork_array, unsigned int num_of_philos);
void		assign_forks(t_philo *philo_array, pthread_mutex_t *fork_array,
				unsigned int i);
void		init_philos(t_init_cond init_cond, t_philo *philo_array,
				t_main_data_struct *main_data, pthread_mutex_t *fork_array);

/* philosophers.c */
void		start_philosophing(t_init_cond init_cond);
int			main(int argc, char **argv);

#endif /* PHILOSOPHERS_H */
