/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printaparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:30:39 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/04/09 20:53:53 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Kant.h"

int	*parse_arguments(int num, char **argv, int i)
{
	int	*params;

	i = 1;
	params = (int *)malloc(sizeof(int) * num);
	if (!params)
		return ((int *)1);
	while (argv[i])
	{
		params[i - 1] = ft_atoi_parser(argv[i]);
		if (params[i - 1] < 0)
			return ((int *)1);
		if (!params[i - 1])
			return ((int *)1);
		if (params[i - 1] == 0)
			return ((int *)1);
		i++;
	}
	return (params);
}

void	print_log(char *str, int philo_number, t_data *data)
{
	unsigned long	j;

	j = 0;
	pthread_mutex_lock(&data->print_mutex);
	if (!data->die)
	{
		j = diff_time(data->time, get_time());
		printf("%ld", j);
		printf("%s", " ms Philo ");
		printf("%i", philo_number);
		printf(" %s \n", str);
	}
	pthread_mutex_unlock(&data->print_mutex);
}
