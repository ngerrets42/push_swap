/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 15:23:39 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/07/15 17:46:58 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "operations.h"

int	sort(t_stack *a, t_stack *b);

void	recursive_sort(t_stack *stack);

#endif
