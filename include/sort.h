/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 15:23:39 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/09 11:27:43 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "ilist.h"
# include "program.h"
# include "operations.h"

t_ilist	*sort(void);
void	sort_perform_operaton(t_program *program, t_ilist **operations, t_operation op);

#endif
