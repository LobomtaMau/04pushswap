/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:48:36 by mbaptist          #+#    #+#             */
/*   Updated: 2023/07/14 16:14:32 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main (int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;
    if ((argc == 1) || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    stack_fill(&a, argv + 1, argc == 2);
    if(!stack_sorted(a))
    {
        if(stack_len(a) == 2)
            sa(&a, false);
        else if(stack_len(a) == 3)
            sort_3(&a);
        else
            push_swap(&a, &b);
    }
    free_stack(&a);
}

/*printf("Original argument: %s\n", argv[1]);
    int i = 0;
    while (argv[i])
    {
        printf("Word %d: %s\n", i, argv[i]);
        i++;
    }*/

/*printf("Stack created:\n");
    print_stack(a);*/

/*void print_stack(t_stack_node *stack)
{
    printf("Stack contents: ");
    while (stack != NULL)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}*/
