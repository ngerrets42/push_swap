/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nerror.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 11:26:12 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/20 11:29:02 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "nerror.h"

static char	*err_get_msg(t_error err)
{
	static char	*err_list[ERR_DEFAULT + 1] =
	{
		[ERR_MALLOC] = "Something went wrong while allocating memory.\n",
		[ERR_GNL] = "Can't allocate memory or can't read from STDIN\n",
		[ERR_UNKNOWN_OPERATION] = "Unknown operation!\n",
		[ERR_STACK_SIZE_ZERO] = "Stack size is zero!\n",
		[ERR_STACK_DUPVALUE] = "Stack can't contain duplicates!\n",
		[ERR_STACK_NOT_SORTED] = "Stack not sorted!\n",
		[ERR_VALUE_NO_SUBSTACK] = "Value doesn't fit in any substack.\n",
		[ERR_WRITE] = "Write system-call failed!\n",
		[ERR_DEFAULT] = "UNKNOWN ERROR\n"
	};

	if (err > ERR_DEFAULT)
		err = ERR_DEFAULT;
	return (err_list[err]);
}

void	error(t_error err)
{
	char	*err_msg;

	err_msg = err_get_msg(err);
	putstr("Error\n- ");
	putstr(err_msg);
	exit(1);
}
