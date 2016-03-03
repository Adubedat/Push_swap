/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 22:07:51 by adubedat          #+#    #+#             */
/*   Updated: 2016/02/29 23:05:24 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	swap_a(t_data data)
{
	int	temp;

	temp = ELEM_A_1;
	ELEM_A_1 = ELEM_A_2;
	ELEM_A_2 = temp;
    data.count++;
    if (data.color == 1)
        ft_printf(BLUE);
    if (data.print_piles == 0)
        ft_printf("sa ");
    else
        print_piles(data, "sa");
    ft_printf(WHITE);
	return (data);
}

t_data	swap_b(t_data data)
{
	int	temp;

	temp = ELEM_B_1;
	ELEM_B_1 = ELEM_B_2;
	ELEM_B_2 = temp;
    data.count++;
    if (data.color == 1)
        ft_printf(BLUE);
    if (data.print_piles == 0)
        ft_printf("sb ");
    else
        print_piles(data, "sb");
    ft_printf(WHITE);
	return (data);
}

t_data	push_b(t_data data)
{
	ELEM_B = ELEM_A_1;
	data.a_elem_nbr -= 1;
	data.b_elem_nbr += 1;
    data.count++;
    if (data.color == 1)
        ft_printf(CYAN);
    if (data.print_piles == 0)
        ft_printf("pb ");
    else
        print_piles(data, "pb");
    ft_printf(WHITE);
	return (data);
}

t_data	push_a(t_data data)
{
	ELEM_A = ELEM_B_1;
	data.b_elem_nbr -= 1;
	data.a_elem_nbr += 1;
    data.count++;
    if (data.color == 1)
        ft_printf(YELLOW);
    if (data.print_piles == 0)
        ft_printf("pa ");
    else
        print_piles(data, "pa");
    ft_printf(WHITE);
	return (data);
}
