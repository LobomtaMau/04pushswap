/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:22:49 by mbaptist          #+#    #+#             */
/*   Updated: 2023/07/14 15:54:14 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheap_node)
{
	while (*a != cheap_node->target_node && *b != cheap_node)
		rr(a, b, false);
	set_curr_position(*a);
	set_curr_position(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheap_node)
{
	while (*a != cheap_node->target_node && *b != cheap_node)
		rrr(a, b, false);
	set_curr_position(*a);
	set_curr_position(*b);
}

void	finish_rotate(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_med)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_med)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_node;

	cheap_node = return_cheap(*b);
	if (cheap_node->above_med
		&& cheap_node->target_node->above_med)
		rotate_both(a, b, cheap_node);
	else if (!(cheap_node->above_med) && !(cheap_node->target_node->above_med))
		rev_rotate_both(a, b, cheap_node);
	finish_rotate(b, cheap_node, 'b');
	finish_rotate(a, cheap_node->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*small;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_5(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	sort_3(a);
	while (*b)
	{
		start_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_curr_position(*a);
	small = find_small(*a);
	if (small->above_med)
		while (*a != small)
			ra(a, false);
	else
		while (*a != small)
			rra(a, false);
}
