#ifndef __SHARE_H__
#define __SHARE_H__

// 端口号
#define PORT "20020"
// 缓冲区大小
#define MAXSIZE 1024 * 64

// 文件基本信息
typedef struct file_info_t {
	char name[256];
	unsigned long long size;
	long long atime;
	long long mtime;
	long long ctime;
	char sha256[65];
} FILE_INFO;

#endif // SHARE_H
