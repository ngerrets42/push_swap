/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:41:32 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 11:37:07 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "program.h"
#include "parse.h"
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
	t_operation	op;

	oplist = operation_list();
	while (operations != NULL)
	{
		op = (t_operation)operations->i;
		printf("%s\n", oplist[op]);
		operations = operations->next;
	}
}

int	main(int argc, char **argv)
{
	t_program	*program;
	t_ilist		*operations;

	if (argc <= 1)
	{
		printf("\n");
		return (0);
	}
	program = program_get();
	program->count = argc - 1;
	program->a = stack_from_argv(argc, argv);
	program->b = stack_create(program->count);
	operations = sort();
	operations_print(operations);
	//DEBUG
	stack_print(program->a);
	//---
	program_free();
	return (0);
}
