#include "encrypt_file.h"
// 加密文件
int encrypt_file(const char *in_path, const char *out_path, const char *key,
		 const char *sha256)
{
	char cmd[512] = "";
	sprintf(cmd,
		"openssl enc -aes-256-ctr -e -K %.64s -iv %.32s -in %s -out %s",
		key, sha256, in_path, out_path);

	if (system(cmd) == -1) {
		fprintf(stderr, "加密失败!\n");
		return -1;
	}
	return 0;
}