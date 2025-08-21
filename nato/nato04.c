#include <stdio.h>
#include <string.h>
#include <ctype.h>

char isterm(char *term) {
	static const char * const nato[] = {
		"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", 
		"Golf", "Hotel", "India", "Juliet", "Kilo", "Lima", 
		"Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", 
		"Sierra", "Tango", "Uniform", "Victor", "Whiskey", 
		"Xray", "Yankee", "Zulu"
	};
	int x;
	const char *n, *t;
	
	for(x=0; x<26; x++) {
		n = nato[x];
		t = term;
		while( *n!='\0' ) {
			if( (*n|0x20)!=(*t|0x20) )
				break;
			n++;
			t++;
		}
		if( *n=='\0' && *t=='\0' )  // Ensure both strings match entirely
			return( *nato[x] );
	}
	return('\0');
}

int main(int argc, char *argv[]) {
    char ch;
    FILE *nato; 
    char *filename;
    int offset = 0;
    char word[64];

    if( argc<2 ) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return(1);
    } else {
        filename = argv[1];
    }

    nato = fopen(filename, "r");
    if( nato==NULL ) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return(1);
    }

    while( (ch=fgetc(nato))!=EOF ) {
        if( isalpha(ch) ) {
            word[offset] = ch;
            offset++;
            if( offset>=64 ) {
                fprintf(stderr, "Buffer overflow\n");
                return(1);
            }
        } else {
            if( offset>0 ) {
                word[offset] = '\0';
                putchar( isterm(word) );
                offset = 0;
            }
        }
    }

    putchar('\n');

    return(0);
}