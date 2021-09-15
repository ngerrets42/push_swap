/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 15:23:39 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/15 17:25:08 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "ilist.h"
# include "program.h"
# include "operations.h"

t_ilist	*sort(void);
void	sort_perform_operation(t_program *program, t_ilist **operations, t_operation op);
int		sort_reduce_operations(t_ilist **ops);

#endif
