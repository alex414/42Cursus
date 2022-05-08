/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:30:11 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/04/07 12:36:46 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Kant.h"

void	destroy_all(t_philo *philo, t_data *data)
{
	pthread_mutex_destroy(&philo->data->print_mutex);
	pthread_mutex_destroy(&philo->data->access_mutex);
	free(data->fork);
	free(data->params);
	free(philo);
}

int	destroy_philo(t_philo *philo, t_data *data, int i)
{
	i = 0;
	while (i < philo->data->params[0])
	{
		if (pthread_join(philo[i].th, NULL) != FALSE)
			return (1);
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	destroy_all(philo, data);
	return (0);
}
