/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack_divide.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 11:42:23 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/20 11:48:06 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "substack.h"

static void	_div_from_astack(t_program *p, t_ilist **ops, t_substack div,
		t_substack sub[3])
{
	int	i;
	int	value;

	i = 0;
	while (i < div.count)
	{
		value = stack_get_top(p->a);
		if (substack_contains_value(sub[ST_A], value))
			sort_perform_operation(p, ops, OP_RA);
		else if (sub[ST_C].stack_type != ST_NONE
			&& substack_contains_value(sub[ST_C], value))
		{
			sort_perform_operation(p, ops, OP_PB);
			if (p->b->top > 0 && substack_contains_value(sub[ST_C],
					stack_get_second(p->b)) == 0)
				sort_perform_operation(p, ops, OP_RB);
		}
		else if (substack_contains_value(sub[ST_B], value))
			sort_perform_operation(p, ops, OP_PB);
		i++;
	}
}

static void	_div_from_bstack(t_program *p, t_ilist **ops, t_substack div,
		t_substack sub[3])
{
	int	i;
	int	value;

	i = 0;
	while (i < div.count)
	{
		value = stack_get_top(p->b);
		if (substack_contains_value(sub[ST_A], value))
		{
			sort_perform_operation(p, ops, OP_PA);
			sort_perform_operation(p, ops, OP_RA);
		}
		else if (sub[ST_C].stack_type != ST_NONE
			&& substack_contains_value(sub[ST_C], value))
			sort_perform_operation(p, ops, OP_RB);
		else if (substack_contains_value(sub[ST_B], value))
			sort_perform_operation(p, ops, OP_PA);
		i++;
	}
	i = 0;
	while (i < sub[ST_B].count)
	{
		sort_perform_operation(p, ops, OP_PB);
		i++;
	}
}

static void	_substack_div_c(t_program *p, t_ilist **ops, t_substack div,
		t_substack sub[3])
{
	int	i;

	if (!substack_contains_value(div, stack_get_top(p->b)))
	{
		i = 0;
		while (i < div.count)
		{
			sort_perform_operation(p, ops, OP_RRB);
			i++;
		}
	}
	_div_from_bstack(p, ops, div, sub);
}

static void	_substack_a_prepare(t_program *p, t_ilist **ops, t_substack sub)
{
	int	i;

	i = 0;
	if (substack_contains_value(sub, stack_get_top(p->a)))
		return ;
	while (i < sub.count)
	{
		sort_perform_operation(p, ops, OP_RRA);
		i++;
	}
}

void	substack_divide(t_program *p, t_ilist **ops, t_substack div)
{
	t_substack	sub[3];

	if (div.count < 1)
		return ;
	if (div.count <= SUBSTACK_TARGET_SIZE)
		return (substack_sortback(p, ops, div));
	substack_split(sub, div);
	if (div.stack_type == ST_B)
		_div_from_bstack(p, ops, div, sub);
	else if (div.stack_type == ST_C)
		_substack_div_c(p, ops, div, sub);
	else
	{
		_substack_a_prepare(p, ops, div);
		_div_from_astack(p, ops, div, sub);
	}
	substack_divide(p, ops, sub[ST_A]);
	substack_divide(p, ops, sub[ST_B]);
	substack_divide(p, ops, sub[ST_C]);
}
