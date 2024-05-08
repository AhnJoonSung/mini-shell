/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:34:52 by moson             #+#    #+#             */
/*   Updated: 2024/05/09 01:44:51 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "my_builtins.h"

int	search_env_content(t_list *env_list, char *key, t_node	**res);

static int	print_unset_err(const int errno_unset)
{
	char	*str;

	if (errno_unset == UNSET_NULPTR)
		str = UNSET_NULPTR_MSG;
	else if (errno_unset == UNSET_UNKNOWN)
		str = UNSET_UNKNOWN_MSG;
	else
		str = UNKNOWN_MSG;
	ft_putstr_fd("unset: ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (errno_unset);
}

//	Return exit code one of below:
//	SUCCESS = UNSET_NOTEXIST
//	UNSET_NULPTR
//	UNSET_UNKNOWN
int	unset_builtin(t_sh_data *sh_data, t_proc *proc)
{
	t_node	*node;
	int		search_res;
	int		cnt;

	if (sh_data == NULL || sh_data->env_list == NULL)
		return (print_unset_err(UNSET_NULPTR));
	cnt = 0;
	while (proc->args[++cnt] != NULL)
	{
		search_res = search_env_content \
		(sh_data->env_list, proc->args[cnt], &node);
		if (search_res == FT_FALSE)
			return (print_unset_err(UNSET_UNKNOWN));
		if (node == NULL)
			return (UNSET_NOTEXIST);
		ft_del_node_and_link(sh_data->env_list, node, ft_del_env);
	}
	return (SUCCESS);
}
