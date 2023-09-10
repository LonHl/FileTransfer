#ifndef __GET_FILE_INFO_H__
#define __GET_FILE_INFO_H__

#include <string.h>
#include <libgen.h>
#include <sys/stat.h>
#include "share.h"
#include "get_sha256.h"

// 获取文件基本信息
FILE_INFO *get_file_info(const char *path, FILE_INFO *buf);

#endif // GET_FILE_INFO_H
