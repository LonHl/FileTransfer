#include <stdio.h>
#include <string.h>
#include "share.h"
#include "get_sha256.h"
#include "receive_file.h"
#include "send_file.h"
#include "command_mode.h"
#include "errp.h"

int main(int argc, char *argv[])
{
	// printf("size : %d\n",sizeof(FILE_INFO));
	// ERRP(argc < 2, "参数过少", goto ERR1);
	// if (argc == 1) {
	// 	command_mode();
	// }
	
	if (!strcmp(argv[1], "-r")) {
		ERRP(argc < 4, "参数过少", goto ERR1);
	}

	if (!strcmp(argv[1], "-r") && argc == 4) {
		receive_file(argv[2], argv[3]);
	} else if (!strcmp(argv[1], "-s") && argc == 3) {
		send_file(argv[2]);
	}

	return 0;
ERR1:
	return -1;
}
