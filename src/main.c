/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:48:36 by mbaptist          #+#    #+#             */
/*   Updated: 2023/07/21 15:57:03 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;
    if (argc == 1)
        return (1);
    if (argc == 2 && !argv[1][0])
        error_msg(&a);
    stack_start(&a, argv + 1);
    if(!is_sorted(a))
    {
        if(stack_len(a) == 2)
            sa(&a);
        else if(stack_len(a) == 3)
            sort_3(&a);
        else
            push_swap(&a, &b);
    }
    free_stack(&a);
}
