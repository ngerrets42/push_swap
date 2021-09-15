/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 11:16:11 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/15 16:10:27 by ngerrets      ########   odam.nl         */
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

static void	substack_single_to_a(t_program *p, t_ilist **ops, t_substack sub)
{
	if (sub.stack_type == ST_C)
	{
		sort_perform_operation(p, ops, OP_RRB);
		sort_perform_operation(p, ops, OP_PA);
	}
	else if (sub.stack_type == ST_B)
		sort_perform_operation(p, ops, OP_PA);
	else
		sort_perform_operation(p, ops, OP_RRA);
}

void	substack_prepare(t_program *p, t_ilist **ops, t_substack sub)
{
	int	i;

	i = 0;
	while (i < sub.count)
	{
		substack_single_to_a(p, ops, sub);
		i++;
	}
}

/*
A	B

1
2
X
X
X
X
X
X
X
	0
*/

static int	_find_value(t_stack *stack, t_stype type, int value, int x)
{
	int	i;

	if (type == ST_B)
	{
		i = stack->top;
		while (i > -1)
		{
			if (stack->numbers[i] == value || stack->numbers[i] == value + 1
				|| stack->numbers[i] == value + 2)
				return (stack->numbers[i - x]);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < stack->size)
		{
			if (stack->numbers[i] == value || stack->numbers[i] == value + 1
				|| stack->numbers[i] == value + 2)
				return (stack->numbers[i + x]);
			i++;
		}
	}
	
	return (-1);
}

static int	_check_array(int x[3], int y[3], int start_value)
{
	y[0] += start_value;
	y[1] += start_value;
	y[2] += start_value;

	if (x[0] == y[0] && x[1] == y[1] && x[2] == y[2])
		return (1);
	return (0);
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
	int		x[3];
	t_stack	*stack;

	/*stack = p->b;
	if (sub.stack_type == ST_A)
		stack = p->a;
	x[0] = _find_value(stack, sub.stack_type, sub.value_start, 0);
	x[1] = _find_value(stack, sub.stack_type, sub.value_start, 1);
	x[2] = _find_value(stack, sub.stack_type, sub.value_start, 2);
	substack_single_to_a(p, ops, sub);
	if (_check_array(x, (int []){0, 1, 2}, sub.value_start))
	{
		_move_away(p, ops, sub);
		substack_single_to_a(p, ops, sub);
		_move_away(p, ops, sub);
		substack_single_to_a(p, ops, sub);
		_move_back(p, ops, sub);
		_move_back(p, ops, sub);
	}
	else if (_check_array(x, (int []){2, 1, 0}, sub.value_start))
	{
		substack_single_to_a(p, ops, sub);
		substack_single_to_a(p, ops, sub);
	}
	else if (_check_array(x, (int []){1, 2, 0}, sub.value_start))
	{
		substack_single_to_a(p, ops, sub);
		sort_perform_operation(p, ops, OP_SA);
		substack_single_to_a(p, ops, sub);
	}
	else if (_check_array(x, (int []){1, 0, 2}, sub.value_start))
	{
		substack_single_to_a(p, ops, sub);
		_move_away(p, ops, sub);
		substack_single_to_a(p, ops, sub);
		sort_perform_operation(p, ops, OP_SA);
		_move_back(p, ops, sub);
	}
	else if (_check_array(x, (int []){0, 2, 1}, sub.value_start))
	{
		substack_single_to_a(p, ops, sub);
		sort_perform_operation(p, ops, OP_SA);
		substack_single_to_a(p, ops, sub);
		sort_perform_operation(p, ops, OP_SA);
	}
	else if (_check_array(x, (int []){2, 0, 1}, sub.value_start))
	{
		substack_single_to_a(p, ops, sub);
		substack_single_to_a(p, ops, sub);
		sort_perform_operation(p, ops, OP_SA);
	}
	else
	{
		printf("\n\nNONE! %d %d %d START: %d\n\n", x[0], x[1], x[2], sub.value_start);
	}*/

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
	if (stack_get_top(p->a) == sub.value_start + 2 && stack_get_second(p->a) == sub.value_start + 1)
		sort_perform_operation(p, ops, OP_SA);
	substack_single_to_a(p, ops, sub);
	if (stack_get_top(p->a) == sub.value_start + 2 && stack_get_second(p->a) == sub.value_start + 1)
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
		if (stack_get_top(p->a) > stack_get_second(p->a))
			sort_perform_operation(p, ops, OP_SA);
	}
	else if (sub.count == 3)
		_sortback_three(p, ops, sub);
	else
		substack_single_to_a(p, ops, sub);
}