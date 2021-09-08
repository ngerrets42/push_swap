/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:02:49 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 18:17:09 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

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

void	stack_swap(t_stack *stack);
void	stack_pushto(t_stack *from, t_stack *to);
void	stack_rotate(t_stack *stack);
void	stack_rotate_reverse(t_stack *stack);

#endif
