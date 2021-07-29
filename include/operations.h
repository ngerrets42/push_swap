/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:23:36 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/07/15 14:54:00 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

void	operation_swap(t_stack *stack);
void	operation_push(t_stack *from, t_stack *to);
void	operation_rotate(t_stack *stack);
void	operation_rotate_reverse(t_stack *stack);

#endif
