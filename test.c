#include <stdio.h>
#include <string.h>
#include "share.h"
#include "get_sha256.h"
#include "encrypt_file.h"
#include "decrypt_file.h"
#include "receive_file.h"
#include "send_file.h"
#include "command_mode.h"
#include "errp.h"

int main(int argc, char *argv[])
{
	char key_buf[65];
	char sha256_buf[65];
	// int ret = encrypt_file(argv[1], argv[2],
	// 		       get_key(key_buf, sizeof(key_buf)),
	// 		       get_sha256(argv[1], sha256_buf));

	int ret = decrypt_file(argv[1], argv[2],
			       get_key(key_buf, sizeof(key_buf)),
			       get_sha256(argv[3], sha256_buf));
	printf("ret = %d\n", ret);
	return 0;
}
