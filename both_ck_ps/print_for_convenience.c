/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_for_convenience.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:09:37 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 19:27:47 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_push(t_push *push)
{
	t_stack		*tmp;

	tmp = push->start_a;
	ft_printf("\nSTART\n");
	ft_printf("STACK_A\n");
	while (tmp)
	{
		ft_printf("%8d\n", tmp->n);
		tmp = tmp->next;
	}
	ft_printf("\nSTACK_B\n");
	tmp = push->start_b;
	while (tmp)
	{
		ft_printf("%8d\n", tmp->n);
		tmp = tmp->next;
	}
	ft_printf("FINISH\n");
}

void			output_check(t_push *push)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	tmp_a = push->start_a;
	tmp_b = push->start_b;
	ft_printf("_____A_____|_____B_____\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
			ft_printf("%6d", tmp_a->n);
		else
			ft_printf("%6c", '^');
		ft_printf("%6c", '|');
		if (tmp_b)
			ft_printf("%6d", tmp_b->n);
		else
			ft_printf("%6c", '^');
		ft_printf("%6c%c", '|', '\n');
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
}
