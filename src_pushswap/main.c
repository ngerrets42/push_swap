/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:41:32 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/17 17:04:55 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "program.h"
#include "operations.h"
#include "ilist.h"
#include "sort.h"

// static void	stack_print(t_stack *stack)
// {
// 	int	i;

// 	i = stack->top;
// 	printf("------\n");
// 	while (i >= 0)
// 	{
// 		printf("|%3d|\n", stack->numbers[i]);
// 		i--;
// 	}
// 	printf("------\n");
// }

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
		//printf("%s\n", oplist[op]);
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
	program->b = stack_from_argv(argc, argv);
	program->count = program->b->size;
	program->a = stack_create(program->count);
	stack_normalize(program->a, program->b);
	if (stack_issorted(program->a))
		return (0);
	operations = sort();
	while (sort_reduce_operations(&operations))
		;
	//operations_print(operations);
	//DEBUG
	operations_print(operations);
	//stack_print(program->a);
	//stack_print(program->b);
	if (!stack_issorted(program->a))
		error(ERR_STACK_NOT_SORTED);
	program_free();
	return (0);
}
