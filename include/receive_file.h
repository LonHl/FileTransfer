#ifndef __RECEIVE_FILE_H__
#define __RECEIVE_FILE_H__

#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include "share.h"
#include "errp.h"
#include "get_sha256.h"
#include "decrypt_file.h"
#include "get_key.h"

// 接收文件
int receive_file(const char *ipv4, const char *dir);

#endif // RECEIVE_FILE_H
