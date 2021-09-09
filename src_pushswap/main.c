/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:41:32 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 16:43:04 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "program.h"
#include "operations.h"
#include "ilist.h"
#include "sort.h"

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

static void	operations_print(t_ilist *operations)
{
	char		**oplist;
	int			i;
	t_operation	op;

	oplist = operation_list();
	i = 0;
	while (operations != NULL)
	{
		op = (t_operation)operations->i;
		printf("%s\n", oplist[op]);
		operations = operations->next;
		i++;
	}
	printf("operations: %d\n", i);
}

int	main(int argc, char **argv)
{
	t_program	*program;
	t_ilist		*operations;

	operations = NULL;
	if (argc <= 1)
	{
		printf("\n");
		return (0);
	}
	program = program_get();
	program->count = argc - 1;
	program->b = stack_from_argv(argc, argv);
	program->a = stack_create(program->count);
	stack_normalize(program->a, program->b);
	stack_print(program->a);
	if (!stack_issorted(program->a))
		operations = sort();
	operations_print(operations);
	//DEBUG
	stack_print(program->a);
	//---
	program_free();
	return (0);
}
