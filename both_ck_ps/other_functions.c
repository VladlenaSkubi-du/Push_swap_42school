/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:52:16 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/22 11:01:04 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			*ft_xmalloc(size_t size)
{
	void		*ptr;

	if (!(ptr = malloc(size)))
	{
		write(2, "No space left\n", 15);
		exit(1);
	}
	ft_bzero(ptr, size);
	return (ptr);
}

t_push			*init_push(void)
{
	t_push		*push;

	push = (t_push *)ft_xmalloc(sizeof(t_push));
	push->start_a = NULL;
	push->start_b = NULL;
	push->total = 0;
	push->total_a = 0;
	push->total_b = 0;
	push->min = INT_MAX;
	push->max = INT_MIN;
	return (push);
}

t_stack			*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)ft_xmalloc(sizeof(t_stack));
	stack->next = NULL;
	stack->n = 0;
	return (stack);
}

void			free_stack(t_stack *start)
{
	t_stack		*tmp;
	t_stack		*store;

	if (start == NULL)
		return ;
	tmp = start;
	while (tmp)
	{
		store = tmp->next;
		free(tmp);
		tmp = store;
	}
}

void			free_push(t_push *push)
{
	free_stack(push->start_a);
	free_stack(push->start_b);
	free(push);
}
