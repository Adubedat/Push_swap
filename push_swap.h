/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:16:28 by adubedat          #+#    #+#             */
/*   Updated: 2016/02/29 19:36:51 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/includes/libft.h"

typedef struct	s_data
{
	int			*a;
	int			*b;
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
void			check_input_error(int argc, char **argv, int i);

#endif
