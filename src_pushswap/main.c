/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:41:32 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/30 11:15:41 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "operations.h"
#include "ilist.h"
#include "sort.h"

static void	operations_print(t_ilist *operations)
{
	char		**oplist;
	int			i;
	t_ilist		*prev;
	t_operation	op;

	oplist = operation_list();
	i = 0;
	while (operations != NULL)
	{
		prev = operations;
		op = (t_operation)operations->i;
		if (putstr(oplist[op]) < 0 || putstr("\n") < 0)
			error_exit(ERR_WRITE);
		operations = operations->next;
		free(prev);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program	*program;
	t_ilist		*operations;

	operations = NULL;
	if (argc <= 1)
		return (0);
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
	operations_print(operations);
	if (!stack_issorted(program->a))
		error_exit(ERR_STACK_NOT_SORTED);
	program_free();
	return (0);
}
