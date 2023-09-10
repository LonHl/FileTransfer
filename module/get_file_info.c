#include "get_file_info.h"

FILE_INFO *get_file_info(const char *path, FILE_INFO *buf)
{
	struct stat statbuf;
	stat(path, &statbuf);
	char *name_buf = basename((char *)path);
	strcpy(buf->name, name_buf);
	buf->size = statbuf.st_size;
	buf->atime = statbuf.st_atim.tv_sec;
	buf->mtime = statbuf.st_mtim.tv_sec;
	buf->ctime = statbuf.st_ctim.tv_sec;
	get_sha256(path, buf->sha256);
	return buf;
}
