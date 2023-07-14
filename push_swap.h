/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:05:20 by mbaptist          #+#    #+#             */
/*   Updated: 2023/07/14 15:56:42 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h> // eliminar
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					position;
	int					push_price;
	bool				above_med;
	bool				cheap;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;

}						t_stack_node;

//Utils
char					**ft_split(char *str, char space);
long					ft_atol(const char *str);
int						stack_len(t_stack_node *stack);

//Criar Stacks
void					stack_fill(t_stack_node **a, char **argv,
							bool flag_ac2);
void					stack_create(t_stack_node **stack, int nbr);

//Manipular Stacks
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **a, t_stack_node **b, bool checker);
void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);

//Algoritmo
void					sort_3(t_stack_node **a);
void					sort_5(t_stack_node **a, t_stack_node **b);
void					push_swap(t_stack_node **a, t_stack_node **b);
void					finish_rotate(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);

//Algo2
t_stack_node			*find_last_node(t_stack_node *top);
t_stack_node			*find_small(t_stack_node *stack);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_curr_position(t_stack_node *stack);
void					set_cheap(t_stack_node *b);
void					start_nodes(t_stack_node *a, t_stack_node *b);
t_stack_node			*return_cheap(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);

//Erros
void					error_msg(t_stack_node **a, char **argv, bool flag_ac2);
int						error_repetition(t_stack_node *a, int nbr);
void					free_stack(t_stack_node **stack);
int						error_syntax(char *str_nbr);
void					free_args(char **argv);

#endif