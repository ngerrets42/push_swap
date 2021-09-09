/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 17:29:35 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 13:23:49 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	stack_lowest(t_stack *stack)
{
	int	i;
	int	lowest_n;
	int	lowest_i;

	i = 0;
	lowest_i = 0;
	lowest_n = __INT_MAX__;
	while (i < stack->top + 1)
	{
		if (stack->numbers[i] < lowest_n)
		{
			lowest_i = i;
			lowest_n = stack->numbers[i];
		}
		i++;
	}
	return (lowest_i);
}

void	stack_normalize(t_stack *a, t_stack *b)
{
	int	i;
	int	next_index;

	a->top = b->top;
	next_index = stack_lowest(b);
	a->numbers[next_index] = 0;
	i = 1;
	while (i < a->size)
	{
		next_index = stack_lowest(b);
		b->numbers[next_index] = __INT_MAX__;
		a->numbers[next_index] = i;
		i++;
	}
	while (b->top >= 0)
		stack_pop(b);
}

t_stack	*stack_from_argv(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	
	stack = stack_create(argc - 1);
	i = 1;
	while (i < argc)
	{
		stack_push(stack, ft_atoi(argv[i]));
		i++;
	}
	return (stack);
}
