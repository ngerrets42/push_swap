/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 17:50:16 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 17:57:59 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	operation_sa(t_program *program)
{
	stack_swap(program->a);
}

void	operation_sb(t_program *program)
{
	stack_swap(program->b);
}

void	operation_ss(t_program *program)
{
	stack_swap(program->a);
	stack_swap(program->b);
}

void	operation_pa(t_program *program)
{
	stack_pushto(program->b, program->a);
}

void	operation_pb(t_program *program)
{
	stack_pushto(program->a, program->b);
}
