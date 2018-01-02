// testsize.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <stdio.h>

#define PACKVALUE 4
#pragma pack(push)
#pragma pack(PACKVALUE)        
typedef struct
{
	char sa;
	double sb;
	int sc;
} innerS;

typedef struct
{
	int a;
	char b;
	short c;
	innerS d[2];
} testS;

#pragma pack(pop)

typedef unsigned long dword;

//字段所占内存大小(字节)
#define FSIZE(type, field) sizeof(((type*)0)->field)
//字段在结构体中的偏移位置
#define FPOS(type, field) ((dword) & ((type*)0)->field)

int _tmain(int argc, _TCHAR* argv[])
{
	printf("#pragma pack(%d):\nsizeof(char)=%d; sizeof(short)=%d; sizeof(int)=%d; sizeof(double)=%d\n\n",
		PACKVALUE, sizeof(char), sizeof(short), sizeof(int), sizeof(double));

	printf("FSIZE = %d, FPOS = %d\n",FSIZE(testS, a),FPOS(testS, a));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, b), FPOS(testS, b));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, c), FPOS(testS, c));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, d), FPOS(testS, d));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, d[0]), FPOS(testS, d[0]));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, d[0].sa), FPOS(testS, d[0].sa));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, d[0].sb), FPOS(testS, d[0].sb));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, d[0].sc), FPOS(testS, d[0].sc));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, d[1]), FPOS(testS, d[1]));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, d[1].sa), FPOS(testS, d[1].sa));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, d[1].sb), FPOS(testS, d[1].sb));
	printf("FSIZE = %d, FPOS = %d\n", FSIZE(testS, d[1].sc), FPOS(testS, d[1].sc));
	return 0;
}