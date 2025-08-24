#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#define MAX_INPUT 240
#define ARG_INPUT 16

int main(int, char**);

extern const char * const nato[];
extern const char * const punc_nums1[];
extern const char * const punc2[];
extern const char * const punc3[];

const char * getNato(char input);
char getAlpha(char * nato);


