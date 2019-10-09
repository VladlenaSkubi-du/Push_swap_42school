/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:16:14 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/02 12:47:22 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_to_stack_a(t_push *push, int n)
{
	static size_t	i = 0;

	if (i)
	{
		push->a->next = init_stack();
		push->a = push->a->next;
	}
	else
	{
		push->a = init_stack();
		push->start_a = push->a;
		i++;
	}
	push->a->n = n;
	push->a->next = NULL;
}

void				push_to_stack_b(t_push *push, int n)
{
	static size_t	i = 0;

	if (i)
	{
		push->b->next = init_stack();
		push->b = push->b->next;
	}
	else
	{
		push->b = init_stack();
		push->start_b = push->b;
		i++;
	}
	push->b->n = n;
	push->b->next = NULL;
}
