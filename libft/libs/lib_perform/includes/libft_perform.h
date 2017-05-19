/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_perform.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 09:37:33 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/23 19:02:12 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PERFORM_H
# define LIBFT_PERFORM_H

# include "../../../includes/libft.h"

/*
**	perform on int :
*/

void			ft_swapi(int *a, int *b);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_itoa(int n);
int				*ft_strc_to_stri(char *str);
int				**ft_tabc_to_tabi(char **tabc);

/*
**	perform on str :
*/

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_swap(char *a, char *b);
void			ft_swap_str(char **str1, char **str2);
char			*ft_strupper(char *str);
char			*ft_strlower(char *str);
int				ft_atoi(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strrev(char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strtrim(char const *s);
char			*ft_strcpy(char *dst, char const *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strdup(char const *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_multijoin(char *ret, char *str1, char *str2, char *str3);
char			*ft_free_and_join(char *str1, char *str2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_cutstr(char *str, char c);
char			*ft_charreplace(char *replaced, char search, char replace);
char			*ft_strreplace(char *replaced, char *search, char *replace);

/*
**	perform on tabc :
*/

void			ft_sort_ascii_tab(char **tab);
char			**ft_tab_dup(char **tab);
char			**ft_strsplit(char const *s, char c);
char			**ft_tabreplace(char **replaced, char *search, char *replace);

/*
**	perform on mem :
*/

void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);

/*
**	dels :
*/

void			ft_strclr(char *s);
void			ft_memdel(void **ap);
void			ft_bzero(void *s, size_t n);
void			ft_strdel(char **as);
void			ft_multifruee(char **str1, char **str2, char **str3);
void			ft_tabclr(char **tab);

#endif
