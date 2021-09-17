/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:17:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/17 12:37:15 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_perform_operation(t_program *p, t_ilist **ops, t_operation op)
{
	void		(*func)(t_program *);
	t_ilist		*new;

	func = operation_get_function(op);
	func(p);
	new = ilst_new(op);
	if (new == NULL)
		error(ERR_MALLOC);
	ilst_add_back(ops, new);
}

static int	_remove_next_two_ops(t_ilist *current)
{
	t_ilist	*new_next;

	new_next = NULL;
	if (current->next->next)
		new_next = current->next->next->next;
	ilst_destroy_element(current->next->next);
	ilst_destroy_element(current->next);
	current->next = new_next;
	return (1);
}

static int	_remove_next_op_and_edit(t_ilist *current, t_operation op)
{
	t_ilist	*new_next;

	new_next = NULL;
	if (current->next->next)
		new_next = current->next->next->next;
	ilst_destroy_element(current->next->next);
	current->next->next = new_next;
	current->next->i = op;
	return (1);
}

static int	_check_and_rem(t_operation op1, t_operation op2, t_ilist *current)
{
	int	no_duplicates;

	no_duplicates = 0;
	if (op1 == OP_PA && op2 == OP_PB)
		no_duplicates = _remove_next_two_ops(current);
	else if (op1 == OP_PB && op2 == OP_PA)
		no_duplicates = _remove_next_two_ops(current);
	else if (op1 == OP_RA && op2 == OP_RRA)
		no_duplicates = _remove_next_two_ops(current);
	else if (op1 == OP_RRA && op2 == OP_RA)
		no_duplicates = _remove_next_two_ops(current);
	else if (op1 == OP_RB && op2 == OP_RRB)
		no_duplicates = _remove_next_two_ops(current);
	else if (op1 == OP_RRB && op2 == OP_RB)
		no_duplicates = _remove_next_two_ops(current);
	else if (op1 == OP_RB && op2 == OP_RA)
		no_duplicates = _remove_next_op_and_edit(current, OP_RR);
	else if (op1 == OP_RRA && op2 == OP_RRB)
		no_duplicates = _remove_next_op_and_edit(current, OP_RRR);
	else if (op1 == OP_RR && op2 == OP_RRA)
		no_duplicates = _remove_next_op_and_edit(current, OP_RB);
	return (no_duplicates);
}

int	sort_reduce_operations(t_ilist **ops)
{
	t_ilist		*current;
	t_operation	op1;
	t_operation	op2;
	int			no_duplicates;

	no_duplicates = 0;
	current = *ops;
	current = current->next;
	while (current != NULL
		&& current->next != NULL
		&& current->next->next != NULL)
	{
		op1 = (t_operation)current->next->i;
		op2 = (t_operation)current->next->next->i;
		no_duplicates = _check_and_rem(op1, op2, current);
		current = current->next;
	}
	return (no_duplicates);
}
