/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:13:26 by momeaizi          #+#    #+#             */
/*   Updated: 2021/12/22 16:30:29 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_atoi(char *str, int *index)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	*index += i;
	return (nb);
}

void	ft_zero_flag(char *str, int *i, t_struct *strc)
{
	int	nb;

	nb = 0;
	if (str[*i] == '0')
	{
		nb = ft_atoi(str + (*i), i);
		if (str[*i] == '.')
		{
			strc->minfild = nb;
			strc->dot = ft_atoi(str + (++(*i)), i);
		}
		else
			strc->zero = nb;
	}
	else if (str[*i] == '.')
		strc->dot = ft_atoi(str + (++(*i)), i);
	else
	{
		strc->minfild = ft_atoi(str + *i, i);
		if (str[*i] == '.')
			strc->dot = ft_atoi(str + (++(*i)), i);
	}
}

void	ft_other_flag(char c, t_struct *strc)
{
	if (c == '-')
		strc->minus = 1;
	else if (c == '+')
		strc->plus = 1;
	else if (c == '#')
		strc->hash = 1;
	else if (c == ' ')
		strc->space = 1;
}

int	ft_print_flags(char c, int *count, va_list	ptr, t_struct *strc)
{
	if (c == 's' || c == 'c')
		ft_characters(c, count, ptr, strc);
	else if (c == 'd' || c == 'i')
		ft_decimal(count, ptr, strc);
	else if (c == 'x' || c == 'X')
		ft_hexa(c, count, ptr, strc);
	else if (c == 'u')
		ft_unsigned(count, ptr, strc);
	else if (c == 'p')
		ft_address(count, ptr, strc);
	else if (c == '%')
		ft_putchar('%', count);
	else
		return (-1);
	return (0);
}
