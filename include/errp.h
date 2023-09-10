#ifndef __ERRP_H__
#define __ERRP_H__

#include <stdio.h>

// 容错宏
#define ERRP(con, info, ret)                           \
	do {                                           \
		if (con) {                             \
			fprintf(stderr, "%s\n", info); \
			ret;                           \
		}                                      \
	} while (0)

#endif // ERRP_H
