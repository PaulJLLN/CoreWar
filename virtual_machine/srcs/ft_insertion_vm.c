/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_vm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:59:05 by damboule          #+#    #+#             */
/*   Updated: 2020/06/16 16:24:12 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void		ft_cpy_printablechar(char *dst, unsigned char *src, int max)
{
	int		index;
	int		a;

	a = 0;
	index = 0;
	while (index < max && src[index])
	{
		dst[a] = src[index];
		a++;
		index++;
	}
	dst[index] = '\0';
	return ;
}

/*
** fonction leaks sur ft_itoa
*/

int			ft_players_data(int fd, char *player, int value_read, int arg)
{
	uint8_t	name[value_read];
	char	*char_tmp;

	if (read(fd, name, value_read) < value_read)
		return (EXIT_FAILURE);
	if (arg == 1 && ft_convert_to_int(name) != COREWAR_EXEC_MAGIC)
		return (EXIT_FAILURE);
	if (arg == 2)
		char_tmp = ft_itoa(ft_convert_to_int(name));
	if (arg == 2 && ft_strcpy(player, char_tmp))
	{
		free(char_tmp);
		return (EXIT_SUCCESS);
	}
	ft_cpy_printablechar(player, name, value_read);
	return (EXIT_SUCCESS);
}

int			ft_read(const char *filecor,
				unsigned char vm[MEM_SIZE], int write_pos, t_player *player)
{
	char	skip[NOT_READ + 1];
	int		fd;
	int		length;

	if ((fd = open(filecor, O_RDONLY)) == -1)
		return (ft_usage(FILECOR, NULL, 0));
	if (ft_players_data(fd, player->magic, MAGIC, HEADER))
		return (ft_usage(MC_HEADER, (char*)filecor, 0));
	if (ft_players_data(fd, player->name, READ_NAME, NO_ARGS))
		return (ft_usage(SIZE_NAME, (char*)filecor, 0));
	read(fd, skip, NOT_READ);
	if (ft_players_data(fd, player->size, READ_EXEC, 2))
		return (ft_usage(SIZE_EXEC, (char*)filecor, 0));
	if (ft_players_data(fd, player->comment, READ_COM, NO_ARGS))
		return (ft_usage(SIZE_COMM, (char*)filecor, 0));
	read(fd, skip, NOT_READ);
	if ((length = read(fd, vm + write_pos, MEM_SIZE + 1)) > TO_READ)
		return (ft_usage(SIZE_EXEC, (char*)filecor, length));
	if (ft_check_int(player->size) || atoi(player->size) != length)
		return (ft_usage(CODE_SIZE, (char*)filecor, length));
	return (EXIT_SUCCESS);
}

int			ft_create_player(t_player *player, t_args *filecor, int value,
					unsigned char vm[MEM_SIZE])
{
	int		i;
	int		write_pos;

	i = 0;
	while (i < filecor->player_nb)
	{
		if (filecor->option[i] == value)
		{
			player->index_player = value;
			write_pos = (MEM_SIZE / filecor->player_nb) * (value - 1);
			if (ft_read(filecor->champ[i], vm, write_pos, player))
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		i += 1;
	}
	return (EXIT_FAILURE);
}

int			ft_insertion_vm(t_args *filecor,
						unsigned char vm[MEM_SIZE], t_player player[4])
{
	int		i;

	i = 0;
	while (i < filecor->player_nb)
	{
		if (ft_create_player(&player[i], filecor, i + 1, vm))
			return (EXIT_FAILURE);
		i += 1;
	}
	return (EXIT_SUCCESS);
}
