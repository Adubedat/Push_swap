/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 19:29:20 by adubedat          #+#    #+#             */
/*   Updated: 2016/02/29 22:40:54 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input_error(int *a, int n, int k, int nbr)
{
	int	i;

	i = nbr;
	while (i > k)
	{
		if (n == a[i])
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i--;
	}
}

int		ft_atoi_error(char *str)
{
	long	result;
	int		negative;
	int		i;

	result = 0;
	i = 0;
	negative = 0;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (negative == 1)
		result = -result;
	if (result > 2147483647 || result < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return ((int)result);
}

t_data	get_piles(int argc, char **argv, int i, t_data data)
{
	int	j;
	int	k;

	k = data.elem_nbr - 1;
	while (k >= 0)
	{
		j = 0;
		data.a[k] = ft_atoi_error(argv[i]);
		check_input_error(data.a, data.a[k], k, data.elem_nbr - 1);
		k--;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' && j == 0 && argv[i][j + 1] >= '0'
				&& argv[i][j + 1] <= '9') || (argv[i][j] >= '0'
				&& argv[i][j] <= '9'))
				j++;
			else
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
		}
		i++;
	}
	return (data);
}
