/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ilist.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 12:19:31 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/30 11:05:56 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILIST_H
# define ILIST_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_ilist
{
	int				i;
	struct s_ilist	*next;
}					t_ilist;

t_ilist	*ilst_new(int content);
t_ilist	*ilst_last(t_ilist *lst);
void	ilst_add_back(t_ilist **lst, t_ilist *element);
void	ilst_destroy_element(t_ilist *element);
void	ilst_destroy(t_ilist *lst);

#endif
