/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nerror.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 11:24:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/30 10:44:31 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NERROR_H
# define NERROR_H

# ifndef ERROR_MSG
#  define ERROR_MSG 0
# endif

# include <stdlib.h>
# include "str.h"

typedef enum e_error
{
	ERR_MALLOC = 0,
	ERR_GNL,
	ERR_UNKNOWN_OPERATION,
	ERR_STACK_SIZE_ZERO,
	ERR_STACK_DUPVALUE,
	ERR_STACK_NOT_SORTED,
	ERR_VALUE_NO_SUBSTACK,
	ERR_WRITE,
	ERR_NOT_INT,
	ERR_NOT_A_NUMBER,
	ERR_DEFAULT
}	t_error;

void	error_exit(t_error err);
void	error_display(t_error err);

#endif
