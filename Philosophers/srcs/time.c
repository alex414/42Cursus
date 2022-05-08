/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:17:41 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/04/09 20:52:29 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Kant.h"

/*https://stackoverflow.com/questions/9407556/why-are-both-tv-sec-and-tv-usec
-significant-in-determining-the-duration-of-a-tim*/
long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * (uint64_t)1000 + t.tv_usec / (uint64_t)1000);
}

long	diff_time(unsigned long t1, unsigned long t2)
{
	unsigned long	t3;

	t3 = t2 - t1;
	return (t3);
}

void	sleeep(long time, t_data *data)
{
	unsigned long	i;

	i = get_time();
	while (!(data->die))
	{
		if (diff_time(i, get_time()) >= time)
			break ;
		usleep(data->params[0]);
	}
}

void	*main_loop(void *philo)
{
	t_philo	*p;
	t_data	*data;

	p = (t_philo *)philo;
	data = p->data;
	if (p->id % 2 == 0)
		usleep(100);
	else
		usleep(data->params[0] * 10);
	while (data->die != TRUE)
	{
		if (data->all_ate == TRUE)
			break ;
		philo_eats(p);
		print_log("is sleeping", p->id, data);
		sleeep(data->params[3], data);
		print_log("is thinking", p->id, data);
	}
	return (NULL);
}
