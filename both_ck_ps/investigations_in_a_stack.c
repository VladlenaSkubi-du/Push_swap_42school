/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   investigations_in_a_stack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:03:52 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 19:32:09 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int				number_operations(t_push *push, t_stack *tmp_a, t_stack *tmp_b)
{
	int			num;
	int			r;
	int			rr;

	num = 0;
	r = count_r_rr(push->start_a, tmp_a->n, 0, 0);
	rr = count_r_rr(push->start_a, tmp_a->n, push->total_a, 1);
	if (r <= rr)
		num = r;
	else
		num = rr;
	r = count_r_rr(push->start_b, tmp_b->n, 0, 0);
	rr = count_r_rr(push->start_b, tmp_b->n, push->total_b, 1);
	if (r <= rr)
		num += r;
	else
		num += rr;
	num++;
	return (num);
}

int				count_r_rr(t_stack *start,
					int best, int max, int flag)
{
	int			res;
	t_stack		*tmp;

	res = 0;
	tmp = start;
	while (tmp && tmp->n != best)
	{
		res++;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (-1);
	return ((flag == 0) ? res : max - res);
}
