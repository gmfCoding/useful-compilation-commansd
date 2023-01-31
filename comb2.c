/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:32:59 by clovell           #+#    #+#             */
/*   Updated: 2023/01/29 14:34:07 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void)
{
	int		first;
	int		second;
	char	temp[7];

	temp[2] = ' ';
	temp[5] = ',';
	temp[6] = ' ';
	first = 0;
	while (first < 100)
	{
		second = first + 1;
		while (second < 100)
		{
			temp[0] = (first / 10) + 48;
			temp[1] = (first % 10) + 48;
			temp[3] = (second / 10) + 48;
			temp[4] = (second % 10) + 48;
			write(1, temp, 7 - ((first == 98) * 2));
			second++;
		}	
		first++;
	}
}

#ifdef _MAIN_

int	main(void)
{
	ft_print_comb2();
	return (0);
}
#endif
