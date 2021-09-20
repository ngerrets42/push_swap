/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:01:15 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/20 11:26:22 by ngerrets      ########   odam.nl         */
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

int	is_space(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	_count_spaces(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count += is_space(str[i]);
		i++;
	}
	return (count);
}

char	*str_trim_spaces(char *str)
{
	int		i;
	int		count;
	char	*new_str;

	count = _count_spaces(str);
	new_str = malloc(sizeof(char) * (ft_strlen(str) - count + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!is_space(str[i]))
		{
			new_str[count] = str[i];
			count++;
		}
		i++;
	}
	new_str[count] = '\0';
	free(str);
	return (new_str);
}

int	putstr(char *str)
{
	return (write(STDOUT_FILENO, str, ft_strlen(str) * sizeof(char)));
}
