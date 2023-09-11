#ifndef __ENCRYPT_FILE_H__
#define __ENCRYPT_FILE_H__

#include <stdio.h>
#include <stdlib.h>
// 加密文件
int encrypt_file(const char *in_path, const char *out_path, const char *key,
		 const char *sha256);
#endif // ENCRYPT_FILE_H