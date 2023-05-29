/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:15:10 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/29 21:35:22 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*init_player(int x, int y, int coins_count)
{
	t_player	*p;

	p = (t_player *)malloc(sizeof(t_player));
	if (!p)
		return (NULL);
	p->coins = 0;
	p->coins_count = coins_count;
	p->x = x;
	p->y = y;
	return (p);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num < -2147483648)
		return ;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}
