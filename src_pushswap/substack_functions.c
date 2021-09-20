/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 11:16:11 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/17 12:21:04 by ngerrets      ########   odam.nl         */
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

// static int	_find_value(t_stack *stack, t_stype type, int value, int x)
// {
// 	int	i;

// 	if (type == ST_B)
// 	{
// 		i = stack->top;
// 		while (i > -1)
// 		{
// 			if (stack->numbers[i] == value || stack->numbers[i] == value + 1
// 				|| stack->numbers[i] == value + 2)
// 				return (stack->numbers[i - x]);
// 			i--;
// 		}
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < stack->size)
// 		{
// 			if (stack->numbers[i] == value || stack->numbers[i] == value + 1
// 				|| stack->numbers[i] == value + 2)
// 				return (stack->numbers[i + x]);
// 			i++;
// 		}
// 	}
// 	return (-1);
// }
