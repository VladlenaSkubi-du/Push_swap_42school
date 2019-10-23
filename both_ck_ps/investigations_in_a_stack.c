/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   investigations_in_a_stack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:03:52 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/23 12:28:13 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** For each b stack we are looking for the best a stack (minimal a in general or
** with the smallest differance between numbers) and than count operations.
** Finally we get one a stack and one b stack
*/

void			choose_best_move(t_push *push, t_stack **a_stack_to_put,
					t_stack **b_stack_to_move)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	int			num_op;
	int			t;

	tmp_a = push->start_a;
	tmp_b = push->start_b;
	num_op = push->total;
	while (tmp_b)
	{
		tmp_a = find_best_a(push, tmp_b->n);
		if ((t = number_operations(push, tmp_a, tmp_b)) < num_op)
		{
			num_op = t;
			*b_stack_to_move = tmp_b;
			*a_stack_to_put = tmp_a;
		}
		tmp_b = tmp_b->next;
	}
}

t_stack			*find_best_a(t_push *push, int b_elem)
{
	t_stack		*tmp_a;
	t_stack		*best_a;
	int			diff;

	tmp_a = push->start_a;
	best_a = NULL;
	diff = INT_MAX;
	while (tmp_a)
	{
		if (tmp_a->n > b_elem && (tmp_a->n - b_elem < diff))
		{
			diff = tmp_a->n - b_elem;
			best_a = tmp_a;
		}
		tmp_a = tmp_a->next;
	}
	best_a = (best_a == NULL) ? put_on_minimal_a(push, best_a) : best_a;
	return (best_a);
}

t_stack			*put_on_minimal_a(t_push *push, t_stack *best_a)
{
	t_stack		*tmp_a;
	int			min_a;

	tmp_a = push->start_a;
	min_a = INT_MAX;
	while (tmp_a)
	{
		if (min_a > tmp_a->n)
		{
			min_a = tmp_a->n;
			best_a = tmp_a;
		}
		tmp_a = tmp_a->next;
	}
	return (best_a);
}