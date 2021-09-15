/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 17:29:35 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/15 18:03:09 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "nerror.h"

static int	stack_lowest(t_stack *stack)
{
	int	i;
	int	lowest_n;
	int	lowest_i;

	i = 0;
	lowest_i = 0;
	lowest_n = __INT_MAX__;
	while (i <= stack->top)
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
	b->numbers[next_index] = __INT_MAX__;
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

int	stack_find_value(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->numbers[i] == value)
			return (1);
		i++;
	}
	return (-1);
}

t_stack	*stack_from_line(char *line)
{
	t_stack	*stack;
	char	**split;
	int		n;
	int		i;

	split = ft_split(line, ' ');
	if (split == NULL)
		return (NULL);
	i = 0;
	while (split[i] != NULL)
		i++;
	stack = stack_create(i);
	i = 0;
	while (split[i] != NULL)
	{
		n = ft_atoi(split[i]);
		free(split[i]);
		if (stack_find_value(stack, n) > -1)
		{
			while (split[i + 1] != NULL)
			{
				free(split[i + 1]);
				i++;
			}
			free(split);
			error(ERR_STACK_DUPVALUE);
		}
		stack_push(stack, n);
		i++;
	}
	free(split);
	return (stack);
}

t_stack	*stack_from_argv(int argc, char **argv)
{
	t_stack	*stack;
	int		n;
	int		i;
	
	if (argc == 2)
		return (stack_from_line(argv[1]));
	stack = stack_create(argc - 1);
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (stack_find_value(stack, n) > -1)
			error(ERR_STACK_DUPVALUE);
		stack_push(stack, n);
		i++;
	}
	return (stack);
}
