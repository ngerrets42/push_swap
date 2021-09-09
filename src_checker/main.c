/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 12:52:41 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 11:19:52 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "program.h"
#include "parse.h"

void	debug_print_ilist(t_ilist *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->i);
		lst = lst->next;
	}
}

static void	stack_print(t_stack *stack)
{
	int	i;

	i = stack->top;
	printf("------\n");
	while (i >= 0)
	{
		printf("|%3d|\n", stack->numbers[i]);
		i--;
	}
	printf("------\n");
}

int	main(int argc, char **argv)
{
	t_ilist		*operations;
	t_program	*program;

	if (argc == 1)
	{
		printf("OK!\n");
		return (0);
	}
	program = program_get();
	program->count = argc - 1;
	program->a = stack_from_argv(argc, argv);
	program->b = stack_create(program->count);
	operations = checker_operations_get();
	checker_operations_perform(operations);
	if (stack_issorted(program->a) == 1 && program->b->top < 0)
		printf("OK!");
	else
		printf("KO!");
	//DEBUG
	printf("\n");
	stack_print(program->a);
	//----
	program_free();
	return (0);
}