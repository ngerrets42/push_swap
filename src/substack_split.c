/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substack_split.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 10:40:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/17 16:25:00 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "substack.h"

static void	_split_equally(t_substack sub[3], t_substack src)
{
	int			third;
	int			modulo;

	third = src.count / 3;
	modulo = src.count % 3;
	sub[ST_A] = substack_create(ST_A, third + modulo,
			src.value_end - third + 1 - modulo);
	sub[ST_B] = substack_create(ST_B, third,
			src.value_end - (2 * third) + 1 - modulo);
	sub[ST_C] = substack_create(ST_C, third, src.value_start);
}

static void	_split_large_a(t_substack sub[3], t_substack src)
{
	sub[ST_C] = substack_create(ST_C, 3, src.value_start);
	sub[ST_B] = substack_create(ST_B, 3, src.value_start + 3);
	sub[ST_A] = substack_create(ST_A, src.count - 6,
			src.value_end - (src.count - 6) + 1);
}

static void	_split_small(t_substack sub[3], t_substack src)
{
	int	leftover;

	sub[ST_A] = substack_create(ST_A, 3, src.value_end - 2);
	sub[ST_C] = substack_create(ST_NONE, 0, 0);
	leftover = src.count - 3;
	if (leftover >= 3)
	{
		sub[ST_B] = substack_create(ST_B, 3, src.value_end - 5);
		leftover -= 3;
	}
	else
	{
		sub[ST_B] = substack_create(ST_B, leftover, src.value_start);
		leftover = 0;
	}
	if (leftover > 0)
		sub[ST_C] = substack_create(ST_C, leftover, src.value_start);
}

void	substack_split(t_substack sub[3], t_substack src)
{
	if (src.count / 3 >= 9)
		_split_equally(sub, src);
	else if (src.count >= 9)
		_split_large_a(sub, src);
	else
		_split_small(sub, src);
}
