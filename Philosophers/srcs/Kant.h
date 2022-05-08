/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kant.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:34:30 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/04/09 20:41:45 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KANT_H
# define KANT_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct t_data
{
	int				all_ate;
	int				*params;
	int				die;
	unsigned long	time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	access_mutex;
}	t_data;

typedef struct t_philo
{
	pthread_t			th;
	int					id;
	int					has_ate;
	int					left_fork;
	int					right_fork;
	long				time_meal;
	t_data				*data;
}	t_philo;

int			ft_onephilo(void);
long		get_time(void);
int			ft_error(void);
int			ft_atoi_parser(const char *str);
int			create_philos(t_philo *philo, int i);
int			*parse_arguments(int num, char **argv, int i);
int			init(t_philo **philo, t_data *data, int i);
int			destroy_philo(t_philo *philo, t_data *data, int i);
void		print_log(char *str, int philo_nb, t_data *data);
long		diff_time(unsigned long t1, unsigned long t2);
void		sleeep(long time, t_data *data);
void		*main_loop(void *philo);
void		philo_eats(t_philo *p);
void		destroy_all(t_philo *philo, t_data *data);

#endif