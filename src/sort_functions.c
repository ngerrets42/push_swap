/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:17:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 12:20:53 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_perform_operation(t_program *program, t_ilist **operations, t_operation op)
{
	void		(*func)(t_program *);
	t_ilist		*new;

	func = operation_get_function(op);
	func(program);
	new = ilst_new(op);
	if (new == NULL)
		error(ERR_MALLOC);
	ilst_add_back(operations, new);
}
