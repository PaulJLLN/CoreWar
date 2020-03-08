/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_virtual_machine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:27:38 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/05 16:32:44 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/virtual_machine.h"

void	ft_create_vm(unsigned char vm[MEM_SIZE])
{
	bzero(vm, MEM_SIZE);
	vm[0] = 4;
	vm[1] = 84;
	vm[2] = 2;
	vm[3] = 3;
	vm[4] = 4;
	vm[5] = 2;
	vm[6] = 144;
	vm[7] = 0;
	vm[8] = 0;
	vm[9] = 0;
	vm[10] = 54;
	vm[11] = 2;
	
	vm[2048] = 4;
	vm[2049] = 84;
	vm[2050] = 2;
	vm[2051] = 3;
	vm[2052] = 4;
	vm[2053] = 2;
	vm[2054] = 144;
	vm[2055] = 0;
	vm[2056] = 0;
	vm[2057] = 0;
	vm[2058] = 54;
	vm[2059] = 2;
}