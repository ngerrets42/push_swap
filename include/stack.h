/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:02:49 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 13:13:57 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "str.h"

typedef struct s_stack
{
	int	size;
	int	top;
	int	*numbers;
}		t_stack;

t_stack	*stack_create(int size);
void	stack_destroy(t_stack *stack);
int		stack_push(t_stack *stack, int number);
int		stack_pop(t_stack *stack);
int		stack_issorted(t_stack *stack);

int		stack_isempty(t_stack *stack);
int		stack_get_top(t_stack *stack);
int		stack_get_bottom(t_stack *stack);
int		stack_get_second(t_stack *stack);

void	stack_swap(t_stack *stack);
void	stack_pushto(t_stack *from, t_stack *to);
void	stack_rotate(t_stack *stack);
void	stack_rotate_reverse(t_stack *stack);

t_stack	*stack_from_argv(int argc, char **argv);
void	stack_normalize(t_stack *a, t_stack *b);

#endif
