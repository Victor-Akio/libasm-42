/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:05:16 by vminomiy          #+#    #+#             */
/*   Updated: 2020/09/02 09:33:48 by vminomiy         ###   ########.fr       */
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
		printf("" PASS "[OK]\n " RESET "");
	else
		printf("" FAIL "[KO]\n " RESET "");
	return (1);
}

int			ft_strcpy_t(char *src)
{
	char	dst1[BUFFER_SIZE];
	char	dst2[BUFFER_SIZE];

	bzero(dst1, BUFFER_SIZE);
	bzero(dst2, BUFFER_SIZE);
	ft_strcpy(dst1, src);
	strcpy(dst2, src);
	printf("strcpy : %s / ft_strcpy : %s\n", dst2, dst1);
	if (!strcmp(dst1, dst2))
		printf("" PASS "[OK]\n " RESET "");
	else
		printf("" FAIL "[KO]\n " RESET "");
	return (1);
}

int			ft_strcmp_t(char *s1, char *s2)
{
	int		ret1;
	int		ret2;

	ret1 = ft_strcmp(s1, s2);
	ret2 = strcmp(s1, s2);
	printf("strcmp : %d / ft_strcmp : %d\n", ret1, ret2);
	if ((ret1 > 0 && ret2 > 0) || (ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 == 0))
		printf("" PASS "[OK]\n " RESET "");
	else
		printf("" FAIL "[KO]\n " RESET "");
	return (1);
}

int			main(void)
{
	/*
	**	ft_strlen
	*/
	printf("%-42s : ", "ft_strlen.s");
	ft_strlen_t("Hellow World!");
	ft_strlen_t("168416432");
	ft_strlen_t("Hellow\t World!");
	ft_strlen_t("Hellow \0World!");
	ft_strlen_t("   ");
	ft_strlen_t("");
	printf("\n\n");

	/*
	** ft_strcpy
	*/
	ft_strcpy_t("Hellow World!");
	ft_strcpy_t("\t@caps");
	ft_strcpy_t("");
	ft_strcpy_t(" ");
	ft_strcpy_t("Hellow\0 World!");
	printf("\n\n");

	/*
	** ft_strcmp
	*/
	ft_strcmp_t("Hellow World!", "Hellow World!");
	ft_strcmp_t("Hellow", "World!");
	ft_strcmp_t("Hellow World!", "");
	ft_strcmp_t("", "Hellow World!");
	ft_strcmp_t("Hellow World!", " ");
	ft_strcmp_t("", "");
	ft_strcmp_t(" ", " ");
	ft_strcmp_t("Hellow\0 World!", " crazy");
	printf("\n\n");
}