/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:05:16 by vminomiy          #+#    #+#             */
/*   Updated: 2020/09/08 21:07:54 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

int			ft_strlen_t(char *str)
{
	int 	ret1;
	int 	ret2;

	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf("strlen : %d / ft_strlen : %d\n", ret1, ret2);
	if (ret1 == ret2)
		printf("" PASS "[OK]\n" RESET "");
	else
		printf("" FAIL "[KO]\n" RESET "");
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
		printf("" PASS "[OK]\n" RESET "");
	else
		printf("" FAIL "[KO]\n" RESET "");
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
		printf("" PASS "[OK]\n" RESET "");
	else
		printf("" FAIL "[KO]\n" RESET "");
	return (1);
}

/*
** F_SETFL - Set the file descriptor flags to the value specified by arg.
** O_NONBLOCK - if specified, open will return immediately without a carrier. 
** pipe - This creates both the reading and writing ends of the pipe. 
*/
int			ft_write_t(char *str)
{
	int			pipeline[2];
	char		buf[BUFFER_SIZE];
	int			ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(pipeline) < 0)
		exit(EXIT_FAILURE);
	fcntl(pipeline[0], F_SETFL, O_NONBLOCK);
	ft_write(pipeline[1], str, strlen(str));
	ret = read(pipeline[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';
	errno = 0;
	//printf("%d\n", errno);
	printf("write : \"%s\" / ft_write : \"%s\"\n", str, buf);
	//ft_write(42, "Error tester\n", 13);
	//printf("%d\n", errno);
	//printf("write_len : \"%zi\" / ft_write_len : \"%zi\"\n", write(1, str, strlen(str)), ft_write(1, buf, strlen(buf)));
	if (!strcmp(buf, str))
		printf("" PASS "[OK]\n" RESET "");
	else
		printf("" FAIL "[KO]\n" RESET "");
	close(pipeline[1]);
	close(pipeline[0]);
	return (1);
}

int			ft_read_t(char *str)
{
	int		pipeline[2];
	char	buf[BUFFER_SIZE];
	int		ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(pipeline) < 0)
		exit(EXIT_FAILURE);
	fcntl(pipeline[0], F_SETFL, O_NONBLOCK);
	write(pipeline[1], str, strlen(str));
	ret = ft_read(pipeline[0], buf, BUFFER_SIZE);
	//ret = ft_read(STDIN_FILENO, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	printf("str : \"%s\" / What was read : \"%s\"\n", str, buf);
	if (!strcmp(buf, str))
		printf("" PASS "[OK]\n" RESET "");
	else
		printf("" FAIL "[KO]\n" RESET "");
	close(pipeline[1]);
	close(pipeline[0]);
	return (1);
}

int			ft_strdup_t(char *str)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup(str);
	s2 = strdup(str);
	printf("strdup : \"%s\" / ft_strdup : \"%s\"\n", s2, s1);
	if (!strcmp(s1, s2))
		printf("" PASS "[OK]\n" RESET "");
	else
		printf("" FAIL "[KO]\n" RESET "");
	free(s1);
	free(s2);
	return (1);
}

int			main(void)
{
	/*
	**	ft_strlen
	*/
	printf("%s", "ft_strlen.s\n");
	ft_strlen_t("Hellow World!");
	ft_strlen_t("168416432");
	ft_strlen_t("Hellow\t World!");
	ft_strlen_t("Hellow \0World!");
	ft_strlen_t("   ");
	ft_strlen_t("");
	ft_strlen_t("esta frase eh bem grande, tem 112 letras e com muitos aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaas");
	printf("\n\n");

	/*
	** ft_strcpy
	*/
	printf("%s", "ft_strcpy.s\n");
	ft_strcpy_t("Hellow World!");
	ft_strcpy_t("\t@caps");
	ft_strcpy_t("");
	ft_strcpy_t(" ");
	ft_strcpy_t("Hellow\0 World!");
	printf("\n\n");

	/*
	** ft_strcmp
	*/
	printf("%s", "ft_strcmp.s\n");
	ft_strcmp_t("Hellow World!", "Hellow World!");
	ft_strcmp_t("Hellow", "World!");
	ft_strcmp_t("Hellow World!", "");
	ft_strcmp_t("", "Hellow World!");
	ft_strcmp_t("Hellow World!", " ");
	ft_strcmp_t("", "");
	ft_strcmp_t(" ", " ");
	ft_strcmp_t("uvaf", "uva");
	ft_strcmp_t("Hellow\0 World!", " crazy");
	printf("\n\n");

	/*
	** ft_write
	*/
	printf("%s", "ft_write.s\n");
	ft_write_t("Hellow World!");
	ft_write_t("42");
	ft_write_t("    ");
	ft_write_t("");
	ft_write_t("Hellow \tworld!");
	ft_write_t("Hellow\0World");
	printf("\n\n");

	/*
	** ft_read
	*/
	printf("%s", "ft_read.s\n");
	ft_read_t("Hellow World!");
	ft_read_t("42");
	ft_read_t("    ");
	ft_read_t("");
	ft_read_t("Hellow \tworld!");
	ft_read_t("Hellow\0World");
	printf("\n\n");

	/*
	** ft_strdup
	*/
	printf("%s", "ft_strdup.s\n");
	ft_strdup_t("Hellow World!");
	ft_strdup_t("42");
	ft_strdup_t("    ");
	ft_strdup_t("");
	ft_strdup_t("Hellow \tworld!");
	ft_strdup_t("Hellow\0World");
	printf("\n\n");
}