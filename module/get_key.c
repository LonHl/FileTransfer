#include "get_key.h"

char *get_key(char *buf, size_t size)
{
	FILE *fp = NULL;
	char *str = NULL;
	size_t len = 0;
	if (size < KEY_SIZE) {
		fprintf(stderr, "buf大小不足\n");
		return NULL;
	}
	if ((fp = fopen(KEY_PATH, "r")) == NULL) {
		if ((fp = fopen(KEY_PATH, "w")) == NULL) {
			perror("created file aes256.key error");
			return NULL;
		}
		printf("未检测到密钥文件,请输入密钥:");
		if (get_in_str(&str, &len) != NULL) {
			if ((len = fwrite(str, strlen(str), 1, fp)) != 1) {
				perror("key write file error");
				return NULL;
			}
			strcpy(buf, str);
			free(str);
		}
	} else {
		len = fread(buf, 64, 1, fp);
		if (len != 1) {
			fprintf(stderr, "保存的密钥损坏,请重新写入\n");
		}
		buf[64] = '\0';
	}
	fclose(fp);
	return buf;
}