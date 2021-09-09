/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 13:52:53 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 11:00:33 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

char	**operation_list(void)
{
	static char	*oplist[OP_COUNT] =
	{
		[OP_SA] = "sa",
		[OP_SB] = "sb",
		[OP_SS] = "ss",
		[OP_PA] = "pa",
		[OP_PB] = "pb",
		[OP_RA] = "ra",
		[OP_RB] = "rb",
		[OP_RR] = "rr",
		[OP_RRA] = "rra",
		[OP_RRB] = "rrb",
		[OP_RRR] = "rrr"
	};

	return (oplist);
}

void	*operation_get_function(t_operation operation)
{
	static void	*oplist[OP_COUNT] =
	{
		[OP_SA] = operation_sa,
		[OP_SB] = operation_sb,
		[OP_SS] = operation_ss,
		[OP_PA] = operation_pa,
		[OP_PB] = operation_pb,
		[OP_RA] = operation_ra,
		[OP_RB] = operation_rb,
		[OP_RR] = operation_rr,
		[OP_RRA] = operation_rra,
		[OP_RRB] = operation_rrb,
		[OP_RRR] = operation_rrr
	};

	return (oplist[operation]);
}
