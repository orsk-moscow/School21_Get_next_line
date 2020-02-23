/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u18188899 <u18188899@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:43:24 by klekisha          #+#    #+#             */
/*   Updated: 2020/02/23 14:26:09 by u18188899        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2
# define MAX_FD 10024

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
