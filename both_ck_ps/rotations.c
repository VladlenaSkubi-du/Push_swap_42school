/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:33:59 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/23 12:31:56 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include  <stdio.h>

/*
** Just for the norm and for code to be easier
*/

t_rotate        *init_rotate(t_push *push, int a, int b)
{
    t_rotate    *rot;
    
    rot = (t_rotate *)ft_xmalloc(sizeof(t_rotate));
    rot->ra_a = count_r_rr(push->start_a, a, 0, 0);
    rot->rb_b = count_r_rr(push->start_b, b, 0, 0);
    rot->rra_a = count_r_rr(push->start_a, a, push->total_a, 1);
    rot->rrb_b = count_r_rr(push->start_b, b, push->total_b, 1);
    return (rot);
}

/*
** Count the nb of rotations needed: flag 0 - ra or rb,
** flag 1 - rra or rrb
*/

int				count_r_rr(t_stack *start,
					int best, int max, int flag)
{
	int			res;
	t_stack		*tmp;

	res = 0;
	tmp = start;
	while (tmp && tmp->n != best)
	{
		res++;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (-1);
	return ((flag == 0) ? res : max - res);
}

/*
** Counting final number of operations for exactly one b stack put on the 
** a stack that matches
*/

int				number_operations(t_push *push, t_stack *tmp_a, t_stack *tmp_b)
{
	int			num;
    t_rotate    *rot;

    rot = init_rotate(push, tmp_a->n, tmp_b->n);
    num = (rot->ra_a <= rot->rra_a) ? rot->ra_a : rot->rra_a;
    num += (rot->rb_b <= rot->rrb_b) ? rot->rb_b : rot->rrb_b;
	num++;
    free(rot);
	return (num);
}

/*
** Finally we chose b stack to be oved to some a stack, check the nb of rotations
** and perform movements
*/

void			move_chosen_way(t_push *push,
					t_stack *a_stack_to_put, t_stack *b_stack_to_move)
{
    
	int			t;
    t_rotate    *rot;
    
	rot = init_rotate(push, a_stack_to_put->n, b_stack_to_move->n);
    t = (rot->ra_a <= rot->rra_a) ? rot->ra_a + 1 : rot->rra_a + 1;
	while (--t)
	{
	    (rot->ra_a <= rot->rra_a) ? ra(push) : rra(push);
	    ft_putendl((rot->ra_a <= rot->rra_a) ? "ra" : "rra");
	}
    t = (rot->rb_b <= rot->rrb_b) ? rot->rb_b + 1 : rot->rrb_b + 1;
	while (--t)
	{
	    (rot->rb_b <= rot->rrb_b) ? rb(push) : rrb(push);
	    ft_putendl((rot->rb_b <= rot->rrb_b) ? "rb" : "rrb");
	}
	pa(push);
	ft_putendl("pa");
	free(rot);
}

/*
** During the algorithm if all the numbers in a stack are smaller than one in b stack
** to be moved, it is put on the smallest stack in a stack. If such operation was done
** in the end we will have in a stack:
** ------
** -------
** ------------ 				(the biggest stack)
** -- 							(lies on the smallest stack)
** -----
** So we need to make final rotations to sort everything till the end
*/

void			check_and_finish_sort(t_push *push)
{
	int			ra_a;
	int			rra_a;
	int			t;
	t_stack		*tmp;

	tmp = push->start_a;
	while (tmp)
	{
		push->min = (tmp->n < push->min) ? tmp->n : push->min;
		push->max = (tmp->n > push->max) ? tmp->n : push->max;
		tmp = tmp->next;
	}
	ra_a = count_r_rr(push->start_a, push->min, 0, 0);
	rra_a = count_r_rr(push->start_a, push->min, push->total_a, 1);
	t = (ra_a <= rra_a) ? ra_a + 1 : rra_a + 1;
	while (--t)
	{
		(ra_a <= rra_a) ? ra(push) : rra(push);
		ft_putendl((ra_a <= rra_a) ? "ra" : "rra");
	}
}