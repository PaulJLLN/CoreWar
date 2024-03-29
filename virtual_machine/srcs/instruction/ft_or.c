/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:07 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/16 16:30:09 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"

static void	ft_verbose(t_process *process, uint32_t param[3][2],
						long param_1, long param_2)
{
	int		i;

	ft_printf("P%5d | %s ", process->no,
	g_tab_instruction[process->opcode].name);
	i = 0;
	while (i < g_tab_instruction[process->opcode].nb_param - 1)
	{
		if (i == 0)
			ft_printf("%d ", param_1);
		else if (i == 1)
			ft_printf("%d ", param_2);
		i += 1;
	}
	ft_printf("r%d\n", param[2][0], process->carry);
}

void		ft_or(t_process *process, t_vm *vm)
{
	long	param_1;
	long	param_2;
	long	param_3;

	param_1 = ft_parameter_recover_value(vm, process->pc,
	vm->param[0], process);
	param_2 = ft_parameter_recover_value(vm, process->pc,
	vm->param[1], process);
	param_3 = vm->param[2][0];
	process->registre[vm->param[2][0] - 1] = param_1 | param_2;
	process->carry = (process->registre[vm->param[2][0] - 1] == 0 ? 1 : 0);
	if (vm->opt.v[1] & 4)
		ft_verbose(process, vm->param, param_1, param_2);
	ft_skip_instruction_sequency(process, vm);
}
