/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:52:39 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 21:25:39 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The algorithm continues here: there are five cases to sort.
** 2 1 3 -> sa;
** 3 2 1 -> sa -> 2 3 1 -> rra
** 3 1 2 -> ra;
** 1 3 2 -> sa -> 3 1 2 -> ra
** 2 3 1 -> rra
*/

void			sort_three_nums_2_cases(t_push *push)
{
	int			up;
	int			mid;
	int			down;

	up = push->start_a->n;
	mid = push->start_a->next->n;
	down = push->start_a->next->next->n;
	if (up < mid && mid < down)
		return ;
	if (up > mid && up < down)
	{
		sa(push);
		ft_putendl("sa");
	}
	else if (up > mid && mid > down)
	{
		sa(push);
		rra(push);
		ft_putendl("sa\nrra");
	}
	else
		sort_three_nums_other_cases(push, up, mid, down);
}

void			sort_three_nums_other_cases(t_push *push,
					int up, int mid, int down)
{
	if (up > mid && mid < down)
	{
		ra(push);
		ft_putendl("ra");
	}
	else if (up < down && mid > down)
	{
		sa(push);
		ra(push);
		ft_putendl("sa\nra");
	}
	else if (up < mid && down < up)
	{
		rra(push);
		ft_putendl("rra");
	}
}

void			find_operation_todo(t_push *push)
{
	t_stack		*a_stack_to_put;
	t_stack		*b_stack_to_move;

	a_stack_to_put = push->start_a;
	b_stack_to_move = push->start_b;
	while (push->start_b)
	{
		choose_best_move(push, &(a_stack_to_put), &(b_stack_to_move));
		move_chosen_way(push, a_stack_to_put, b_stack_to_move);
		push->total_a++;
		push->total_b--;
	}
}

void			move_chosen_way(t_push *push,
					t_stack *a_stack_to_put, t_stack *b_stack_to_move)
{
	int			ra_a;
	int			rra_a;
	int			rb_b;
	int			rrb_b;
	int			t;

	ra_a = count_r_rr(push->start_a, a_stack_to_put->n, 0, 0);
	rra_a = count_r_rr(push->start_a, a_stack_to_put->n, push->total_a, 1);
	t = (ra_a <= rra_a) ? ra_a + 1 : rra_a + 1;
	while (--t)
	{
		(ra_a <= rra_a) ? ra(push) : rra(push);
		ft_putendl((ra_a <= rra_a) ? "ra" : "rra");
	}
	rb_b = count_r_rr(push->start_b, b_stack_to_move->n, 0, 0);
	rrb_b = count_r_rr(push->start_b, b_stack_to_move->n, push->total_b, 1);
	t = (rb_b <= rrb_b) ? rb_b + 1 : rrb_b + 1;
	while (--t)
	{
		(rb_b <= rrb_b) ? rb(push) : rrb(push);
		ft_putendl((rb_b <= rrb_b) ? "rb" : "rrb");
	}
	pa(push);
	ft_putendl("pa");
}

void			check_and_finish_sort(t_push *push)
{
	int			ra_a;
	int			rra_a;
	int			t;

	ra_a = count_r_rr(push->start_a, push->min, 0, 0);
	rra_a = count_r_rr(push->start_a, push->min, push->total_a, 1);
	t = (ra_a <= rra_a) ? ra_a + 1 : rra_a + 1;
	while (--t)
	{
		(ra_a <= rra_a) ? ra(push) : rra(push);
		ft_putendl((ra_a <= rra_a) ? "ra" : "rra");
	}
}
