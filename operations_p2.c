/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 23:05:33 by adubedat          #+#    #+#             */
/*   Updated: 2016/02/29 23:22:19 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	rotate_a(t_data data)
{
	int j;
	int temp;

	j = data.a_elem_nbr - 1;
	while (j > 0)
	{
		temp = data.a[j];
		data.a[j] = data.a[j - 1];
		data.a[j - 1] = temp;
		j--;
	}
    data.count++;
    if (data.color == 1)
        ft_printf(RED);
    if (data.print_piles == 0)
        ft_printf("ra ");
    else
        print_piles(data, "ra");
    ft_printf(WHITE);
	return (data);
}

t_data	rotate_b(t_data data)
{
	int j;
	int temp;

	j = data.b_elem_nbr - 1;
	while (j > 0)
	{
		temp = data.b[j];
		data.b[j] = data.b[j - 1];
		data.b[j - 1] = temp;
		j--;
	}
    data.count++;
    if (data.color == 1)
        ft_printf(RED);
    if (data.print_piles == 0)
        ft_printf("rb ");
    else
        print_piles(data, "rb");
    ft_printf(WHITE);
	return (data);
}

t_data	reverse_rotate_a(t_data data)
{
	int i;
	int temp;

	i = 0;
	while (i < data.a_elem_nbr - 1)
	{
		temp = data.a[i];
		data.a[i] = data.a[i + 1];
		data.a[i + 1] = temp;
		i++;
	}
    data.count++;
    if (data.color == 1)
        ft_printf(PURPLE);
    if (data.print_piles == 0)
        ft_printf("rra ");
    else
        print_piles(data, "rra");
    ft_printf(WHITE);
	return (data);
}

t_data	reverse_rotate_b(t_data data)
{
	int i;
	int temp;

	i = 0;
	while (i < data.b_elem_nbr - 1)
	{
		temp = data.b[i];
		data.b[i] = data.b[i + 1];
		data.b[i + 1] = temp;
		i++;
	}
    data.count++;
    if (data.color == 1)
        ft_printf(RED);
    if (data.print_piles == 0)
        ft_printf("rrb ");
    else
        print_piles(data, "rrb");
    ft_printf(WHITE);
	return (data);
}
