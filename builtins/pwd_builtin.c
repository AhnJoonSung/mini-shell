/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:04:43 by moson             #+#    #+#             */
/*   Updated: 2023/11/16 23:04:44 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "builtins.h"

//	Return PWD_EXIT_CODE
int	pwd_builtin(t_sh_data *sh_data, t_proc *proc)
{
	char	*buf;

	if (sh_data == NULL || proc == NULL)
		return (PWD_ARGS_ERROR);
	buf = getcwd(NULL, 0);
	if (buf == NULL)
		return (PWD_MALLOC_FAILED);
	ft_printf("%s\n", buf);
	free(buf);
	buf = NULL;
	return (PWD_SUCCESS);
}
