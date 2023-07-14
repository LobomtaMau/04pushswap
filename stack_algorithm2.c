/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algorithm2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:09:54 by mbaptist          #+#    #+#             */
/*   Updated: 2023/07/14 16:23:43 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->position;
		if (!(b->above_med))
			b->push_price = len_b - (b->position);
		if (b->target_node->above_med)
			b->push_price += b->target_node->position;
		else
			b->push_price += len_a - (b->target_node->position);
		b = b->next;
	}
}

void	set_curr_position(t_stack_node *stack)
{
	int	i;
	int	midle;

	i = 0;
	if (!stack)
		return ;
	midle = stack_len(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= midle)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_nod(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_a;
	t_stack_node	*target_node;
	long			close_index;

	while (b)
	{
		close_index = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < close_index)
			{
				close_index = curr_a->value;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (LONG_MAX == close_index)
			b->target_node = find_small(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_cheap(t_stack_node *b)
{
	long			best_match;
	t_stack_node	*best_match_node;

	if (!b)
		return ;
	best_match = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match)
		{
			best_match = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheap = true;
}

void	start_nodes(t_stack_node *a, t_stack_node *b)
{
	set_curr_position(a);
	set_curr_position(b);
	set_target_nod(a, b);
	set_price(a, b);
	set_cheap(b);
}
