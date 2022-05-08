/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:30:22 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/04/07 12:35:45 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Kant.h"

void	ft_initall(int i, t_philo *p, t_data *data)
{
		p[i].id = i + 1;
		p[i].data = data;
		p[i].has_ate = FALSE;
		data->all_ate = FALSE;
		data->die = FALSE;
}

int	ft_set_data(t_data *data)
{
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->params[0]);
	if (!data->fork)
		return (1);
	if (data->params[0] == 1)
		return ((int)ft_onephilo());
	if (pthread_mutex_init(&data->print_mutex, NULL)
		|| pthread_mutex_init(&data->access_mutex, NULL))
		return (1);
	return (0);
}

int	init(t_philo **philo, t_data *data, int i)
{
	t_philo	*p;

	p = *philo;
	i = 0;
	p = (t_philo *)malloc(sizeof(t_philo) * data->params[0]);
	if (!p)
		return (1);
	if (ft_set_data(data))
		return (1);
	while (i < data->params[0])
	{
		ft_initall(i, p, data);
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (1);
		p[i].left_fork = i;
		if (i == data->params[0] - 1)
			p[i].right_fork = FALSE;
		else
			p[i].right_fork = i + 1;
		i++;
	}
	*philo = p;
	return (0);
}
