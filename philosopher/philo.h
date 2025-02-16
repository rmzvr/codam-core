/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:38:35 by rzvir             #+#    #+#             */
/*   Updated: 2025/02/16 18:59:32 by rmzvr            ###   ########.fr       */
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
// !
# include <errno.h>
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
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				number_of_meals;
	uint32_t		seat;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint32_t		*is_someone_dead;
	uint64_t		last_meal_time;
	int64_t			*dinner_start_time;
	pthread_mutex_t	*startMutex;
	pthread_mutex_t	*deathMutex;
	pthread_mutex_t	*mealMutex;
	pthread_mutex_t	*printMutex;
}	t_philosopher;
typedef struct s_table
{
	int64_t			dinner_start_time;
	uint32_t		is_someone_dead;
	size_t			number_of_philosophers;
	size_t			number_of_meals;
	pthread_mutex_t	startMutex;
	pthread_mutex_t	deathMutex;
	pthread_mutex_t	printMutex;
	pthread_mutex_t	mealMutex;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
}	t_table;

size_t		ft_nbrlen(int n);
size_t		ft_strlen(const char *s);
uint32_t	ft_atoui(const char *nptr);
uint64_t	ft_atoul(const char *nptr);

int			show_help(void);
int			show_error(int code);

int			is_invalid_argument(char *argument);
int			validate_arguments(int argc, char **argv);

int			show_malloc_error(int code);
int			handle_mutex_error(int code, t_mutex_action action);
int			handle_thread_error(int code, t_thread_action action);
#endif