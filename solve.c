/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:33:00 by adubedat          #+#    #+#             */
/*   Updated: 2016/03/07 15:35:19 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	check_min(t_data data)
{
	int i;

	data.min = data.a[0];
	data.direction = 1;
	i = 0;
	while (i < data.a_elem_nbr)
	{
		if (data.a[i] < data.min)
		{
			data.min = data.a[i];
			if (i < (data.a_elem_nbr / 2))
				data.direction = 1;
			else
				data.direction = 0;
		}
		i++;
	}
	return (data);
}

t_data	solve_1(t_data data)
{
	while (issort(data) == 0)
	{
		data = check_min(data);
		if (data.direction == 0)
		{
			while (ELEM_A_1 != data.min)
				data = rotate_a(data);
		}
		else
		{
			while (ELEM_A_1 != data.min)
				data = reverse_rotate_a(data);
		}
		if (issort(data) != 1)
			data = push_b(data);
	}
	while (data.b_elem_nbr > 0)
		data = push_a(data);
	return (data);
}

int		issort(t_data data)
{
	int i;

	i = 0;
	while (i < data.a_elem_nbr - 1)
	{
		if (data.a[i] < data.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_data	solve_2(t_data data)
{
	while (issort(data) == 0)
	{
		if (ELEM_A_1 > data.a[0] && ELEM_A_1 > ELEM_A_2)
			data = rotate_a(data);
		else if (ELEM_A_2 > ELEM_A_1 && ELEM_A_2 > data.a[0])
			data = reverse_rotate_a(data);
		else
			data = swap_a(data);
	}
	return (data);
}
