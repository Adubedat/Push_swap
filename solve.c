#include "push_swap.h"

t_data  check_min(t_data data)
{
    int i;

    data.min = data.a[0];
    data.direction = 0;
    i = 0;
    while (i < data.a_elem_nbr)
    {
        if (data.a[i] < data.min)
        {
            data.min = data.a[i];
            if ((i * 2) > data.a_elem_nbr)
                data.direction = 1;
            else
                data.direction = 0;
        }
        i++;
    }
    return (data);
}

t_data  solve_1(t_data data)
{
    while (issort(data) == 0)
    {
        data = check_min(data);
        if (data.direction == 1)
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

int     issort(t_data data)
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

t_data  solve_2(t_data data)
{
    while (issort(data) == 0)
    {
        if (ELEM_A_1 > ELEM_A_2 && ELEM_A_1 < data.a[0])
            data = swap_a(data);
        else if (ELEM_A_1 > data.a[0] && ELEM_A_1 > ELEM_A_2)
            data = rotate_a(data);
        else
            data = reverse_rotate_a(data);
    }
    return (data);
}
