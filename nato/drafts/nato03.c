#include <stdio.h>
#include <string.h>

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
		if( *n=='\0' )
			return( *nato[x] );
	}
	return('\0');
}

int main() {
    char phrase[240];
    char *match;
    char ch;
    printf("NATO word or phrase: ");
    fgets(phrase, sizeof(phrase), stdin);

    match = strtok(phrase, " ");
    while(match) {
        if( (ch=isterm(match))!='\0' )
            putchar(ch);
        match = strtok(NULL, " ");
    }
    putchar('\n'); 

    return(0);
}
