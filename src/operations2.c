/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 17:50:16 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 17:59:21 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	operation_ra(t_program *program)
{
	stack_rotate(program->a);
}

void	operation_rb(t_program *program)
{
	stack_rotate(program->b);
}

void	operation_rr(t_program *program)
{
	stack_rotate(program->a);
	stack_rotate(program->b);
}

void	operation_rra(t_program *program)
{
	stack_rotate_reverse(program->a);
}

void	operation_rrb(t_program *program)
{
	stack_rotate_reverse(program->b);
}
