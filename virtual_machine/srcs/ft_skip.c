/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:39:28 by paul              #+#    #+#             */
/*   Updated: 2020/04/06 10:50:45 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include "../includes/tab.h"

void	ft_print_skip(t_vm *vm, t_process *process, int to_skip)
{
	int i;

	ft_printf("ADV %d (%#.4x -> %#.4x)", to_skip + 1, process->pc, process->pc + to_skip + 1);
	i = 0;
	while (i <= to_skip)
		ft_printf( " %.2x", vm->vm[(process->pc + i++) % MEM_SIZE]);
	ft_printf("\n");
}

int	ft_skip_one_parameter_field(t_vm *vm, int to_skip, const int j, const uint8_t opcode)
{
	if (vm->param[j][1] == REG_BIT)
		to_skip += 1;
	else if (vm->param[j][1] == IND_BIT)
		to_skip += 2;
	else if (vm->param[j][1] == DIR_BIT)
		to_skip += g_tab_instruction[opcode].dir_size;
	return (to_skip);
}

/*
**	Fonction qui va deplacer le PC lorsque l'instruction a été executer.
*/

void	ft_skip_instruction_sequency(t_process *process, t_vm *vm)
{
	int	to_skip;
	int	nb_param;
	int i;

	to_skip = 0;
	if (g_tab_instruction[process->opcode].ocp == TRUE)
		to_skip = 1;
	nb_param = g_tab_instruction[process->opcode].nb_param;
	i = 0;
	while (i < nb_param)
		to_skip = ft_skip_one_parameter_field(vm, to_skip, i++, process->opcode);
	ft_print_skip(vm, process, to_skip);
	ft_move_pc(process, to_skip + 1);
}

/*
**	Fonction qui va deplacer le pc dans le cas d'un OCP incorrect.
*/

int	ft_skip_bad_ocp_parsing(unsigned char ocp, t_process *process)
{
	int	nb_param;
	int	option;
	int	j;

	nb_param = g_tab_instruction[process->opcode].nb_param;
	process->pc += 1;
	j = 0;
	while (j < nb_param)
	{
		option = 0b11000000 & ocp;
		if (option == REG_BIT)
		{
			if (g_tab_instruction[process->opcode].param_type[j] & T_REG)
				process->pc += 1;
		}
		else if (option == IND_BIT)
		{
			if (g_tab_instruction[process->opcode].param_type[j] & T_IND)
				process->pc += 2;
		}
		else if (option == T_DIR)
		{
			if (g_tab_instruction[process->opcode].param_type[j] & T_DIR)
				process->pc += g_tab_instruction[process->opcode].dir_size;
		}
		else
		{
			process->pc += 1;
			return (ERROR);
		}
		ocp <<= 2;
		j += 1;
	}
	return (ERROR);
}