/**
 * MIT License
 * Copyright (c) 2023 Robert1037
 * sha256min.c v2.1 little-endian
 * Last modified: 2023-01-21
 **/
#ifndef __SHA256_H__
#define __SHA256_H__

#include <stdio.h>
#include <stdlib.h>
#define M_LEN 64 // each M block is 512 bits == 64 bytes
#define Rn(X, n) ((X << (32 - n)) | (X >> n))
#define Sn(X, n) (X >> n)
#define Ch(X, Y, Z) ((X & Y) ^ (~X & Z))
#define Maj(X, Y, Z) ((X & Y) ^ (X & Z) ^ (Y & Z))
#define Sigma_E0(X) \
	(Rn(X, 2) ^ Rn(X, 13) ^ Rn(X, 22)) // Σ0(X) = R2(X) ⊕ R13(X) ⊕ R22(X)
#define Sigma_E1(X) \
	(Rn(X, 6) ^ Rn(X, 11) ^ Rn(X, 25)) // Σ1(X) = R6(X) ⊕ R11(X) ⊕ R25(X)
#define Sigma_o0(X) \
	(Rn(X, 7) ^ Rn(X, 18) ^ Sn(X, 3)) // σ0(X) = R7(X) ⊕ R18(X) ⊕ S3(X)
#define Sigma_o1(X) \
	(Rn(X, 17) ^ Rn(X, 19) ^ Sn(X, 10)) // σ1(X) = R17(X) ⊕ R19(X) ⊕ S10(X)

// 获取文件的sha256
char *get_sha256(const char *path, char *buf);

#endif // SHA256_H
