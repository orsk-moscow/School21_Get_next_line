/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:43:24 by klekisha          #+#    #+#             */
/*   Updated: 2019/05/12 19:36:43 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# define MAX_FD 10024

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		get_next_line(const int fd, char **line);

#endif
