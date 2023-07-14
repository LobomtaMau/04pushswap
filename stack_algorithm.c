/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:26:37 by mbaptist          #+#    #+#             */
/*   Updated: 2023/07/14 15:55:23 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack_node	*find_high(t_stack_node *stack)
{
	int				high;
	t_stack_node	*high_node;

	if (stack == NULL)
		return (NULL);
	high = INT_MIN;
	while (stack)
	{
		if (stack->value > high)
		{
			high = stack->value;
			high_node = stack;
		}
		stack = stack->next;
	}
	return (high_node);
}

t_stack_node	*return_cheap(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	sort_3(t_stack_node **a)
{
	t_stack_node	*high_node;

	high_node = find_high(*a);
	if (*a == high_node)
		ra(a, false);
	else if ((*a)->next == high_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_5(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		start_nodes(*a, *b);
		finish_rotate(a, find_small(*a), 'a');
		pb(b, a, false);
	}
}
