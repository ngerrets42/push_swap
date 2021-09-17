/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack_sortback.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 12:12:24 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/17 12:20:28 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "substack.h"

static void	substack_single_to_a(t_program *p, t_ilist **ops, t_substack sub)
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

static void	_move_away(t_program *p, t_ilist **ops, t_substack sub)
{
	if (sub.stack_type == ST_A)
		sort_perform_operation(p, ops, OP_PB);
	else
		sort_perform_operation(p, ops, OP_RA);
}

static void	_move_back(t_program *p, t_ilist **ops, t_substack sub)
{
	if (sub.stack_type == ST_A)
		sort_perform_operation(p, ops, OP_PA);
	else
		sort_perform_operation(p, ops, OP_RRA);
}

static void	_sortback_three(t_program *p, t_ilist **ops, t_substack sub)
{
	substack_single_to_a(p, ops, sub);
	if (stack_get_top(p->a) == sub.value_start)
	{
		_move_away(p, ops, sub);
	}
	substack_single_to_a(p, ops, sub);
	if (stack_get_top(p->a) == sub.value_start)
	{
		_move_away(p, ops, sub);
	}
	if (stack_get_top(p->a) == sub.value_start + 2
		&& stack_get_second(p->a) == sub.value_start + 1)
		sort_perform_operation(p, ops, OP_SA);
	substack_single_to_a(p, ops, sub);
	if (stack_get_top(p->a) == sub.value_start + 2
		&& stack_get_second(p->a) == sub.value_start + 1)
		sort_perform_operation(p, ops, OP_SA);
	if (stack_get_top(p->a) != sub.value_start)
		_move_back(p, ops, sub);
}

void	substack_sortback(t_program *p, t_ilist **ops, t_substack sub)
{
	int	i;

	i = 0;
	if (sub.count == 2)
	{
		while (i < sub.count)
		{
			substack_single_to_a(p, ops, sub);
			i++;
		}
		if (p->a->top > 0 && stack_get_top(p->a) > stack_get_second(p->a))
			sort_perform_operation(p, ops, OP_SA);
	}
	else if (sub.count == 3)
		_sortback_three(p, ops, sub);
	else
		substack_single_to_a(p, ops, sub);
}
