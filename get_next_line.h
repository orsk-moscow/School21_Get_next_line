/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u18188899 <u18188899@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:43:24 by klekisha          #+#    #+#             */
/*   Updated: 2020/02/23 19:38:54 by u18188899        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2
# define MAX_FD 1

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		getNL(const int fd, char **line);

#endif
