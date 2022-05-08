/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:38:45 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/11/03 02:15:50 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_PUSH_SWAP_H
# define  H_PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_num
{
	int				num;
}				t_num;

void	swap(t_list *stk);
void	swap_ss(t_list *stk_a, t_list *stk_b);
void	push(t_list **stk_dst, t_list **stk_src);
void	rotate(t_list **stk);
void	rotate_rr(t_list **stk_a, t_list **stk_b);
void	reverse(t_list **stk);
void	reverse_rr(t_list **stk_a, t_list **stk_b);
void	operator_commands(t_list **stk_a, t_list **stk_b, char *command);
void	num_lst(t_list *stk, int *num);
void	no_rep(t_list *stk);
t_list	*init_stk(int ar, char **ars);
int		ft_atoi_modified(const char *str);
void	sorter(t_list *stk);
void	two_size(t_list *stk, int *num);
void	three_size(t_list **stk, int *num);
void	five_size(t_list **stk_a, int *num);
int		search_small(int *num, int size);
void	chunks(t_list **stk_a, int *num);
void	chunks_workout(t_list **stk_a, t_list **stk_b, int *num, int chnum);
int		hold(int *chunk, int *num, int stk_size, int chnum);
void	chunks_back(t_list **stk_a, t_list **stk_b);
void	moving_n_pushing_a(t_list **stk, int i);
void	moving_n_pushing_b(t_list **stk, int i);
int		they_rigth(int *num, int size);
void	patcher(t_list **stk_a, t_list **stk_b, int *num, int size);
void	clean_lst(void *cont);
void	error(void);
void	malloc_fail(void);

#endif
