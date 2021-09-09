/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:03:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 16:13:45 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	sort_fivehundred(t_program *program, t_ilist **operations)
{
	
}

static void	sort_hundred(t_program *program, t_ilist **operations)
{
	
}

int	stack_check_three(int x[3], t_stack *stack)
{
	if (x[0] == stack->numbers[stack->top] &&
		x[1] == stack->numbers[stack->top - 1] &&
		x[2] == stack->numbers[stack->top - 2])
		return (1);
	return (0);
}

static void	sort_three(t_program *p, t_ilist **ops)
{
	if (p->count == 2 )
		sort_perform_operation(p, ops, OP_SA);
	else if (stack_check_three((int []){1, 2, 0}, p->a))
		sort_perform_operation(p, ops, OP_RRA);
	else if (stack_check_three((int []){2, 1, 0}, p->a))
	{
		sort_perform_operation(p, ops, OP_SA);
		sort_perform_operation(p, ops, OP_RRA);
	}
	else if (stack_check_three((int []){1, 0, 2}, p->a))
		sort_perform_operation(p, ops, OP_SA);
	else if (stack_check_three((int []){2, 0, 1}, p->a))
		sort_perform_operation(p, ops, OP_RA);
	else if (stack_check_three((int []){0, 2, 1}, p->a))
	{
		sort_perform_operation(p, ops, OP_RRA);
		sort_perform_operation(p, ops, OP_SA);
	}
}

static void	sort_five(t_program *p, t_ilist **ops)
{
	while (p->a->top > 2)
	{
		if (stack_get_top(p->a) == 3 || stack_get_top(p->a) == 4)
			sort_perform_operation(p, ops, OP_PB);
		else
			sort_perform_operation(p, ops, OP_RR);
	}
	sort_three(p, ops);
	sort_perform_operation(p, ops, OP_PA);
	sort_perform_operation(p, ops, OP_PA);
	if (stack_get_top(p->a) > stack_get_second(p->a))
		sort_perform_operation(p, ops, OP_SA);
	sort_perform_operation(p, ops, OP_RA);
	sort_perform_operation(p, ops, OP_RA);
}

t_ilist	*sort(void)
{
	t_program	*program;
	t_ilist		*operations;

	operations = NULL;
	program = program_get();
	if (program->count <= 3)
		sort_three(program, &operations);
	else if (program->count <= 5)
		sort_five(program, &operations);
	else if (program->count <= 100)
		sort_hundred(program, &operations);
	else
		sort_fivehundred(program, &operations);
	return (operations);
}
