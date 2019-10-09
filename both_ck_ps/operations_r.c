/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:56:37 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 19:22:24 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotate a - shift up all elements of stack a by 1. The first element becomes
** the last one.
*/

void			ra(t_push *push)
{
	t_stack		*tmp_a;

	if (!(push->start_a) || !(push->start_a->next))
		return ;
	tmp_a = push->start_a;
	while (tmp_a->next)
		tmp_a = tmp_a->next;
	tmp_a->next = push->start_a;
	push->start_a = push->start_a->next;
	tmp_a->next->next = NULL;
}

/*
** rotate b - shift up all elements of stack b by 1. The first element becomes
** the last one.
*/

void			rb(t_push *push)
{
	t_stack		*tmp_b;

	if (!(push->start_b) || !(push->start_b->next))
		return ;
	tmp_b = push->start_b;
	while (tmp_b->next)
		tmp_b = tmp_b->next;
	tmp_b->next = push->start_b;
	push->start_b = push->start_b->next;
	tmp_b->next->next = NULL;
}

/*
** ra and rb at the same time.
*/

void			rr(t_push *push)
{
	ra(push);
	rb(push);
}
