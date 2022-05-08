/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:30:33 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/04/09 20:28:45 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Kant.h"
/*para entenderlo */
void	philo_eats(t_philo *p)
{
	t_data	*data;

	data = p->data;
	pthread_mutex_lock(&data->fork[p->left_fork]);
	print_log("Left fork", p->id, data);
	pthread_mutex_lock(&data->fork[p->right_fork]);
	print_log("Right fork", p->id, data);
	print_log("Is eating 🍄 ", p->id, data);
	p->time_meal = get_time();
	p->has_ate += 1;
	sleeep(data->params[2], data);
	pthread_mutex_unlock(&data->fork[p->left_fork]);
	pthread_mutex_unlock(&data->fork[p->right_fork]);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	data;
	int		i;

	i = 0;
	if ((argc <= 4 || argc >= 7))
		return (1);
	data.params = parse_arguments(--argc, argv, i);
	if (init(&philo, &data, i))
		return (1);
	if (create_philos(philo, i))
		return (1);
	if (destroy_philo(philo, &data, i))
		return (1);
}
