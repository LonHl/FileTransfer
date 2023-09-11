#include "get_in_str.h"
// 获取输入的字符串
char *get_in_str(char **lineptr, size_t *n)
{
	if (getline(lineptr, n, stdin) == -1) {
		perror("get input error");
		return NULL;
	}
	if ((*lineptr)[strlen(*lineptr) - 1] == '\n')
		(*lineptr)[strlen(*lineptr) - 1] = '\0';
	return *lineptr;
}
