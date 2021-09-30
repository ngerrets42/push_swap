/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 17:19:59 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/30 10:46:23 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

static t_program	*program_alloc(void)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (program == NULL)
		error_exit(ERR_MALLOC);
	program->a = NULL;
	program->b = NULL;
	program->count = 0;
	return (program);
}

t_program	*program_get(void)
{
	static t_program	*program = NULL;

	if (program == NULL)
		program = program_alloc();
	return (program);
}

void	program_free(void)
{
	t_program	*program;

	program = program_get();
	if (program->a)
		stack_destroy(program->a);
	if (program->b)
		stack_destroy(program->b);
	free(program);
}

void	program_exit(int exitcode)
{
	program_free();
	exit(exitcode);
}
