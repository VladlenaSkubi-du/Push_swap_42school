/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:43:25 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 20:08:41 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @push - consists of 2 t_stacks: a and b (if t_stacks there is a num and a
** pointer to teh next t_stack)
*/

int				main(int argc, char **argv)
{
	int			i;
	t_push		*push;
	char		*str;

	i = 0;
	push = init_push();
	if (argc > 1)
	{
		while (argv[++i] && i < argc)
			if (invalid_argv(argv[i], push) < 0)
			{
				free_push(push);
				return (1);
			}
		while (get_next_line(0, &str) > 0)
		{
			check_stdin(push, str);
			free(str);
			str = NULL;
		}
		check_after_stdin(push);
	}
	free_push(push);
	return (0);
}
