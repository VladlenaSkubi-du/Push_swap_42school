/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:55:44 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 21:08:23 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

void			pa(t_push *push)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	if (!push->start_b)
		return ;
	tmp_b = push->start_b->next;
	tmp_a = init_stack();
	tmp_a->n = push->start_b->n;
	push->start_b->next = NULL;
	free(push->start_b);
	push->start_b = tmp_b;
	tmp_a->next = push->start_a;
	push->start_a = tmp_a;
}

/*
** push b - take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void			pb(t_push *push)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	if (!push->start_a)
		return ;
	tmp_a = push->start_a->next;
	tmp_b = init_stack();
	tmp_b->n = push->start_a->n;
	push->start_a->next = NULL;
	free(push->start_a);
	push->start_a = tmp_a;
	tmp_b->next = push->start_b;
	push->start_b = tmp_b;
}
