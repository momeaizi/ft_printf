/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:13:42 by momeaizi          #+#    #+#             */
/*   Updated: 2021/12/22 16:30:45 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init(t_struct *strc)
{
	strc->minus = 0;
	strc->plus = 0;
	strc->hash = 0;
	strc->space = 0;
	strc->minfild = 0;
	strc->zero = 0;
	strc->dot = -1;
}

int	ft_check(char *str, int *count, va_list ptr, t_struct *strc)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '-' || str[i] == '+' || str[i] == '#')
		ft_other_flag(str[i++], strc);
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
		ft_zero_flag(str, &i, strc);
	i += ft_print_flags(str[i], count, ptr, strc);
	return (i + 1);
}

int	ft_printf(const char *str, ...)
{
	va_list		ptr;
	int			count;
	t_struct	strc;

	count = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft_init(&strc);
			str += ft_check((char *)str + 1, &count, ptr, &strc);
		}
		else
			ft_putchar(*str, &count);
		str++;
	}
	return (count);
}
