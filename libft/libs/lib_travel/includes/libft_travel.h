/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_travel.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 09:38:06 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/18 17:23:24 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TRAVEL_H
# define LIBFT_TRAVEL_H

# include "../../../includes/libft.h"

/*
**	Count on str :
*/

size_t			ft_strlen(const char *str);
int				ft_strmax(char *str1, char *str2);
int				ft_strmin(char *str1, char *str2);
int				count_int_in_str(char *str);
/*
**	Count on tab :
*/

int				ft_tablen(char **tab);

/*
**	Lib CTYPE and cmp on int :
*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);

int				ft_iseof(char c);
int				ft_intcmp(int one, int two);
int				ft_intlen(int n);

/*
**	cmp on str :
*/

int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlexicocmp(char *str1, char *str2);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnrchr(char *str, int pos, int n);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);

/*
**	cmp on mem :
*/

void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**	cmp on tab of str :
*/

int				ft_find_index_tab(char *search, char **tab, size_t len);

#endif
