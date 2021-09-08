/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ilist.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 12:19:31 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 12:23:43 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILIST_H
# define ILIST_H

# include <stddef.h>

typedef struct s_ilist
{
	int				i;
	struct s_ilist	*next;
}					t_ilist;

t_ilist	*ilst_new(int content);

#endif
