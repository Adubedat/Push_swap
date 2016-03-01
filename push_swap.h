/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:16:28 by adubedat          #+#    #+#             */
/*   Updated: 2016/02/29 23:22:14 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define ELEM_A_1 data.a[data.a_elem_nbr - 1]
# define ELEM_A_2 data.a[data.a_elem_nbr - 2]
# define ELEM_B_1 data.b[data.b_elem_nbr - 1]
# define ELEM_B_2 data.b[data.b_elem_nbr - 2]
# define ELEM_A data.a[data.a_elem_nbr]
# define ELEM_B data.b[data.b_elem_nbr]
# include "libft/libft.h"

typedef struct	s_data
{
	int			*a;
	int			*b;
    int         min;
    int         count;
    int         direction;
	int			a_elem_nbr;
	int			b_elem_nbr;
	int			elem_nbr;
	int			operation_nbr;
	int			print_pile;
	int			color;
	int			final_result;
	int			list_options;
}				t_data;

t_data			init_data(t_data data);
t_data			check_bonus(char **argv, t_data data, int i);
t_data			check_bonus2(char **argv, t_data data, int i);
t_data			get_input(int argc, char **argv);
t_data			get_piles(int argc, char **argv, int i, t_data data);
void			check_input_error(int *a, int n, int k, int nbr);
int				ft_atoi_error(char *str);
t_data			swap_a(t_data data);
t_data			swap_b(t_data data);
t_data			push_b(t_data data);
t_data			push_a(t_data data);
t_data			rotate_a(t_data data);
t_data			rotate_b(t_data data);
t_data			reverse_rotate_a(t_data data);
t_data			reverse_rotate_b(t_data data);
t_data          solve_1(t_data data);
t_data          solve_2(t_data data);
t_data          check_min(t_data data);
int             issort(t_data data);

#endif
