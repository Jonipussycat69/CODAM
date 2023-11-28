/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:55:42 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/28 18:28:11 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_variables	v;
	static char	buffer[BUFFER_SIZE + 2];

	v.ret_str = (char *)malloc(sizeof(char));
	v.ret_str[0] = '\0';
	RETURN_NULL_IF(!v.ret_str);
	v.out = 0; v.btsr = BUFFER_SIZE; v.read_if = 0;
	WHILE(v.btsr == BUFFER_SIZE && v.out == 0, {v.i_1 = 0;
	READ_IF(v.read_if == 1, fd, buffer, BUFFER_SIZE, v.btsr)
	v.read_if = 1;
	F_R_N_IF(v.btsr < 0, v.ret_str); v.out = 0;
	v.r_len = 0; NL_LEN(v.ret_str, v.r_len);
	v.b_len = 0; NL_LEN(buffer, v.b_len);
	v.new_str = (char *)malloc(v.b_len + v.r_len + 1);
	F_R_N_IF(!v.new_str, v.ret_str);
	v.i_1 = 0; v.i_2 = 0; v.i_3 = 0; v.i_4 = 0;
	WHILE(v.i_2 < v.r_len, {v.new_str[v.i_2++] = v.ret_str[v.i_1++];})
	WHILE(v.i_3 < v.b_len, {v.new_str[v.i_2++] = buffer[v.i_3++];})
	v.new_str[v.i_2] = '\0';
	free(v.ret_str);
	v.ret_str = v.new_str;
	BUF_SET(buffer, v.i_4, v.i_3)
	buffer[v.i_4] = '\0';
	v.i_1 = 0; NL_CHECK(v.ret_str, v.i_1, v.out)})
	END_CHECK(v.ret_str && v.ret_str[0] == '\0', v.ret_str);
}

// int	main(void)
// {
// 	char	*line;
// 	int	fd = open("test.txt", O_RDONLY);
// 	int	i;

// 	i = 0;
// 	if (fd < 0)
// 		return (1);
// 	while (line && i++ < 21)
// 	{
// 		line = get_next_line(fd);
// 		if (line)
// 		{
// 			printf("\nline:	%sx\n\n", line);
// 			free(line);
// 		}
// 	}
// 	close(fd);
// 	printf("\n");
// 	return (0);
// }
