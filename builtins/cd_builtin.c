/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:04:26 by moson             #+#    #+#             */
/*   Updated: 2023/11/16 23:04:27 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "builtins.h"

//	Return arguments length
static int	get_args_len(char **args)
{
	int	len;

	if (args == NULL)
		return (0);
	len = 0;
	while (args[len] != NULL)
		len++;
	return (len);
}

//	Return CD_EXIT_CODE
//	Error message -> STDERR
int	cd_builtin(t_sh_data *sh_data, t_proc *proc)
{
	int	args_len;

	args_len = get_args_len(proc->args);
	if (args_len == 0)
	{
		
	}
	else if (args_len == 1)
	{

	}
	else	// TOO MANY ARGS
	{

	}

	if (access(proc->args))
}

