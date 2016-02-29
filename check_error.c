/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 19:29:20 by adubedat          #+#    #+#             */
/*   Updated: 2016/02/29 19:42:43 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input_error(int argc, char **argv, int i)
{
	int	j;

	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' && j == 0) || (argv[i][j] >= '0' &&
				argv[i][j] <= '9'))
				j++;
			else
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
		}
		i++;
	}
}
