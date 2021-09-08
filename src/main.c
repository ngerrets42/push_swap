/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:41:32 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 18:09:55 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include "str.h"

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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	printf("%d\n", argc - 1);

	a = stack_from_argv(argc, argv);
	b = stack_create(a->size);

	stack_print(a);
	printf("%d\n", a->size);

	int ops = 0;

	//operation_rotate(a);

	stack_print(a);
	stack_print(b);
	printf("OPERATIONS: %d\n", ops);
	stack_destroy(a);
	stack_destroy(b);
	return (0);
}
