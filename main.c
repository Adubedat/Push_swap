/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:15:27 by adubedat          #+#    #+#             */
/*   Updated: 2016/02/29 23:22:21 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_data data;

	data = get_input(argc, argv);
	return (0);
}

t_data	init_data(t_data data)
{
	data.operation_nbr = 0;
	data.print_pile = 0;
	data.color = 0;
	data.final_result = 0;
	data.list_options = 0;
	data.b_elem_nbr = 0;
	return (data);
}

t_data	check_bonus(char **argv, t_data data, int i)
{
	if (!(argv[i]))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (ft_strcmp(argv[i], "-o") == 0)
	{
		data.operation_nbr = 1;
		return (check_bonus(argv, data, i + 1));
	}
	if (ft_strcmp(argv[i], "-v") == 0)
	{
		data.print_pile = 1;
		return (check_bonus(argv, data, i + 1));
	}
	if (ft_strcmp(argv[i], "-c") == 0)
	{
		data.color = 1;
		return (check_bonus(argv, data, i + 1));
	}
	data = check_bonus2(argv, data, i);
	return (data);
}

t_data	check_bonus2(char **argv, t_data data, int i)
{
	if (ft_strcmp(argv[i], "-f") == 0)
	{
		data.final_result = 1;
		return (check_bonus(argv, data, i + 1));
	}
	if (ft_strcmp(argv[i], "-i") == 0)
	{
		data.list_options = 1;
		return (check_bonus(argv, data, i + 1));
	}
	return (data);
}

t_data	get_input(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		j = 0;
	int		k = 0;

	data = init_data(data);
	i = 1;
	data = check_bonus(argv, data, i);
	i = i + data.operation_nbr + data.print_pile + data.color
		+ data.final_result + data.list_options;
	data.a = (int*)malloc(sizeof(int) * argc - i);
	data.b = (int*)malloc(sizeof(int) * argc - i);
	data.elem_nbr = argc - i;
	data.a_elem_nbr = data.elem_nbr;
	data = get_piles(argc, argv, i, data);
	data = push_b(data);
	data = push_b(data);
	data = push_b(data);
	data = push_a(data);
	data = reverse_rotate_a(data);
	ft_printf("Pile A : ");
	while (j < data.a_elem_nbr)
	{
		ft_printf("%d ", data.a[j]);
		j++;
	}
	ft_printf("\nPile B : ");
	while (k < data.b_elem_nbr)
	{
		ft_printf("%d ", data.b[k]);
		k++;
	}
	return (data);
}
