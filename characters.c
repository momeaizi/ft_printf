/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:29:08 by momeaizi          #+#    #+#             */
/*   Updated: 2021/12/22 11:47:23 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_characters(char flag, int *count, va_list ptr, t_struct *strc)
{
	char	*str;
	int		str_len;

	if (flag == 's')
	{
		str = va_arg(ptr, char *);
		str_len = ft_strlen(str);
		if (strc->dot >= 0 && strc->dot < str_len)
			str_len = strc->dot;
		string(str, str_len, count, strc);
	}
	else
	{
		if (!strc->minus)
			print(strc->minfild - 1, ' ', count);
		ft_putchar(va_arg(ptr, int), count);
		if (strc->minus)
			print(strc->minfild - 1, ' ', count);
	}
}

void	string(char *str, int str_len, int *count, t_struct *strc)
{
	if (strc->dot >= 0)
	{
		if (!strc->minus)
			print(strc->minfild - str_len, ' ', count);
		ft_putstr_(str, str_len, count);
		if (strc->minus)
			print(strc->minfild - str_len, ' ', count);
	}
	else
	{
		if (!strc->minus)
			print(strc->minfild - str_len, ' ', count);
		ft_putstr(str, count);
		if (strc->minus)
			print(strc->minfild - str_len, ' ', count);
	}
}

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
		ft_putstr("(null)", count);
	else
		while (*str)
			ft_putchar(*str++, count);
}

void	ft_putstr_(char *str, int len, int *count)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr_("(null)", len, count);
	else
		while (str[i] && i < len)
			ft_putchar(str[i++], count);
}
