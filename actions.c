/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:02:58 by dpaco             #+#    #+#             */
/*   Updated: 2024/04/26 19:48:04 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_takes_fork(t_philo *philo)
{
	pthread_mutex_t *first_fork;
	pthread_mutex_t	*second_fork;

    if ((philo->id % 2) == 0)
	{
        first_fork = philo->right_fork;
        second_fork = philo->left_fork;
    }
	else
	{
        first_fork = philo->left_fork;
        second_fork = philo->right_fork;
    }
    pthread_mutex_lock(first_fork);
    message_from_philo("has taken fork", philo);
    pthread_mutex_lock(second_fork);
    message_from_philo("has taken fork", philo);
}

void	philo_is_eating(t_philo *philo)
{
	message_from_philo("is eating", philo);
	pthread_mutex_lock(&philo->program->mutex);
	philo->last_meal = get_time() - philo->program->starting_time;
	philo->time_to_die = philo->last_meal + philo->program->time_to_die;
	pthread_mutex_unlock(&philo->program->mutex);
	ft_busy(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->number_of_meals > 0)
		philo->number_of_meals--;
}

void	philo_is_sleeping(t_philo *philo)
{
	message_from_philo("is sleeping", philo);
	ft_busy(philo->time_to_sleep);
}

void	philo_is_thinking(t_philo *philo)
{
	message_from_philo("is thinking", philo);
}