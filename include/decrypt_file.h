#ifndef __DECRYPT_FILE_H__
#define __DECRYPT_FILE_H__

#include <stdio.h>
#include <stdlib.h>
// 解密文件
int decrypt_file(const char *in_path, const char *out_path, const char *key,
		 const char *sha256);

#endif // DECRYPT_FILE_H