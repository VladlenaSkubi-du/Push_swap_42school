/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stdin_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:02:59 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/03 16:32:38 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			check_stdin(t_push *push, char *str)
{
	if (!ft_strcmp(str, "sa"))
		sa(push);
	else if (!ft_strcmp(str, "sb"))
		sb(push);
	else if (!ft_strcmp(str, "ss"))
		ss(push);
	else if (!ft_strcmp(str, "pa"))
		pa(push);
	else if (!ft_strcmp(str, "pb"))
		pb(push);
	else if (!ft_strcmp(str, "ra"))
		ra(push);
	else if (!ft_strcmp(str, "rb"))
		rb(push);
	else if (!ft_strcmp(str, "rr"))
		rr(push);
	else if (!ft_strcmp(str, "rra"))
		rra(push);
	else if (!ft_strcmp(str, "rrb"))
		rrb(push);
	else if (!ft_strcmp(str, "rrr"))
		rrr(push);
	else
		error_operations(str, push);
}

void			check_after_stdin(t_push *push)
{
	t_stack		*tmp;

	if (push->start_b)
		ko(push);
	tmp = push->start_a;
	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			ko(push);
		tmp = tmp->next;
	}
	ok(push);
}
