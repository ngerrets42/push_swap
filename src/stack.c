/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:06:39 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 18:20:36 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stddef.h>
#include <stdlib.h>
#include "nerror.h"

/*
**	Create a stack with size
*/
t_stack	*stack_create(int size)
{
	t_stack	*stack;

	if (size <= 0)
		error(ERR_STACK_SIZE_ZERO);
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		error(ERR_MALLOC);
	stack->size = size;
	stack->top = -1;
	stack->numbers = malloc(sizeof(int) * size);
	if (stack->numbers == NULL)
	{
		free(stack);
		error(ERR_MALLOC);
	}
	return (stack);
}

/*
**	free the stack and its contents
*/
void	stack_destroy(t_stack *stack)
{
	if (stack == NULL)
		return ;
	free(stack->numbers);
	free(stack);
}

/*
**	Push a number to the top of the stack.
**	returns 0 on SUCCES, 1 if the stack is full.
*/
int	stack_push(t_stack *stack, int number)
{
	if (stack->top + 1 >= stack->size)
		return (1);
	(stack->top)++;
	stack->numbers[stack->top] = number;
	return (0);
}

/*
**	"pops" the top element of the stack. Returning it's value.
**	This function doesn't actually reset the information,
**		but rather just lowers the index of top.
**	returns 0 if there is no top.
*/
int	stack_pop(t_stack *stack)
{
	if (stack->top < 0)
		return (0);
	(stack->top)--;
	return (stack->numbers[stack->top + 1]);
}

int	stack_issorted(t_stack *stack)
{
	int	i;

	if (stack->size <= 1)
		return (1);
	i = 1;
	while (i < stack->size)
	{
		if (stack->numbers[i - 1] < stack->numbers[i])
			return (0);
		i++;
	}
	return (1);
}
