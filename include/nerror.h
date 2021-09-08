/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nerror.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 11:24:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 17:39:45 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NERROR_H
# define NERROR_H

# include <stdio.h>
# include <stdlib.h>

typedef enum e_error
{
	ERR_MALLOC = 0,
	ERR_GNL,
	ERR_UNKNOWN_OPERATION,
	ERR_STACK_SIZE_ZERO,
	ERR_DEFAULT
}	t_error;

void	error(t_error err);

#endif