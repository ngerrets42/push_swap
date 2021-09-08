/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 17:50:16 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 17:59:40 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	operation_rrr(t_program *program)
{
	stack_rotate_reverse(program->a);
	stack_rotate_reverse(program->b);
}
