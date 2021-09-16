/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 10:40:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/16 11:33:01 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "substack.h"

//	REMOVE
#include <stdio.h>
void	substack_print(t_substack sub)
{
	printf("substack\n	count: %d\n	stack_type: %d\n	value_start: %d\n	value_end: %d\n",
		sub.count, sub.stack_type, sub.value_start, sub.value_end);
}





static t_substack	substack_create(t_stype type, int count, int start_value)
{
	t_substack	sub;

	sub.count = count;
	sub.stack_type = type;
	sub.value_start = start_value;
	sub.value_end = start_value + count - 1;
	return (sub);
}

static void	substack_split_duos(t_substack sub[3], t_substack src)
{
	int			third;
	int			modulo;

	third = src.count / 3;
	modulo = src.count % 3;
	if (src.count <= 4)
	{
		sub[ST_A] = substack_create(ST_A, 2, src.value_start + modulo + 1);
		sub[ST_B] = substack_create(ST_B, 1 + modulo, src.value_start);
		sub[ST_C] = substack_create(ST_NONE, 0, 0);
	}
	else if (src.count == 5)
	{
		sub[ST_A] = substack_create(ST_A, 2, src.value_end - 1);
		sub[ST_B] = substack_create(ST_B, 2, src.value_end - 3);
		sub[ST_C] = substack_create(ST_C, 1, src.value_start);
	}
	else
	{
		sub[ST_A] = substack_create(ST_A, third + modulo, src.value_end - third + 1 - modulo);
		sub[ST_B] = substack_create(ST_B, third, src.value_end - (2 * third) + 1 - modulo);
		sub[ST_C] = substack_create(ST_C, third, src.value_start);
	}
}

/*
0
1
2
3
4
5
6
*/
static void	substack_split(t_substack sub[3], t_substack src)
{
	int			third;
	int			modulo;

	third = src.count / 3;
	modulo = src.count % 3;
	if (third >= 9)
	{
		sub[ST_A] = substack_create(ST_A, third + modulo, src.value_end - third + 1 - modulo);
		sub[ST_B] = substack_create(ST_B, third, src.value_end - (2 * third) + 1 - modulo);
		sub[ST_C] = substack_create(ST_C, third, src.value_start);
	}
	//Possibly nonsense:
	else if (src.count >= 9)
	{

		sub[ST_C] = substack_create(ST_C, 3, src.value_start);
		sub[ST_B] = substack_create(ST_B, 3, src.value_start + 3);
		sub[ST_A] = substack_create(ST_A, src.count - 6, src.value_end - (src.count - 6) + 1);
	}
	else
	{
		sub[ST_A] = substack_create(ST_A, 3, src.value_end - 2);
		sub[ST_C] = substack_create(ST_NONE, 0, 0);
		third = src.count - 3;
		if (third >= 3)
		{
			sub[ST_B] = substack_create(ST_B, 3, src.value_end - 5);
			third -= 3;
		}
		else
		{
			sub[ST_B] = substack_create(ST_B, third, src.value_start);
			third = 0;
		}
		if (third > 0)
			sub[ST_C] = substack_create(ST_C, third, src.value_start);
	}
	// printf("==SOURCE_STACK==\n");
	// substack_print(src);
	// printf("==CHILD_STACKS==\n");
	// substack_print(sub[ST_A]);
	// substack_print(sub[ST_B]);
	// substack_print(sub[ST_C]);
	// printf("================\n");
}

static void	substack_divide_next(t_program *p, t_ilist **ops, t_substack sub[3])
{
	if (sub[ST_A].count > 0)
		substack_divide(p, ops, sub[ST_A]);
	if (sub[ST_B].count > 0)
		substack_divide(p, ops, sub[ST_B]);
	if (sub[ST_C].count > 0)
		substack_divide(p, ops, sub[ST_C]);
}

/*static void	_sortback_if_able(t_program *p, t_ilist **ops)
{
	int	value;

	while (1)
	{
		value = p->a->size - p->a->top - 2;
		if (value == -1)
			return ;
		printf("value: %d\n", value);
		if (stack_get_bottom(p->a) == value)
		{
			sort_perform_operation(p, ops, OP_RRA);
			continue ;
		}
		else if (stack_get_top(p->b) == value)
		{
			sort_perform_operation(p, ops, OP_PA);
			continue ;
		}
		else if (stack_get_bottom(p->b) == value)
		{
			sort_perform_operation(p, ops, OP_RRB);
			sort_perform_operation(p, ops, OP_PA);
			continue ;
		}
		return ;
	}
}*/

void	substack_divide(t_program *p, t_ilist **ops, t_substack div)
{
	t_substack	sub[3];
	int			i;
	int			value;
	static int	sortback = 0;

	if (div.count <= SUBSTACK_TARGET_SIZE)
	{
		sortback = 1;
		return (substack_sortback(p, ops, div));
	}
	if (sortback == 1)
		substack_prepare(p, ops, div);
	substack_split(sub, div);
	i = 0;
	while (i < div.count)
	{
		value = stack_get_top(p->a);
		if (substack_contains_value(sub[ST_A], value))
			sort_perform_operation(p, ops, OP_RA);
		else if (sub[ST_C].stack_type != ST_NONE && substack_contains_value(sub[ST_C], value))
		{
			sort_perform_operation(p, ops, OP_PB);
			sort_perform_operation(p, ops, OP_RB);
		}
		else if (substack_contains_value(sub[ST_B], value))
			sort_perform_operation(p, ops, OP_PB);
		//else
		//	error(ERR_VALUE_NO_SUBSTACK);
		i++;
	}
	substack_divide_next(p, ops, sub);
}
