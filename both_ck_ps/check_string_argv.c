/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string_argv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:20:59 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/04 20:50:33 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check if the string sent as arguments is invalid:
** "-5-", "--4", "+6+", just NULL, only spaces or tabs, other symbols than '-'
** or '+' or numbers, and that there are no duplications.
** Check for the maximal  integer is performed in atoi. If there are no errors,
** all the numbers are saved in the stack_a in the structure t_push.
** @nu - is where the final numbers as strings are saved.
*/

int				invalid_argv(char *argv, t_push *push)
{
	char		**nu;
	size_t		i;
	size_t		j;

	i = 0;
	nu = ft_strsplit(argv, ' ');
	if (nu[i] == NULL)
	{
		ft_arrdel(nu);
		return (-1);
	}
	while (nu[i])
	{
		j = -1;
		while (nu[i][++j])
			if (!((nu[i][j] >= '0' && nu[i][j] <= '9') ||
				(nu[i][j] == '-' && j == 0 && nu[i][j + 1]) ||
				(nu[i][j] == '+' && j == 0 && nu[i][j + 1])))
				error_exit(nu, push);
		push_to_stack_a(push, atoi_push_swap(nu[i++], nu, push));
		push->total++;
	}
	check_duplicate(nu, push);
	ft_arrdel(nu);
	return (0);
}

int				atoi_push_swap(char *str, char **nums, t_push *push)
{
	long long	res;
	int			sign;
	size_t		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
		if (sign * res > INT_MAX || sign * res < INT_MIN)
			error_exit(nums, push);
	}
	return (sign * res);
}

void			check_duplicate(char **nums, t_push *push)
{
	int			num;
	t_stack		*tmp_1;
	t_stack		*tmp_2;

	tmp_1 = push->start_a;
	while (tmp_1->next)
	{
		num = tmp_1->n;
		tmp_2 = tmp_1->next;
		while (tmp_2)
		{
			if (num == tmp_2->n)
				error_exit(nums, push);
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
}
