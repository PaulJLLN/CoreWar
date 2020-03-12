/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2020/03/12 15:19:11 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/struct.h"
#include "../includes/prototypes.h"

t_instruction	g_tab_instruction[16] =
{
	{&ft_live, "live", 10, 1, 0, 4, {T_DIR}, {0}},
	{&ft_ld, "ld", 5, 2, 1, 4, {T_DIR | T_IND, T_REG}, {0}},
	{&ft_st, "st", 5, 2, 1, 0, {T_REG, T_IND | T_REG}, {0}},
	{&ft_add, "add", 10, 3, 1, 0, {T_REG, T_REG, T_REG}, {0}},
	{&ft_sub, "sub", 10, 3, 1, 0, {T_REG, T_REG, T_REG}, {0}},
	{&ft_and, "and", 6, 3, 1, 4,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}},
	{&ft_or, "or", 6, 3, 1, 4,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}},
	{&ft_xor, "xor", 6, 3, 1, 4,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}},
	{&ft_zjmp, "zjmp", 20, 1, 0, 2, {T_DIR}, {0}},
	{&ft_ldi, "ldi", 25, 3, 1, 2,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, {0}},
	{&ft_sti, "sti", 25, 3, 1, 2,
		{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, {0}},
	{&ft_fork, "fork", 800, 1, 0, 2, {T_DIR}, {0}},
	{&ft_lld, "lld", 10, 2, 1, 4, {T_DIR | T_IND, T_REG}, {0}},
	{&ft_lldi, "lldi", 50, 3, 1, 2,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, {0}},
	{&ft_lfork, "lfork", 1000, 1, 0, 2, {T_DIR}, {0}},
	{&ft_aff, "aff", 2, 1, 1, 0, {T_REG}, {0}}
};
