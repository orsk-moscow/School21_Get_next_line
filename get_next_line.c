#include "get_next_line.h"
#include "../libft/libft.h"
// copy folder "libft" with files libft.h and libft.a in root of the repo
// ssize_t?
// type of BUFF_SIZE?
// ft_count_words can be equal to 0? Or 1 minimum?

// char	*ft_join_n_sym_from_buf(char *temp3, char *buffer, size_t len)
// {
// 	char	*temp4;
// 	if (!buffer || len == 0)
// 		return (NULL);
// 	if (!temp3 && (!(temp3 = (char*)ft_memalloc(len + 1))))
// 		return (NULL);
// 	if (!(temp4 = (char*)ft_memalloc(ft_strlen(temp3) + len + 1)))
// 	{
// 		ft_bzero(temp3, ft_strlen(temp3));
// 		ft_bzero(buffer, ft_strlen(buffer));
// 		return (NULL);
// 	}
// 	ft_strncpy(temp4, temp3, ft_strlen(temp3));
// 	ft_strncpy(temp4 + ft_strlen(temp3), buffer, len);
// 	ft_bzero(temp3, ft_strlen(temp3));
// 	ft_strncpy(temp3, (const char*)temp4, ft_strlen(temp4));
// 	ft_bzero(temp4, ft_strlen(temp4));
// 	return (temp3);
// }

// int     get_next_line(const int fd, char **line)
// {
//     static char		*fd_array[MAX_FD];
//     char			*buf;
//     char			*temp1;
//     char			*temp2;
// 	size_t			n_bites_in_buf;
// 	if (!(temp1 = (char*)ft_memalloc(sizeof(char) * (size_t)(BUFF_SIZE + 1))))
// 		return (-1);
// 	if (!(buf = (char*)ft_memalloc(sizeof(char) * (size_t)(BUFF_SIZE + 1))))
// 		return (-1);
// 	while (((n_bites_in_buf = (size_t)read(fd, buf, (int)BUFF_SIZE)) != 0) && (!ft_strchr(buf, '\n')))
// 		temp2 = ft_join_n_sym_from_buf(temp1, buf, n_bites_in_buf);
// 	if (n_bites_in_buf)
// 		temp2 = ft_join_n_sym_from_buf(temp2, buf, (size_t)(ft_strchr(buf, '\n') - buf));
// 	if (fd_array[fd])
// 	{
// 		ft_join_n_sym_from_buf(fd_array[fd], temp1, ft_strlen(temp1));
// 		ft_strncpy(temp1, fd_array[fd], ft_strlen(fd_array[fd]));
// 		ft_bzero(fd_array[fd], ft_strlen(fd_array[fd]));
// 		if (temp1 != temp2)
// 			ft_strncpy(temp1 + ft_strlen(temp1), temp2, ft_strlen(temp2));
// 	}
// 	if (n_bites_in_buf)
// 		fd_array[fd] = ft_join_n_sym_from_buf(NULL, ft_strchr(buf, '\n') + 1, n_bites_in_buf - (ft_strchr(buf, '\n') - buf) - 1);
// 	if (!(*line = (char*)ft_memalloc(sizeof(char) * ft_strlen(temp1) + 1)))
// 		return (-1);
// 	ft_bzero(buf, ft_strlen(buf));
// 	ft_memmove(*line, temp2, ft_strlen(temp2));
// 	if (temp1 != temp2)
// 		ft_bzero(temp2, ft_strlen(temp2));	
// 	else
// 		temp2 = NULL;
// 	ft_bzero(temp1, ft_strlen(temp1));
// 	return (1);
// }

// VERSION 2
// int		ft_is_newline(const int fd, char *str2, char **line)
// {
// 	size_t	n_symbols_before_newline;
// 	char	*temp5;

// 	n_symbols_before_newline = (ft_strchr(str2, (int)'\n') ? ((size_t)(ft_strchr(str2, (int)'\n') - str2)) : ft_strlen(str2));
// 	if (!(*line))
// 	{
// 		if (!(*line = (char*)ft_memalloc(sizeof(char) * (n_symbols_before_newline + 1))))
// 			return (-1);
// 	}
// 	if (ft_strchr(str2, (int)'\n'))
// 	{
// 		ft_strncpy(*line + ft_strlen(*line), str2, n_symbols_before_newline);
// 		if (!(temp5 = (char*)ft_memalloc(ft_strlen(str2) - n_symbols_before_newline)))
// 			return (-1);
// 		ft_strncpy(temp5, str2 + n_symbols_before_newline + 1, ft_strlen(str2) - n_symbols_before_newline - 1);
// 		ft_bzero(str2, ft_strlen(str2));
// 		ft_strncpy(str2, temp5, ft_strlen(temp5));
// 		ft_bzero(temp5, ft_strlen(temp5));
// 		return (1);
// 	}
// 	else
// 	{
// 		ft_strncpy(*line + ft_strlen(*line), str2, n_symbols_before_newline);
// 		return (2);
// 	}
// }

// char	*ft_add_one_more_buf(char *temp8)
// {
// 	char	*temp9;
// 	size_t	max_new_length;
 
// 	max_new_length = ft_strlen(temp8) + BUFF_SIZE;
// 	if (!(temp9 = (char*)ft_memalloc(max_new_length + 1)))
// 		return (NULL);
// 	ft_strcpy(temp9, temp8);
// 	ft_bzero(temp8, ft_strlen(temp8));
// 	// if (!(temp8 = (char*)ft_memalloc(max_new_length + 1)))
// 	// 	return (NULL);
// 	return(temp9);
// }

// int     get_next_line(const int fd, char **line)
// {
// 	static char		*fd_array[MAX_FD] = {NULL};
// 	size_t			n_bites_in_buf;
// 	char			*buf;
// 	int				temp6;

// 	if (*line)
// 		ft_bzero(*line, ft_strlen(*line));
// 	if (!(buf = (char*)ft_memalloc(sizeof(char) * (size_t)(BUFF_SIZE + 1))))
// 		return (-1);
// 	if (fd_array[fd] && fd_array[fd][0] != '\0')
// 		temp6 = ft_is_newline(fd, fd_array[fd], line);
// 	else if (temp6 != 1)
// 	{
// 		if (!(fd_array[fd] = (char*)ft_memalloc(sizeof(char) * (size_t)(BUFF_SIZE + 1))))
// 			return (-1);
// 		while ((n_bites_in_buf = (size_t)read(fd, buf, BUFF_SIZE)) != 0 && (temp6 = ft_is_newline(fd, buf, line) == 2))
// 		{
// 			*line = ft_add_one_more_buf(*line);
// 		}
// 		ft_strcpy(fd_array[fd], buf);
// 	}
// 	ft_bzero(buf, ft_strlen(buf));			
// 	return (n_bites_in_buf == 0 ? 0 : temp6); // wrong return!
// }

// VERSION 3

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


int		get_next_line(const int fd, char **line)
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
	temp13 = ft_strlen(fd_array[fd]);
	// if (temp12 = ft_strchr(fd_array[fd], (int)'\n'))
	if (!(*line = ft_strnew(temp13)))
		return (-1);
	ft_strcpy(*line, fd_array[fd]);
	// functional test = will i have correct fd_array[fd] for 2 file descriptors
	return (temp13);
}
