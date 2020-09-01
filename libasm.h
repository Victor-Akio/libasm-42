/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 22:28:57 by vminomiy          #+#    #+#             */
/*   Updated: 2020/09/01 23:41:55 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

# define FAIL "\033[31m"
# define PASS "\033[032m"
# define RESET "\033[0m"
# define BUFFER_SIZE 256

size_t		ft_strlen(const char *s);

#endif