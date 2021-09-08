/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 15:58:35 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 18:08:54 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ilist.h"
# include "operations.h"
# include "nerror.h"
# include "str.h"
# include "../lib/get_next_line/get_next_line.h"
# include "program.h"

void		checker_operations_perform(t_ilist *operations);
t_operation	checker_op_from_str(char *str);
t_ilist		*checker_operation_next(void);
t_ilist		*checker_operations_get(void);

#endif
