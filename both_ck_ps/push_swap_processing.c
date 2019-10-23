/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:52:39 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/23 12:31:52 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The algorithm starts here: we send all the numbers exept of three of them to
** the stack_b. After we sort 3 left numbers in stack_a.
*/

void			count_operations(t_push *push)
{
	int			three;
	
	three = push->total + 1;
	while (--three > 3)
	{
		pb(push);
		ft_putendl("pb");
	}
	push->total_a = three;
	push->total_b = (push->total - three > 0) ? push->total - three : 0;
	(three == 3) ? sort_three_nums_2_cases(push) : 0;
	if (three == 2 && push->start_a->n > push->start_a->next->n)
	{
		sa(push);
		ft_putendl("sa");
	}
	while (push->start_b)
		find_operation_todo(push);
	(check_if_sorted(push) == -1) ? check_and_finish_sort(push) : 0;
}

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

/*
** Here we are looking for the best options: which b stack on which a stack to put
** and perform the best operation found
*/

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

int				check_if_sorted(t_push *push)
{
	t_stack		*tmp;

	if (push->start_b)
		return (-1);
	tmp = push->start_a;
	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}