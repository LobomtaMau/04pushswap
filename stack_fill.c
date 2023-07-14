/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:38:10 by mbaptist          #+#    #+#             */
/*   Updated: 2023/07/14 16:37:35 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_fill (t_stack_node **a, char **argv, bool flag_ac2)
{
    long nbr;
    int i;

    i = 0;
    while (argv[i])
    {
        if (error_syntax(argv[i]))
            error_msg(a, argv, flag_ac2);
        nbr = ft_atol(argv[i]);
        if( nbr > INT_MAX || nbr < INT_MIN)
            error_msg(a, argv, flag_ac2);
        if (error_repetition(*a, (int)nbr))
            error_msg(a, argv, flag_ac2);
        stack_create(a, (int)nbr);
        i++;
    }
    if(flag_ac2)
        free_args(argv);
}

void stack_create(t_stack_node **stack, int nbr)
{
    t_stack_node *node;
    t_stack_node *last_node;

    if (!stack)
        return ;
    node = malloc(sizeof(t_stack_node));
    if(!node)
        return;
    node->next = NULL;
    node->value = nbr;
    if (*stack == NULL)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

t_stack_node *find_last_node(t_stack_node *top)
{
    if (!top)
        return (NULL);
    while (top->next)
        top = top->next;
    return (top);
}

int	stack_len(t_stack_node *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack_node	*find_small(t_stack_node *stack)
{
	long			small;
	t_stack_node	*small_node;

	if (!stack)
		return (NULL);
	small = LONG_MAX;
	while (stack)
	{
		if (stack->value < small)
		{
			small = stack->value;
			small_node = stack;
		}
		stack = stack->next;
	}
	return (small_node);
}
