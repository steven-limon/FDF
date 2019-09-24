/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 23:04:05 by slimon            #+#    #+#             */
/*   Updated: 2019/05/26 22:17:05 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ns;
	int		i;
	long	num;

	num = (long)n;
	i = ft_longlen(num);
	if (!(ns = ft_strnew(i)))
		return (NULL);
	if (num == 0)
		ns[0] = '0';
	if (num < 0)
	{
		ns[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		ns[--i] = '0' + num % 10;
		num /= 10;
	}
	return (ns);
}
