/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:40:53 by sschmele          #+#    #+#             */
/*   Updated: 2019/10/23 12:37:56 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "ft_printf.h"

# define INT_MAX (2147483647)
# define INT_MIN (-2147483648)

typedef	struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_push
{
	t_stack			*start_a;
	t_stack			*start_b;
	int				total;
	int				total_a;
	int				total_b;
	int				min;
	int				max;
}					t_push;

typedef struct		s_rotate
{
	int				ra_a;
	int				rb_b;
	int				rra_a;
	int				rrb_b;
}					t_rotate;

/*
** ------------------------------- Common functions ---------------------------
*/

/*
** String check in file - check_string_argv.c
*/

int					invalid_argv(char *argv, t_push *push);
int					atoi_push_swap(char *str, char **nums, t_push *push);
void				check_duplicate(char **nums, t_push *push);

/*
** Malloc and free for t_push and t_stack and other structures
** in file - other_functions.c
*/

void				*ft_xmalloc(size_t size);
t_push				*init_push(void);
t_stack				*init_stack(void);
void				free_stack(t_stack *start);
void				free_push(t_push *push);

/*
** Initiation and push of numbers to stacks a and b
** in file - push_init_stacks.c
*/

void				push_to_stack_a(t_push *push, int n);
void				push_to_stack_b(t_push *push, int n);

/*
** Operations in the project - files operations_p.c,
** operations_r.c, operations_rr.c, operations_s.c
*/

void				sa(t_push *push);
void				sb(t_push *push);
void				ss(t_push *push);

void				pa(t_push *push);
void				pb(t_push *push);

void				ra(t_push *push);
void				rb(t_push *push);
void				rr(t_push *push);

void				rra(t_push *push);
void				rrb(t_push *push);
void				rrr(t_push *push);

/*
** Answers that programs can give: "Error", "KO", "OK" - for checker
*/

void				error_exit(char **nums, t_push *push);
void				error_operations(char *str, t_push *push);
void				ko(t_push *push);
void				ok(t_push *push);

/*
** ----------------------------- Checker part ---------------------------------
*/

/*
** Checking if user inputs operations listed -
** in file - check_stdin_operations.c
*/

void				check_stdin(t_push *push, char *str);
void				check_after_stdin(t_push *push);

/*
** ---------------------------- Push_swap part --------------------------------
*/

/*
** Algorithm starts here -
** in file - push_swap_processing.c
*/

void				count_operations(t_push *push);
void				sort_three_nums_2_cases(t_push *push);
void				sort_three_nums_other_cases(t_push *push,
						int up, int mid, int down);
void				find_operation_todo(t_push *push);
int					check_if_sorted(t_push *push);

/*
** Stack_a - searching the right element to put a b-stack element on -
** in file - investigations_in_a_stack.c
*/

t_stack				*find_best_a(t_push *push, int b_elem);
t_stack				*put_on_minimal_a(t_push *push, t_stack *best_a);
void				choose_best_move(t_push *push,
						t_stack **a_stack_to_put, t_stack **b_stack_to_move);

/*
** Rotations - all the functions where we check or use rotations -
** in file rotations.c
*/

t_rotate        	*init_rotate(t_push *push, int a, int b);
int					number_operations(t_push *push,
						t_stack *tmp_a, t_stack *tmp_b);
void				move_chosen_way(t_push *push,
						t_stack *a_stack_to_put, t_stack *b_stack_to_move);
int					count_r_rr(t_stack *start,
						int best, int max, int flag);
void				check_and_finish_sort(t_push *push);

/*
**Just to see some steps - in file print_for_convenience.c
*/

void				print_push(t_push *push);
void				output_check(t_push *push);

#endif
