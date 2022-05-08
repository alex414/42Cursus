/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:13:23 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/04/09 20:53:43 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Kant.h"

void	check_all_eat(t_philo *philo, t_data *data, int i)
{
	i = 1;
	while (data->params[4] > 0 && i < data->params[0]
		&& philo[i].has_ate == data->params[4])
			i++;
	if (i == data->params[0])
		data->all_ate = TRUE;
}

void	death_checker(t_philo *philo, int i)
{
	t_data		*data;
	long		time;

	data = philo->data;
	while (!(data->all_ate))
	{
		i = 0;
		while (i < data->params[0] && data->die != TRUE)
		{
			pthread_mutex_lock(&data->access_mutex);
			time = diff_time(philo[i].time_meal, get_time());
			if (time >= data->params[1])
			{
				print_log("Died 🥀", philo[i].id, data);
				data->die = TRUE;
			}
			pthread_mutex_unlock(&data->access_mutex);
			usleep(100);
			i++;
		}
		if (data->die == TRUE)
			break ;
		check_all_eat(philo, data, i);
	}
}

int	create_philos(t_philo *philo, int i)
{
	i = 0;
	philo->data->time = get_time();
	while (i < philo->data->params[0])
	{
		if (pthread_create(&(philo[i].th), NULL,
				&main_loop, &(philo[i])) != 0)
			return (1);
		philo[i].time_meal = get_time();
		i++;
	}
	death_checker(philo, i);
	return (0);
}
