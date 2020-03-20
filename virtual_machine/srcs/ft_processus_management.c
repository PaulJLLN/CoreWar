/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:28:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/20 16:39:01 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../includes/virtual_machine.h"
#include "../includes/tab.h"
#include "../includes/debug.h"

/*
**	Fonction qui déplace correctement le PC d'une certaine valeur.
*/

void	ft_move_pc(t_process *process, int value)
{
	process->pc = (process->pc + value) % MEM_SIZE;
}

t_process	*ft_process_move(t_process *process, t_process *tab[1024], int cycle, int cycle_to_add)
{
	t_process	*tmp;

	tmp = process->next;
	process->next = tab[(cycle + cycle_to_add) % 1024];
	tab[cycle % 1024] = tmp;
	return (process);
}

t_process	*ft_create_processus(int nb_player, size_t pc, unsigned char opcode)
{
	t_process *process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	bzero(process->registre, sizeof(process->registre));
	if (nb_player > 0 && nb_player <= LIMIT_CHAMP)
		process->registre[0] = -nb_player;
	else
	{
		free(process);
		return (NULL);
	}
	process->no = nb_player;
	process->pc = pc;
	process->carry = 0;
	process->cycle_left = 0;
	process->opcode = opcode;
	process->next = NULL;
	return (process);
}

void	ft_add_process(t_process *tab[1024], t_process *process)
{
	t_process	*h_tmp;
	t_process	*local;

	h_tmp = tab[0];
	local = tab[0];
	if (tab[0] == NULL)
		tab[0] = process;
	else
	{
		process->next = local;
		tab[0] = process;
		ft_reset_begin_process_list(tab[0]);
	}
}

void	ft_add_process_list(t_vm *vm, t_process *process)
{
	int	i;

	vm->nb_process += 1;
	if (vm->nb_process > vm->nb_max_process)
		vm->process_list = realloc(vm->process_list, vm->nb_max_process * 2);
	i = 0;
	while (vm->process_list[i] != 0)
	{
		i += 1;
	}
	vm->process_list[i] = process;
}

int	ft_create_processus_list(int nb_player, t_process *tab[1024], t_vm *vm)
{
	int	i;
	size_t	pc;
	t_process *process;

	i = 0;
	while (i < nb_player)
	{
		pc = (MEM_SIZE / nb_player) * i;
		if(!(process = ft_create_processus(i + 1, pc, vm->vm[pc] - 1)))
			return (ERROR);
		ft_add_process(tab + g_tab_instruction[process->opcode].cycle_to_exec, process);
		ft_add_process_list(vm, process);
		i += 1;
	}
	return (TRUE);
}
