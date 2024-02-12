/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_ptr_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:24:48 by blarger           #+#    #+#             */
/*   Updated: 2023/12/14 11:53:38 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_to_hex(void *str)
{
	int					hex_len;
	unsigned long long	ptr_val;
	char				*hex_str;

	if (!str)
	{
		ft_putstr("0x0");
		return (3);
	}
	hex_len = get_hex_len((unsigned long long)str);
	hex_str = malloc((hex_len + 1) * sizeof(char));
	if (!hex_str)
		return (0);
	ptr_val = (unsigned long long)str;
	conv_hex_low(hex_len, ptr_val, hex_str);
	ft_putstr("0x");
	ft_putstr(hex_str);
	free(hex_str);
	return (hex_len + 2);
}

/* int main()
{
	char *str = "Hello World";
	ft_ptr_to_hex(str);
	printf("hex=%p\n", str);
} */
