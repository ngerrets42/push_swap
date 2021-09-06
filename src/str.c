/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:01:15 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/06 14:01:23 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	str_is_str(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
