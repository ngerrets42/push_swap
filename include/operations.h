/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 14:23:36 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 18:05:23 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "program.h"

typedef enum e_operation
{
	OP_SA = 0,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_operation;

char		**operation_list(void);
void		*operation_get_function(t_operation operation);

void		operation_sa(t_program *program);
void		operation_sb(t_program *program);
void		operation_ss(t_program *program);
void		operation_pa(t_program *program);
void		operation_pb(t_program *program);
void		operation_ra(t_program *program);
void		operation_rb(t_program *program);
void		operation_rr(t_program *program);
void		operation_rra(t_program *program);
void		operation_rrb(t_program *program);
void		operation_rrr(t_program *program);

#endif
