#include "receive_file.h"
#include "share.h"
// 接收文件
int receive_file(const char *ipv4, const char *dir)
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
	hints.ai_flags = AI_NUMERICHOST;
	hints.ai_protocol = 0;
	// 获取目标主机的地址信息
	s = getaddrinfo(ipv4, PORT, &hints, &result);
	if (s != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		return -1;
	}
	// 遍历地址信息列表，尝试建立连接
	for (rp = result; rp != NULL; rp = rp->ai_next) {
		sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
		if (sfd == -1)
			continue;

		if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
			break;

		close(sfd);
	}

	freeaddrinfo(result);
	// 判断是否成功建立连接
	if (rp == NULL) {
		fprintf(stderr, "Could not connect\n");
		return -1;
	}

	FILE_INFO info;
	read(sfd, &info, sizeof(info));
	// 切换到指定目录
	chdir(dir);
	// 打开文件
	int fd = open(info.name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		perror("open error");
		return -1;
	}
	// 调整文件大小
	if (ftruncate(fd, info.size) == -1) {
		perror("ftruncate error");
		return -1;
	}

	// p = mmap(NULL, info.size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	// if (p == MAP_FAILED) {
	// 	perror("mmap error");
	// 	return -1;
	// }
	// close(fd);

	// int ret_size = read(sfd, p, info.size);
	// printf("ret_size : %d info_size : %d\n", ret_size,info.size);

	// munmap(p, info.size);
	int n;
	while ((n = read(sfd, buf, sizeof(buf))) > 0) {
		write(fd, buf, n);
	}

	close(sfd);

	char sha256_buf[65];
	// 计算接收到的文件的SHA256哈希值
	get_sha256(info.name, sha256_buf);
	// 比较接收到的文件的SHA256哈希值与发送方提供的哈希值是否一致
	if (strcmp(info.sha256, sha256_buf)) {
		fprintf(stderr, "传输文件错误\n");
		return -1;
	}
	return 0;
}
