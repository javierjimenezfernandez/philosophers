/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:44:11 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/28 19:05:16 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>

# ifndef MAX_THREADS
#  define MAX_THREADS 200
# endif /* MAX_THREADS */
/* max for usleep = 1000000 in us, which is 1000 in ms. source: man usleep */
# define MAX_MSECONDS 1000
# define MAX_UNSIGNEDINT 4294967295
# define MAX_UINT_LENGHT 11
# define HAS_TAKEN_A_FORK "has taken a fork"
# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define DIED "died"
# define GETTIMEOFDAY_E "gettimeofday() error\n"
# define PTHREAD_CREATE_E "pthread_create() error\n"
# define PTHREAD_JOIN_E "pthread_join() error\n"
# define INIT_TIMES_EAT_ZERO ""

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
	bool			is_eating;
	bool			*is_dead;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*last_meal_lock;
	pthread_mutex_t	*is_dead_lock;
}			t_philo;

typedef struct s_main_data_struct
{
	bool			dead_philo_flag;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	last_meal_lock;
	pthread_mutex_t	is_dead_lock;
	t_philo			*philo_array;
}			t_main_data_struct;

/* ft_utils.c */
size_t			ft_strlen(const char *s);
bool			ft_isalldigit(const char *str);
size_t			ft_uintlen(unsigned int n);
unsigned int	ft_atoui(const char *str);
char			*ft_uitoa(unsigned int n, char *str);

/* time_utils.c */
time_t			gettime_in_ms(void);
int				accurate_msleep(time_t ms);

/* print_utils.c */
void			log_fd(int fd, const char *log_info);
void			print_state(char *str, t_philo *philo);
void			print_philo(const t_philo *philo);
void			print_all_philos(const t_philo *philo_array);

/* error_handler.c */
void			wrong_usage(void);
void			init_times_must_eat_is_zero(void);
void			destroy_all_mutexes(
					const char *log_info,
					t_main_data_struct *main_data,
					pthread_mutex_t *fork_array);

/* input_control.c */
bool			is_out_of_range(char *num, char *range, t_arguments argument);
bool			is_input_correct(int argc, char **argv);
t_init_cond		parse_input(int argc, char **argv);

/* init.c */
void			init_main_data_struct(
					t_main_data_struct *main_data,
					t_philo *philo_array);
void			init_forks(
					unsigned int num_of_philos,
					pthread_mutex_t *fork_array);
void			assign_forks(
					t_philo *philo_array,
					pthread_mutex_t *fork_array,
					unsigned int i);
void			init_philos(
					t_init_cond init_cond,
					t_main_data_struct *main_data,
					t_philo *philo_array,
					pthread_mutex_t *fork_array);

/* watcher.c */
bool			is_dead(t_philo *philo);
bool			is_time_to_die(t_philo *philo);
bool			philo_just_died(t_philo *philo_array);
bool			nobody_is_hungry(t_philo *philo_array);
void			*watcher(void *ptr);

/* philo_actions.c */
void			to_think(t_philo *philo);
void			to_sleep(t_philo *philo);
void			lock_forks(t_philo *philo);
void			to_eat(t_philo *philo);
void			*philo_actions(void *ptr);

/* threads_create.c */
void			threads_create(
					t_main_data_struct *main_data,
					t_philo *philo_array,
					pthread_mutex_t *fork_array);

/* philosophers.c */
void			philosophize(t_init_cond init_cond);
int				main(int argc, char **argv);

#endif /* PHILOSOPHERS_H */
