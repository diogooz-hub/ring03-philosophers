/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:19:40 by dpaco             #+#    #+#             */
/*   Updated: 2024/04/28 12:16:30 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/headers/libft.h"
# include "libft/headers/get_next_line.h"
# include "libft/headers/ft_printf.h"
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>

typedef struct s_philo
{
	int								id;
	int								last_meal;
	int								number_of_meals;
	unsigned int					time_to_die;
	unsigned int					time_to_sleep;
	unsigned int					time_to_eat;
	pthread_t						thread_id;
	pthread_mutex_t					*left_fork;
	pthread_mutex_t					*right_fork;
	struct s_data					*program;
}	t_philo;

typedef struct s_data
{
	int								number_of_philos;
	unsigned int					time_to_die;
	unsigned int					time_to_sleep;
	unsigned int					time_to_eat;
	int								number_of_meals;
	unsigned int					starting_time;
	int								philosopher_dead;
	int								all_full;
	pthread_mutex_t					mutex;
	pthread_mutex_t					*fork_mutex;
	t_philo							*philosopher;
}	t_data;

//checks
int					check_arguments(int ac, char **av);

//routine
void				begin_threads(t_data *program);
void				join_threads(t_data *program);

//actions
void				handle_one_philo(t_philo *philo);
int					philo_takes_fork(t_philo *philo);
void				philo_is_eating(t_philo *philo);
void				philo_is_sleeping(t_philo *philosopher);
void				philo_is_thinking(t_philo *philosopher);

//monitoring
void				monitoring(t_data *program);
int					stop_threds(t_philo *philo);

//utils
unsigned int		get_time(void);
void				ft_busy(unsigned int time);
void				free_program(t_data *program);
void				destroy_fork_mutexes(t_data *program);

//messages
void				message_from_philo(char *str, t_philo *philosopher);
void				message_from_monitoring(char *str, t_philo *philosopher);

#endif