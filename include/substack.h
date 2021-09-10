/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 11:47:51 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/10 13:35:25 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSTACK_H
# define SUBSTACK_H

# include "stack.h"
# include "program.h"
# include "ilist.h"

typedef enum e_stype
{
	ST_A = 0,
	ST_B,
	ST_C
}	t_stype;

typedef struct s_substack
{
	int		count;
	int		value_start;
	t_stype	stack_type;
}			t_substack;

t_substack	substack_from_stack(t_stack *stack);
t_substack	*substack_divide(t_program *p, t_ilist **ops, t_substack sub);

#endif
