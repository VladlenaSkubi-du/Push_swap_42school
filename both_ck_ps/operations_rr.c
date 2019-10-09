/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:00:15 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 17:55:57 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** reverse rotate a - shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

void			rra(t_push *push)
{
	t_stack		*tmp_a;
	t_stack		*start;

	if (!(push->start_a) || !(push->start_a->next))
		return ;
	tmp_a = push->start_a;
	start = push->start_a;
	while (tmp_a->next->next)
		tmp_a = tmp_a->next;
	push->start_a = tmp_a->next;
	push->start_a->next = start;
	tmp_a->next = NULL;
}

/*
** reverse rotate b - shift down all elements of stack b by 1.
** The last element becomes the first one.
*/

void			rrb(t_push *push)
{
	t_stack		*tmp_b;
	t_stack		*start;

	if (!(push->start_b) || !(push->start_b->next))
		return ;
	tmp_b = push->start_b;
	start = push->start_b;
	while (tmp_b->next->next)
		tmp_b = tmp_b->next;
	push->start_b = tmp_b->next;
	push->start_b->next = start;
	tmp_b->next = NULL;
}

/*
** rra and rrb at the same time.
*/

void			rrr(t_push *push)
{
	rra(push);
	rrb(push);
}
