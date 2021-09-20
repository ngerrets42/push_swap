/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 11:16:11 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/20 12:06:52 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "substack.h"

t_substack	substack_from_stack(t_stack *stack)
{
	t_substack	sub;

	sub.stack_type = ST_A;
	sub.value_start = 0;
	sub.value_end = stack->top;
	sub.count = stack->top + 1;
	return (sub);
}

t_substack	substack_create(t_stype type, int count, int start_value)
{
	t_substack	sub;

	sub.count = count;
	sub.stack_type = type;
	sub.value_start = start_value;
	sub.value_end = start_value + count - 1;
	return (sub);
}

int	substack_contains_value(t_substack sub, int value)
{
	return (value >= sub.value_start && value <= sub.value_end);
}

void	substack_single_to_a(t_program *p, t_ilist **ops, t_substack sub)
{
	if (sub.stack_type == ST_C)
	{
		if (substack_contains_value(sub, stack_get_top(p->b)) == 0)
		{
			if (substack_contains_value(sub, stack_get_bottom(p->b)))
				sort_perform_operation(p, ops, OP_RRB);
		}
		if (substack_contains_value(sub, stack_get_top(p->b)))
			sort_perform_operation(p, ops, OP_PA);
	}
	else if (sub.stack_type == ST_B)
	{
		if (substack_contains_value(sub, stack_get_top(p->b)))
			sort_perform_operation(p, ops, OP_PA);
	}
	else if (sub.stack_type == ST_A && p->a->top >= sub.count - 1)
	{
		if (substack_contains_value(sub, stack_get_bottom(p->a)))
			sort_perform_operation(p, ops, OP_RRA);
	}
}
