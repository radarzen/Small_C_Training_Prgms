#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_INPUT 256
#define WORDS 64
#define ARG_INPUT 256

int main(int, char**);

extern const char * const nato[];
extern const char * const punc_nums1[];
extern const char * const punc2[];
extern const char * const punc3[];
extern const char * const nato_rev[];

const char * getNato(char input);
char getAlpha(char * nato_rev);


