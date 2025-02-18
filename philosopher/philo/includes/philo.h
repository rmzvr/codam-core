/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:38:35 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/18 15:55:52 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_action
{
	TAKE,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_action;

typedef enum e_mutex_action
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK
}	t_mutex_action;

typedef enum e_thread_action
{
	CREATE,
	JOIN
}	t_thread_action;

typedef struct s_philosopher
{
	size_t			seat;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			last_meal_time;
	int				number_of_meals;
	unsigned int	*is_someone_dead;
	long			*dinner_start_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*start_mutex;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*print_mutex;
}	t_philosopher;
typedef struct s_table
{
	long			dinner_start_time;
	unsigned int	is_someone_dead;
	int				number_of_meals;
	size_t			number_of_philosophers;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
}	t_table;

size_t	ft_nbrlen(int n);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
long	get_current_time_in_milliseconds(void);
int		show_help(void);
int		show_error(int code);
int		is_invalid_argument(char *argument);
int		validate_arguments(int argc, char **argv);
int		show_malloc_error(int code);
int		handle_mutex_error(int code, t_mutex_action action);
int		handle_thread_error(int code, t_thread_action action);
int		handle_mutex(pthread_mutex_t *mutex, t_mutex_action action);
int		handle_thread(pthread_t *thread, void *(*routine)(void *),
			void *arg, t_thread_action action);
int		initialize_philosopher(t_philosopher *philosopher, size_t seat,
			char **argv, t_table *table);
int		initialize_philosophers(t_table *table, char **argv);
int		initialize_table(t_table *table, char **argv);
int		waiter_routine(t_table *table);
int		deinitialize_table(t_table *table);
int		deinitialize_philosophers(t_table *table);
void	*philosopher_routine(void *arg);
int		action(t_action action, long dinner_start_time,
			t_philosopher *philosopher);
int		check_death(t_philosopher *philosopher);
int		is_philosopher_dead(t_philosopher *philosopher);
int		is_someone_dead(t_philosopher *philosophers,
			size_t number_of_philosophers);
void	get_forks(t_philosopher *philosopher,
			pthread_mutex_t *forks, size_t seat, size_t number_of_philosophers);
void	set_number_of_meals(t_table *table, char **argv);
#endif