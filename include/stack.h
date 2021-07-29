/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:02:49 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/07/15 17:50:58 by ngerrets      ########   odam.nl         */
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

#endif
