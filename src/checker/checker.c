/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 15:58:21 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 18:10:20 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_operation	checker_op_from_str(char *str)
{
	char			**oplist;
	t_operation		i;

	oplist = operation_list();
	i = 0;
	while (i < OP_COUNT)
	{
		if (str_is_str(str, oplist[i]))
			return (i);
		i++;
	}
	return (OP_COUNT);
}

t_ilist	*checker_operation_next(void)
{
	t_operation	operation;
	char		*line;
	int			retv;

	retv = get_next_line(0, &line);
	if (retv == -1)
		error(ERR_GNL);
	if (line[0] == '\0')
		return (NULL);
	line = str_trim_spaces(line);
	operation = checker_op_from_str(line);
	if (operation == OP_COUNT)
		error(ERR_UNKNOWN_OPERATION);
	return (ilst_new(operation));
}

t_ilist	*checker_operations_get(void)
{
	t_ilist	*head;
	t_ilist	*current;

	head = checker_operation_next();
	current = head;
	while (current != NULL)
	{
		current->next = checker_operation_next();
		current = current->next;
	}
	return (head);
}

static void	checker_operation_run(t_operation operation)
{
	void		(*func)(t_program *);
	t_program	*program;

	program = program_get();
	func = operation_get_function(operation);
	func(program);
}

void	checker_operations_perform(t_ilist *operations)
{
	t_operation	op;

	while (operations != NULL)
	{
		op = (t_operation)operations->i;
		if (op >= OP_COUNT || op < 0)
			error(ERR_UNKNOWN_OPERATION);
		checker_operation_run(op);
		operations = operations->next;
	}
}
