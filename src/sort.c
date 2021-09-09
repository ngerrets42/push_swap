/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:03:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 11:30:46 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	sort_fivehundred(t_program *program, t_ilist **operations)
{
	
}

static void	*sort_hundred(t_program *program, t_ilist **operations)
{
	
}

static void	*sort_five(t_program *program, t_ilist **operations)
{
	sort_perform_operaton(program, operations, OP_PB);
	sort_perform_operaton(program, operations, OP_PA);
	sort_perform_operaton(program, operations, OP_RR);
	sort_perform_operaton(program, operations, OP_RR);
	sort_perform_operaton(program, operations, OP_RR);
}

t_ilist	*sort(void)
{
	t_program	*program;
	t_ilist		*operations;

	operations = NULL;
	program = program_get();
	if (program->count <= 5)
		sort_five(program, &operations);
	else if (program->count <= 100)
		sort_hundred(program, &operations);
	else
		sort_fivehundred(program, &operations);
	return (operations);
}

