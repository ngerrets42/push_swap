/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 11:47:51 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/20 12:07:14 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSTACK_H
# define SUBSTACK_H

# define SUBSTACK_TARGET_SIZE 3

# include "stack.h"
# include "sort.h"
# include "operations.h"
# include "program.h"
# include "ilist.h"

typedef enum e_stype
{
	ST_A = 0,
	ST_B,
	ST_C,
	ST_NONE
}	t_stype;

typedef struct s_substack
{
	int		count;
	int		value_start;
	int		value_end;
	t_stype	stack_type;
}			t_substack;

int			substack_contains_value(t_substack sub, int value);
void		substack_split(t_substack sub[3], t_substack src);
void		substack_sortback(t_program *p, t_ilist **ops, t_substack sub);
void		substack_divide(t_program *p, t_ilist **ops, t_substack div);
t_substack	substack_from_stack(t_stack *stack);
t_substack	substack_create(t_stype type, int count, int start_value);
void		substack_single_to_a(t_program *p, t_ilist **ops, t_substack sub);

#endif
