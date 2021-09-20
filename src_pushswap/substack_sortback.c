/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack_sortback.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 12:12:24 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/20 13:11:10 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "substack.h"

static void	_move_away(t_program *p, t_ilist **ops, t_substack sub)
{
	if (sub.stack_type == ST_A)
		sort_perform_operation(p, ops, OP_PB);
	else
		sort_perform_operation(p, ops, OP_RA);
}

static void	_swapa(t_program *p, t_ilist **ops)
{
	if (stack_get_top(p->b) < stack_get_second(p->b))
		sort_perform_operation(p, ops, OP_SS);
	else
		sort_perform_operation(p, ops, OP_SA);
}

static void	_three_from_c(t_program *p, t_ilist **ops, t_substack sub)
{
	sort_perform_operation(p, ops, OP_RRB);
	if (stack_get_top(p->b) != sub.value_start)
		sort_perform_operation(p, ops, OP_PA);
	sort_perform_operation(p, ops, OP_RRB);
	if (stack_get_top(p->b) != sub.value_start)
	{
		sort_perform_operation(p, ops, OP_PA);
		if (stack_get_top(p->a) > stack_get_second(p->a))
			_swapa(p, ops);
	}
	sort_perform_operation(p, ops, OP_RRB);
	sort_perform_operation(p, ops, OP_PA);
	if (stack_get_top(p->a) > stack_get_second(p->a))
		_swapa(p, ops);
	if (stack_get_top(p->b) == sub.value_start)
		sort_perform_operation(p, ops, OP_PA);
}

void	_sortback_three(t_program *p, t_ilist **ops, t_substack sub)
{
	if (sub.stack_type == ST_C)
		return (_three_from_c(p, ops, sub));
	substack_single_to_a(p, ops, sub);
	if (stack_get_top(p->a) == sub.value_start)
		_move_away(p, ops, sub);
	substack_single_to_a(p, ops, sub);
	if (stack_get_top(p->a) == sub.value_start)
		_move_away(p, ops, sub);
	if (stack_get_top(p->a) == sub.value_start + 2
		&& stack_get_second(p->a) == sub.value_start + 1)
		_swapa(p, ops);
	substack_single_to_a(p, ops, sub);
	if (stack_get_top(p->a) == sub.value_start + 2
		&& stack_get_second(p->a) == sub.value_start + 1)
		_swapa(p, ops);
	if (stack_get_top(p->a) != sub.value_start)
	{
		if (sub.stack_type == ST_A)
			sort_perform_operation(p, ops, OP_PA);
		else
			sort_perform_operation(p, ops, OP_RRA);
	}
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
			_swapa(p, ops);
	}
	else if (sub.count == 3)
		_sortback_three(p, ops, sub);
	else
		substack_single_to_a(p, ops, sub);
}
