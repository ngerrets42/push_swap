/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 15:23:39 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/17 13:29:23 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "ilist.h"
# include "program.h"
# include "operations.h"

t_ilist	*sort(void);
void	sort_perform_operation(t_program *p, t_ilist **ops, t_operation op);
int		sort_reduce_operations(t_ilist **ops);

#endif
