/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_display.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 09:35:41 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/18 13:17:46 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DISPLAY_H
# define LIBFT_DISPLAY_H

# include "../../../includes/libft.h"

/*
** display char :
*/

void			ft_putchar(char c);
void			ft_put_n_char(char character, unsigned int len);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar_color(char *color, char c);
void			ft_putchar_color_fd(char *color, char c, int fd);

/*
** display int :
*/

void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_color(char *str, int n);
void			ft_putnbr_color_fd(char *str, int n, int fd);
void			ft_before_nbr(char c, int len, int nbr);
void			ft_after_nbr(char c, int len, int nbr);

/*
** display str :
*/

void			ft_putstr(char const *s);
void			ft_puts_until(char *str, unsigned int len);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr_color(char *color, char *str);
void			ft_putstr_color_fd(char *color, char *str, int fd);
void			ft_before_str(char c, int len, char *str);
void			ft_after_str(char c, int len, char *str);
void			ft_putendl(char *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl_color(char *color, char *str);
void			ft_putendl_color_fd(char *color, char *str, int fd);
void			ok(void);

/*
** display tab str :
*/

void			ft_aff_tabc(char **tab);

#endif
