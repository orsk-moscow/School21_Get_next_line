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

int		ft_is_newline(const int fd, char *str2, char **line)
{
	size_t	n_symbols_before_newline;
	char	*temp5;

	n_symbols_before_newline = (ft_strchr(str2, (int)'\n') ? ((size_t)(ft_strchr(str2, (int)'\n') - str2)) : ft_strlen(str2));
	if (!(*line))
	{
		if (!(*line = (char*)ft_memalloc(sizeof(char) * (n_symbols_before_newline + 1))))
			return (-1);
	}
	if (ft_strchr(str2, (int)'\n'))
	{
		ft_strncpy(*line, str2, n_symbols_before_newline);
		if (!(temp5 = (char*)ft_memalloc(ft_strlen(str2) - n_symbols_before_newline)))
			return (-1);
		ft_strncpy(temp5, str2 + n_symbols_before_newline + 1, ft_strlen(str2) - n_symbols_before_newline - 1);
		ft_bzero(str2, ft_strlen(str2));
		ft_strncpy(str2, temp5, ft_strlen(temp5));
		ft_bzero(temp5, ft_strlen(temp5));
		return (1);
	}
	else
	{
		ft_strncpy(*line, str2, n_symbols_before_newline);
		return (2);
	}
}

int     get_next_line(const int fd, char **line)
{
	static char		*fd_array[MAX_FD];
	size_t			n_bites_in_buf;
	char			*buf;
	int				temp6;

	if (!(buf = (char*)ft_memalloc(sizeof(char) * (size_t)(BUFF_SIZE + 1))))
		return (-1);
	if (fd_array[fd])
		temp6 = ft_is_newline(fd, fd_array[fd], line);
	else
	{
		if (!(fd_array[fd] = (char*)ft_memalloc(sizeof(char) * (size_t)(BUFF_SIZE + 1))))
			return (-1);
		while ((n_bites_in_buf = (size_t)read(fd, buf, (int)BUFF_SIZE)) != 0 && (temp6 = ft_is_newline(fd, buf, line) == 2))
			*line += n_bites_in_buf;
		ft_strcpy(fd_array[fd], buf);
	}
	ft_bzero(buf, ft_strlen(buf));			
	return (n_bites_in_buf == 0 ? 0 : temp6); // wrong return!
}
