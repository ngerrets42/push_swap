/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_get.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:42:07 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/16 11:03:58 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_isempty(t_stack *stack)
{
	return (stack->top == -1);
}

int	stack_get_top(t_stack *stack)
{
	if (stack->top == -1)
		return (-1);
	return (stack->numbers[stack->top]);
}

int	stack_get_bottom(t_stack *stack)
{
	return (stack->numbers[0]);
}

int	stack_get_second(t_stack *stack)
{
	return (stack->numbers[stack->top - 1]);
}
