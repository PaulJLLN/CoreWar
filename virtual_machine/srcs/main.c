/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:31:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/07 09:21:00 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/debug.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include <stdbool.h>

int		main(int ac, char **av)
{
	t_vm			vm;

	if (ft_initialisation(&vm) == false)
		return (false);
	if (ft_parse(ac - 1, av + 1, &vm))
		return (false);
	if (!ft_processus_player_initialisation(&vm))
		return (false);
	if (vm.opt.d[0] == true)
		ft_loop_dumped(&vm, vm.tab);
	else
		ft_loop_std(&vm, vm.tab);
	return (0);
}
