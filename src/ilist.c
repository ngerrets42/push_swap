/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ilist.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 12:20:45 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 12:22:02 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ilist.h"

t_ilist	*ilst_new(int content)
{
	t_ilist	*element;

	element = (t_ilist *)malloc(sizeof(t_ilist));
	if (element == NULL)
		return (NULL);
	element->i = content;
	element->next = NULL;
	return (element);
}

