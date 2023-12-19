/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:02:23 by gdetourn          #+#    #+#             */
/*   Updated: 2023/12/19 09:50:49 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *ret);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *ret);
void	ft_putnbr_base(long int nbr, char *base, int *ret);
void	ft_putnbr_b_un(unsigned int nbr, char *base, int *ret);
void	ft_pnbr_p(unsigned long nbr, char *base, int *ret);
int		ft_check_type(va_list	args, const char *format, int *ret);

#endif