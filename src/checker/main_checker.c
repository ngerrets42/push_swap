/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 12:52:41 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 12:29:52 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "nerror.h"
#include "operations.h"
#include "ilist.h"
#include <unistd.h>
#include "str.h"
#include "../../lib/get_next_line/get_next_line.h"

static t_operation	operation_from_str(char *str)
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

static t_ilist	*next_operation(void)
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
	operation = operation_from_str(line);
	if (operation == OP_COUNT)
		error(ERR_UNKNOWN_OPERATION);
	return (ilst_new(operation));
}

static t_ilist	*get_operations(void)
{
	t_ilist	*head;
	t_ilist	*current;

	head = next_operation();
	current = head;
	while (current != NULL)
	{
		current->next = next_operation();
		current = current->next;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	t_ilist	*operations;

	operations = get_operations();
	while (operations != NULL)
	{
		printf("%d\n", operations->i);
		operations = operations->next;
	}
	return (0);
}