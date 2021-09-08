/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 15:09:23 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/08 16:02:55 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdlib.h>

int		ft_atoi(const char *str);
int		str_is_str(const char *str1, const char *str2);
int		is_space(int c);
char	*str_trim_spaces(char *str);

#endif
