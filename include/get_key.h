#ifndef __GET_KEY_H__
#define __GET_KEY_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_in_str.h"
#define KEY_PATH "./aes256.key"
#define KEY_SIZE 65

// 获取密钥
char *get_key(char *buf,size_t size);

#endif // GET_FILE_INFO_H
