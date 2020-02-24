/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u18188899 <u18188899@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:43:24 by klekisha          #+#    #+#             */
/*   Updated: 2020/02/23 19:52:30 by u18188899        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_2(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;
	char	*fresh;

	i1 = 0;
	i2 = 0;
	i3 = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i1])
		i1++;
	while (s2[i2])
		i2++;
	fresh = (char*)malloc(sizeof(char) * (i1 + i2 + 1));
	if (!fresh)
		return (NULL);
	while (i3 < i1)
		fresh[i3++] = *s1++;
	while (i3 < (i1 + i2))
		fresh[i3++] = *s2++;
	fresh[i3] = '\0';
	return (fresh);
}

void	ft_memdel_2(void **ap)
{
	if (!(ap))
		return ;
	if (!(*ap))
		return ;
	free(*ap);
	*ap = NULL;
	return ;
}

char	*ft_strcpy_2(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		getNL(const int fd, char **line)
{
	static char		*fd_array[MAX_FD] = {0};
	char			buf[BUFF_SIZE + 1];
	size_t			n_bites_in_buf;
	char			*temp12;
	size_t			temp13;

	if (fd < 0 || !line)
		return (-1);
	while ((n_bites_in_buf = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[n_bites_in_buf] = '\0';
		(fd_array[fd]
			? (fd_array[fd] = ft_strjoin_2(fd_array[fd], buf))
			: (fd_array[fd] = ft_strjoin_2("", buf)));
		if (!fd_array[fd])
			return (-1);
	}
	if (!fd_array[fd])
		exit(1);
	temp13 = ft_strlen(fd_array[fd]);
	if (!(*line = ft_strnew(temp13)))
		return (-1);
	ft_strcpy(*line, fd_array[fd]);
	return (temp13);
}
