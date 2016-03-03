#include "push_swap.h"

void    print_final_result(t_data data)
{
    int i;

    i = data.a_elem_nbr - 1;
    if (data.color == 1)
        ft_printf(RED);
    ft_printf("\nRésultat final : ");
    while (i >= 0)
    {
        ft_printf("%d ", data.a[i]);
        i--;
    }
    ft_printf(WHITE);
}

void    print_piles(t_data data, char *str)
{
    int i;
    int j;

    i = data.a_elem_nbr - 1;
    j = data.b_elem_nbr - 1;
    ft_printf("%s :\n"WHITE"Pile A : ", str);
    while (i >= 0)
    {
        ft_printf("%d ", data.a[i]);
        i--;
    }
    ft_printf("\nPile B : ");
    while (j >= 0)
    {
        ft_printf("%d ", data.b[j]);
        j--;
    }
    ft_printf("\n");
}
