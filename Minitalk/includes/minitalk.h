/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 00:36:34 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/06/27 19:56:17 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define BUFFSIZE 1001
# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	char		msg[BUFFSIZE];
	int			top_bit;
	int			top_byte;
	_Bool		all_receive;
	_Bool		buff_overflow;
}				t_stack;

t_stack			g_bitwise = {{0}, 1 << 6, 0, FALSE, FALSE};

void			error(char *str_error);
void			print_pid(void);
void			usage(void);

#endif
