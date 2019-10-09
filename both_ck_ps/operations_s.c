/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:55:04 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 19:27:33 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** swap a - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements.
*/

void		sa(t_push *push)
{
	int		tmp;

	if (!(push->start_a) || !(push->start_a->next))
		return ;
	tmp = push->start_a->next->n;
	push->start_a->next->n = push->start_a->n;
	push->start_a->n = tmp;
}

/*
** swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements.
*/

void		sb(t_push *push)
{
	int		tmp;

	if (!(push->start_b) || !(push->start_b->next))
		return ;
	tmp = push->start_b->next->n;
	push->start_b->next->n = push->start_b->n;
	push->start_b->n = tmp;
}

/*
** sa and sb at the same time.
*/

void		ss(t_push *push)
{
	sa(push);
	sb(push);
}
