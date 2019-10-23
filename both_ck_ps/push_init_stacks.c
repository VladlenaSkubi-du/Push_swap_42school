/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_init_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:16:14 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/22 11:05:01 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_to_stack_a(t_push *push, int n)
{
	static t_stack	*run;

	if (push->total == 0)
	{
		run = init_stack();
		push->start_a = run;
	}
	else
	{
		run->next = init_stack();
		run = run->next;
	}
	run->n = n;
}

void				push_to_stack_b(t_push *push, int n)
{
	static t_stack	*run;

	if (push->total == 0)
	{
		run = init_stack();
		push->start_b = run;
	}
	else
	{
		run->next = init_stack();
		run = run->next;
	}
	run->n = n;
}
