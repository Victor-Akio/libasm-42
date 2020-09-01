/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:05:16 by vminomiy          #+#    #+#             */
/*   Updated: 2020/09/02 01:47:13 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int			ft_strlen_t(char *str)
{
	int 	ret1;
	int 	ret2;

	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf("strlen : %d / ft_strlen : %d\n", ret1, ret2);
	if (ret1 == ret2)
		printf("" PASS "[OK] " RESET "");
	else
		printf("" FAIL "[KO] " RESET "");
	return (1);
}

int		main(void)
{
	/*
	**	ft_strlen
	*/
	//printf("%-42s : ", "ft_strlen.s");
	ft_strlen_t("Hellow World");
	printf("\n\n");
}