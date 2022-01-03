/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:13:58 by momeaizi          #+#    #+#             */
/*   Updated: 2021/12/22 16:37:34 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include<stdarg.h>
# include<unistd.h>

typedef struct t_struct{
	int	minus;
	int	plus;
	int	hash;
	int	space;
	int	minfild;
	int	zero;
	int	dot;
}		t_struct;

//ft_printf
int		ft_printf(const char *str, ...);
int		ft_check(char *str, int *count, va_list ptr, t_struct *strc);
void	ft_init(t_struct *strc);
//ft_flags
void	ft_other_flag(char c, t_struct *strc);
void	ft_zero_flag(char *str, int *i, t_struct *strc);
int		ft_atoi(char *str, int *index);
int		ft_print_flags(char c, int *count, va_list	ptr, t_struct *str);
//characters
void	ft_characters(char flag, int *count, va_list ptr, t_struct *strc);
void	string(char *str, int str_len, int *count, t_struct *strc);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putstr_(char *str, int len, int *count);
//functions
void	ft_decimal(int *count, va_list ptr, t_struct *strc);
void	ft_negative(int nbr, int nbr_len, int *count, t_struct *strc);
void	ft_positive(int nbr, int nbr_len, int *count, t_struct *strc);
char	splus(char c, t_struct *strc);
void	dot_zero(int nbr_len, int *count, t_struct *strc);
//functions1
int		ft_strlen(char	*str);
int		get_nbrlen(unsigned long int nbr, int base);
void	print(int len, char c, int *count);
void	ft_putnbr(unsigned long int nbr, int base, int alpha, int *count);
void	hex(unsigned int nbr, char c, int *count);
//functions2
void	ft_address(int *count, va_list	ptr, t_struct *strc);
void	ft_unsigned(int *count, va_list ptr, t_struct *strc);
void	ft_hexa(char c, int *count, va_list	ptr, t_struct *strc);
void	hash(char c, int *count);
#endif
