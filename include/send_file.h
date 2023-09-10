#ifndef __SEND_FILE_H__
#define __SEND_EILE_H__

#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include "share.h"
#include "errp.h"
// 发送文件
int send_file(const char *path);

#endif // SEND_FILE_H
