/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 12:52:41 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/06 14:08:55 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "list.h"
#include <unistd.h>
#include "str.h"

static t_operation	operation_from_str(char *str)
{
	static t_strint	*oplist = NULL;
	int				i;

	if (!oplist)
		oplist = operation_list();
	i = 0;
	while (i < OP_COUNT)
	{
		if (str_is_str(str, oplist[i].str))
			return ((t_operation)oplist[i].i);
	}
	return (OP_COUNT);
}

static t_list	*next_operation(void)
{
	static int	index = 0;
	static char	buffer[4];
	t_operation	operation;

	operation = OP_COUNT;
	while (read(STDIN_FILENO, buffer, 1) > 0 && buffer[0] == ' ')
		;
	buffer[1] = read(STDIN_FILENO, &(buffer[1]), 2);
	if (buffer[0] && buffer[1] && buffer[2])
		operation = operation_from_str(buffer);
	buffer[3] = '\0';
	if (operation != OP_COUNT)
		return (ft_lstnew(&operation));
	return (NULL);
}

static t_list	*get_operations(void)
{
	t_list	*head;
	t_list	*current;

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
	t_list	*operations;

	operations = get_operations();

	while (operations != NULL)
	{
		printf("%d\n", *(int *)(operations->content));
		operations = operations->next;
	}
}