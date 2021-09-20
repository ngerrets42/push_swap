/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 15:09:23 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/20 12:30:25 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *str);
long int	ft_atol(const char *str);
char		**ft_split(char const *str, char c);
int			str_is_str(const char *str1, const char *str2);
int			is_space(int c);
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*str_trim_spaces(char *str);
int			putstr(char *str);

#endif
