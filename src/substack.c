/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 11:51:21 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/10 19:45:29 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "substack.h"
#include "sort.h"

#define SUBSTACK_MIN_SIZE 2

static int	g_counter = 0;

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
	sub.value_start= 0;
	sub.count = stack->top + 1;
	return (sub);
}

t_substack	substack_set(t_stype type, int count, int start_value)
{
	t_substack	sub;

	sub.count = count;
	sub.stack_type = type;
	sub.value_start= start_value;
	return (sub);
}

void	substack_single_to_a(t_program *p, t_ilist **ops, t_substack sub)
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
}

void	substack_prepare(t_program *p, t_ilist **ops, t_substack sub)
{
	int	i;

	i = 0;
	while (i < sub.count)
	{
		if (sub.stack_type == ST_C)
			g_counter++;
		g_counter++;
		substack_single_to_a(p, ops, sub);
		i++;
	}
}

void	substack_sortback(t_program *p, t_ilist **ops, t_substack sub)
{
	int	i;

	i = 0;
	while (i < sub.count)
	{
		substack_single_to_a(p, ops, sub);
		i++;
	}
	if (stack_get_top(p->a) > stack_get_second(p->a))
		sort_perform_operation(p, ops, OP_SA);
}

void	substack_set_and_div(t_program *p, t_ilist **ops, t_substack sub)
{
	int			third;
	t_substack	div[3];

	third = sub.count / 3;
	div[ST_A] = substack_set(ST_A, (sub.count - third - third),
		sub.value_start+ third * 2);
	substack_div(p, ops, div[ST_A]);
	div[ST_B] = substack_set(ST_B, third, sub.value_start + third);
	substack_div(p, ops, div[ST_B]);
	div[ST_C] = substack_set(ST_C, third, sub.value_start);
	substack_div(p, ops, div[ST_C]);
}

void	substack_div_small(t_program *p, t_ilist **ops, t_substack sub)
{
	int			i;
	int			value;
	t_substack	div[2];

	substack_prepare(p, ops, sub);
	i = 0;
	while (i < sub.count)
	{
		value = stack_get_top(p->a);
		if (value == -1)
			return ;
		//	Move 2 to B
		if (value >= sub.value_start && value <= sub.value_start + 1)
			sort_perform_operation(p, ops, OP_PB);
		//	Move 1 to A
		if (value == sub.value_start + 2)
			sort_perform_operation(p, ops, OP_RA);
		i++;
	}
	div[ST_A] = substack_set(ST_A, 1, sub.value_start + 2);
	substack_sortback(p, ops, div[ST_A]);
	div[ST_B] = substack_set(ST_B, 2, sub.value_start);
	substack_sortback(p, ops, div[ST_B]);
}

void	substack_div(t_program *p, t_ilist **ops, t_substack sub)
{
	int	i;
	int	third;
	int	value;

	third = sub.count / 3;
	//substack_print(sub);
	/*if (sub.count == 3)
	{
		substack_div_small(p, ops, sub);
		return ;
	}*/
	// sortback
	if (sub.count <= SUBSTACK_MIN_SIZE)
	{
		substack_sortback(p, ops, sub);
		return ;
	}
	//	Move all to top of a-stack
	if (p->b->top > 0)
		substack_prepare(p, ops, sub);
	i = 0;
	while (i < sub.count)
	{
		value = stack_get_top(p->a);
		//	Move to C (push to b and rotate b)
		if (value >= sub.value_start && value <= sub.value_start + third - 1)
		{

			g_counter += 2;

			sort_perform_operation(p, ops, OP_PB);
			sort_perform_operation(p, ops, OP_RB);
		}
		//	Move to B (push to b)
		else if (value >= sub.value_start + third && value <= sub.value_start + third * 2 - 1)
		{

			g_counter++;

			sort_perform_operation(p, ops, OP_PB);
		}
		//	Move to A (rotate a)
		else
		{

			g_counter++;

			sort_perform_operation(p, ops, OP_RA);
		}
		i++;
	}
	//	Now do more substacks
	substack_set_and_div(p, ops, sub);
}

t_substack	*substack_divide(t_program *p, t_ilist **ops, t_substack sub)
{

	substack_div(p, ops, sub);
	printf("COUNTER: %d\n", g_counter);
	return (NULL);
}
