/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 11:51:21 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/10 14:52:57 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "substack.h"
#include "sort.h"

//	REMOVE
#include <stdio.h>
void	substack_print(t_substack sub)
{
	printf("substack\n	count: %d\n	stack_type: %d\n	value_start: %d\n",
		sub.count, sub.stack_type, sub.value_start);
}

t_substack	substack_from_stack(t_stack *stack)
{
	t_substack	sub;

	sub.stack_type = ST_A;
	sub.value_start = 0;
	sub.count = stack->top + 1;
	return (sub);
}

t_substack	substack_set(t_stype type, int count, int start_value)
{
	t_substack	sub;

	sub.count = count;
	sub.stack_type = type;
	sub.value_start = start_value;
	return (sub);
}

void	substack_perform_divide(t_substack sub[3], t_stype type)
{
	printf("------\n");
	substack_print(sub[0]);
	substack_print(sub[1]);
	substack_print(sub[2]);
	printf("------\n");
}

void	substack_prepare(t_program *p, t_ilist **ops, t_substack sub)
{
	int	i;

	i = 0;
	while (i < sub.count)
	{
		if (sub.stack_type == ST_C)
		{
			sort_perform_operation(p, ops, OP_RRB);
			sort_perform_operation(p, ops, OP_PA);
		}
		else if (sub.stack_type == ST_B)
			sort_perform_operation(p, ops, OP_PA);
		else
			sort_perform_operation(p, ops, OP_RRA);
		i++;
	}
}

void	substack_pushback(t_program *p, t_ilist **ops, t_substack sub)
{
	substack_prepare(p, ops, sub);
	if (stack_get_top(p->a) > stack_get_second(p->a))
		sort_perform_operation(p, ops, OP_SA);
}

void	substack_div(t_program *p, t_ilist **ops, t_substack sub)
{
	int	i;
	int	third;
	int	value;
	int	start;

	third = sub.count / 3;
	start = sub.value_start;
	//Rotate all to top of a-stack, then divide again
	if (p->b->top > -1)
		substack_prepare(p, ops, sub);
	i = 0;
	while (i < sub.count)
	{
		value = stack_get_top(p->a);
		//	Move to C (push to b and rotate b)
		if (value >= start && value <= start + third - 1)
		{
			sort_perform_operation(p, ops, OP_PB);
			sort_perform_operation(p, ops, OP_RB);
		}
		//	Move to B (push to b)
		if (value >= start + third && value <= start + third * 2 - 1)
			sort_perform_operation(p, ops, OP_PB);
		//	Move to A (rotate a)
		if (value >= start + third * 2 && value <= start + sub.count - 1)
			sort_perform_operation(p, ops, OP_RA);
		i++;
	}
	//	Now do more substacks
	t_substack	sa = substack_set(ST_A, (sub.count - third - third), start + third * 2);
	substack_print(sa);
	if (sa.count > 2)
		substack_div(p, ops, sa);
	else
		substack_pushback(p, ops, sa);
	t_substack	sb = substack_set(ST_B, third, start + third);
	if (sb.count > 2)
		substack_div(p, ops, sb);
	else
		substack_pushback(p, ops, sb);
	t_substack	sc = substack_set(ST_C, third, start);
	if (sc.count > 2)
		substack_div(p, ops, sc);
	else
		substack_pushback(p, ops, sc);
}

t_substack	*substack_divide(t_program *p, t_ilist **ops, t_substack sub)
{
	t_substack	divided[3];
	int			third;
	int			modulo;

	third = sub.count / 3;
	modulo = sub.count % 3;

	/*substack_print(sub);
	if (sub.stack_type == ST_C)
	{
		divided[ST_C] = substack_set(ST_C, sub.stack_index, third, sub.value_start);
		divided[ST_B] = substack_set(ST_B, sub.stack_index + third, third, sub.value_start + third);
		divided[ST_A] = substack_set(ST_A, p->a->top, third + modulo, sub.value_start + third * 2);
	}
	if (sub.stack_type == ST_B)
	{
		divided[ST_C] = substack_set(ST_C, p->b->top, third, sub.value_start);
		divided[ST_B] = substack_set(ST_B, 0, third, sub.value_start + third);
		divided[ST_A] = substack_set(ST_A, p->a->top, third + modulo, sub.value_start + third * 2);
	}
	if (sub.stack_type == ST_A)
	{
		divided[ST_C] = substack_set(ST_C, p->b->top, third, sub.value_start);
		divided[ST_B] = substack_set(ST_B, 0, third, sub.value_start + third);
		divided[ST_A] = substack_set(ST_A, sub.stack_index, third + modulo, sub.value_start + third * 2);
	}
	substack_perform_divide(divided, sub.stack_type);*/

	substack_div(p, ops, sub);
	
	return (NULL);
}
