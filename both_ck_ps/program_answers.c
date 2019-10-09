/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_answers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:22:06 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/02 12:42:53 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			error_exit(char **nums, t_push *push)
{
	ft_putendl_fd("Error", 2);
	ft_arrdel(nums);
	free_push(push);
	exit(1);
}

void			error_operations(char *str, t_push *push)
{
	ft_putendl_fd("Error", 2);
	free(str);
	free_push(push);
	exit(1);
}

void			ko(t_push *push)
{
	ft_putendl("KO");
	free_push(push);
	exit(1);
}

void			ok(t_push *push)
{
	ft_putendl("OK");
	free_push(push);
	exit(1);
}
