/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:43:54 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 21:26:01 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv)
{
	int			i;
	t_push		*push;

	i = 0;
	push = init_push();
	if (argc > 1)
	{
		while (argv[i++] && i < argc)
			if (invalid_argv(argv[i], push) < 0)
			{
				free_push(push);
				return (1);
			}
		if (check_if_sorted(push) == -1)
			count_operations(push);
	}
	free_push(push);
	return (0);
}

/*
** The algorithm starts here: we send all the numbers exept of three of them to
** the stack_b. After we sort 3 left numbers in stack_a.
*/

void			count_operations(t_push *push)
{
	int			three;
	t_stack		*tmp;

	tmp = push->start_a;
	while (tmp)
	{
		push->min = (tmp->n < push->min) ? tmp->n : push->min;
		push->max = (tmp->n > push->max) ? tmp->n : push->max;
		tmp = tmp->next;
	}
	three = push->total + 1;
	while (--three > 3)
	{
		pb(push);
		ft_putendl("pb");
	}
	push->total_a = three;
	push->total_b = (push->total - three > 0) ? push->total - three : 0;
	(three == 3) ? sort_three_nums_2_cases(push) : 0;
	(three == 2 && push->start_a->n > push->start_a->next->n) ? sa(push) : 0;
	while (push->start_b)
		find_operation_todo(push);
	(check_if_sorted(push) == -1) ? check_and_finish_sort(push) : 0;
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
