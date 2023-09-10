#include "send_file.h"
#include "get_file_info.h"
// 发送文件
int send_file(const char *path)
{
	int sfd, s;
	void *p;
	char buf[MAXSIZE];
	struct addrinfo hints;
	struct addrinfo *result, *rp;
	// 初始化addrinfo结构体
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_NUMERICHOST | AI_PASSIVE;
	hints.ai_protocol = 0;
	// 获取本地主机的地址信息
	s = getaddrinfo(NULL, PORT, &hints, &result);
	if (s != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		return -1;
	}
	// 遍历地址信息列表，尝试绑定套接字
	for (rp = result; rp != NULL; rp = rp->ai_next) {
		sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
		if (sfd == -1)
			continue;

		if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
			break;

		close(sfd);
	}

	freeaddrinfo(result);
	// 判断是否成功绑定套接字
	if (rp == NULL) {
		fprintf(stderr, "Could not bind\n");
		return -1;
	}
	// 监听连接请求
	if (listen(sfd, 8) == -1) {
		perror("listen error");
		return -1;
	}

	struct sockaddr_in clientaddr;
	socklen_t addrlen = sizeof(clientaddr);
	int connfd = accept(sfd, (struct sockaddr *)&clientaddr, &addrlen);
	if (connfd == -1) {
		perror("Connect Error");
		return -1;
	}
	close(sfd);

	FILE_INFO info;
	get_file_info(path, &info);
	// 发送文件信息
	write(connfd, &info, sizeof(info));

	int fd = open(path, O_RDONLY);
	if (fd == -1) {
		perror("open error");
		close(connfd);
		return -1;
	}
	// 使用mmap进行内存映射
	p = mmap(NULL, info.size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (p == MAP_FAILED) {
		perror("mmap error");
		close(fd);
		close(connfd);
		return -1;
	}
	close(fd);
	// 发送文件内容
	int ret_size = write(connfd, p, info.size);
	printf("ret_size : %d\n", ret_size);
	// 解除内存映射
	munmap(p, info.size);

	close(connfd);

	return 0;
}
