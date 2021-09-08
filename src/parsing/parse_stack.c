/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 17:29:35 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 17:37:03 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_stack	*stack_from_argv(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	
	stack = stack_create(argc - 1);
	i = 1;
	while (i < argc)
	{
		stack_push(stack, ft_atoi(argv[i]));
		i++;
	}
	return (stack);
}
