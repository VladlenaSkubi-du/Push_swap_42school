/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:43:54 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/23 12:30:50 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv)
{
	int			i;
	t_push		*push;

	i = 0;
	push = init_push();
	if (argc > 1)
	{
		while (argv[i++] && i < argc)
			if (invalid_argv(argv[i], push) < 0)
			{
				free_push(push);
				return (1);
			}
		if (check_if_sorted(push) == -1)
			count_operations(push);
	}
	free_push(push);
	return (0);
}
