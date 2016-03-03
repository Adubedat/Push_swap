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
    if (data.operation_nbr == 1 && data.color == 1)
        ft_printf(BLUE"\nNombre d'opérations : %d"WHITE, data.count);
    else if (data.operation_nbr == 1)
        ft_printf("\nNombre d'opérations : %d", data.count);
    if (data.final_result == 1)
        print_final_result(data);
    if (data.list_options == 1)
    {
        ft_printf(GREEN"\nOptions disponibles :\n-i : Liste des options\n-o : "
            "Nombre d'operations\n-v : Afficher les piles pour chaque operatio"
            "n\n-c : Ajouter des couleurs\n-f : Afficher la pile finale"WHITE);
    }
    free(data.a);
    free(data.b);
	return (0);
}

t_data	init_data(t_data data)
{
	data.operation_nbr = 0;
    data.min = 0;
    data.count = 0;
	data.print_piles = 0;
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
		data.print_piles = 1;
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

	data = init_data(data);
	i = 1;
	data = check_bonus(argv, data, i);
	i = i + data.operation_nbr + data.print_piles + data.color
		+ data.final_result + data.list_options;
	data.a = (int*)malloc(sizeof(int) * argc - i);
	data.b = (int*)malloc(sizeof(int) * argc - i);
	data.elem_nbr = argc - i;
	data.a_elem_nbr = data.elem_nbr;
	data = get_piles(argc, argv, i, data);
    if (data.elem_nbr > 3)
        data = solve_1(data);
    else
        data = solve_2(data);
    ft_printf("%c", 8);
	return (data);
}
