/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 15:16:23 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/07/22 22:31:47 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	stack_get_lowest(t_stack *stack)
{
	int	lowest;
	int	index;
	int	i;

	index = 0;
	lowest = stack->numbers[0];
	i = 1;
	while (i < stack->top + 1)
	{
		if (stack->numbers[i] <= lowest)
		{
			lowest = stack->numbers[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	stack_get_highest(t_stack *stack)
{
	int	highest;
	int	index;
	int	i;

	index = 0;
	highest = stack->numbers[0];
	i = 1;
	while (i < stack->top + 1)
	{
		if (stack->numbers[i] >= highest)
		{
			highest = stack->numbers[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	rotate_n_times(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		operation_rotate(stack);
		i++;
	}
}

void	rotate_reverse_n_times(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		operation_rotate_reverse(stack);
		i++;
	}
}

void	rotate_to_index(t_stack *stack, int index)
{
	if (index > stack->top / 2)
	{
		rotate_n_times(stack, index + 1);
	}
	else
	{
		rotate_reverse_n_times(stack, stack->top - index - 1);
	}
}

/*
int	sort(t_stack *a, t_stack *b)
{
	int	lowest_i;
	int	operations;

	operations = 0;
	lowest_i = stack_get_lowest(a);
	rotate_to_index(a, lowest_i);
	operations += lowest_i + 1;
	operation_push(a, b);
	operations++;
	while (a->top >= 0)
	{
		lowest_i = stack_get_lowest(a);
		rotate_to_index(a, lowest_i);
		operations += lowest_i + 1;
		operation_push(a, b);
		operations++;
	}
	while(b->top >= 0)
	{
		operations++;
		operation_push(b, a);
	}
	return (operations);
}*/

int	is_partially_sorted(t_stack *a)
{
	int	lowest;
	int	prev;
	int	i;

	lowest = stack_get_lowest(a);
	i = lowest - 1;
	prev = lowest;
	while (i >= 0)
	{
		//printf(" %d <", a->numbers[prev]);
		if (a->numbers[i] < a->numbers[prev])
		{
			//printf("! %d\n", a->numbers[i]);
			return (0);
		}
		//if (i == 0)
			//printf(" %d", a->numbers[i]);
		prev = i;
		i--;
	}
	prev = 0;
	i = a->top;
	while (i > lowest)
	{
		//printf(" %d <", a->numbers[prev]);
		if (a->numbers[i] < a->numbers[prev])
		{
			//printf("! %d\n", a->numbers[i]);
			return (0);
		}
		prev = i;
		i--;
	}
	printf(" OK\n");
	return (1);
}

int	is_sorted(t_stack *a)
{
	int	i;
	int	prev;

	i = 1;
	prev = a->numbers[a->top];
	while(i < a->top)
	{
		if (a->numbers[a->top - i] < prev)
			return (0);
		prev = a->numbers[a->top - i];
		i++;
	}
	return (1);
}

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->numbers[stack->top];
	stack->numbers[stack->top] = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = temp;
}

static void	stack_print(t_stack *stack)
{
	int	i;

	i = stack->top;
	printf("------\n");
	while (i >= 0)
	{
		printf("|%3d|\n", stack->numbers[i]);
		i--;
	}
	printf("------\n");
}
/*
4	2
3	3
2	4
1	0
0	1
*/
int	is_at_right_pos(t_stack *a, int index)
{
	int	num;
	int	lowest;
	int	correct_pos;

	lowest = stack_get_lowest(a);
	//if (index == lowest)
	//	return (0);
	num = a->numbers[index];
	correct_pos = a->top - num + lowest + 1;
	if (correct_pos > a->top)
		correct_pos -= a->top;
	if (index == correct_pos)
		return (1);
	return (0);
}

int	sort(t_stack *a, t_stack *b)
{
	int	operations;

	operations = 0;
	if (a->top < 1)
		return (0);
	while (!is_partially_sorted(a))
	{
		//return (0);
		if (a->numbers[a->top] > a->numbers[a->top - 1] && !is_at_right_pos(a, a->top))
		{
			swap(a);
			//printf("swap\n");
			//stack_print(a);
			operations++;
		}
		operation_rotate(a);
		//printf("rotate\n");
		//stack_print(a);
		operations++;
	}
	rotate_to_index(a, stack_get_lowest(a));
	return (operations);
}
