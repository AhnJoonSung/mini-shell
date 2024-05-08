/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:04:43 by moson             #+#    #+#             */
/*   Updated: 2024/05/09 01:48:56 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "my_builtins.h"
#include <string.h>

static int	print_pwd_err(const int errno_getcwd)
{
	char	*str;

	str = strerror(errno_getcwd);
	ft_putstr_fd("pwd: ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (errno_getcwd);
}

//	Return exit code of getcwd()
int	pwd_builtin(void)
{
	char	*buf;
	int		errno_getcwd;

	errno_getcwd = 0;
	buf = getcwd(NULL, 0);
	if (buf == NULL)
		errno_getcwd = errno;
	if (errno_getcwd == 0)
		ft_printf("%s\n", buf);
	else
		errno_getcwd = print_pwd_err(errno_getcwd);
	ft_free((void *)&buf);
	return (errno_getcwd);
}
