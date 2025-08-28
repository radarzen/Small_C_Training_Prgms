#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 120

int main(int, char**);

void getNato(char input) {
  static char *nato[] = {
     "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
     "Golf", "Hotel", "India", "Juliette", "Kilo", "Lima", 
     "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
     "Sierra", "Tango", "Uniform", "Victor", "Whiskey", 
     "Xray", "Yankee", "Zulu"
  };

  static char *punc_nums1[] = {
     "<space>", "<exclemation>", "<d-quote>", "<num>", "<dollar>",
     "<percent>", "<ampersand>", "<s-quote>", "<o-parenthesis>",
     "<c-parenthesis>", "<asterisk>", "<plus>", "<comma>",
     "<hyphen>", "<dot>", "<slash>", "Zero", "One", "Two", "Tree",
     "Fower", "Fife", "Six", "Seven", "Eight", "Niner", "<colon>",
     "<semi-colon>", "<o-angle-brkt>", "<equals>", 
     "<c-angle-brkt>", "<question>", "<at-sign>"
  };

  static char *punc2[] = {
     "<o-brkt>", "<backslash>", "<c-brkt>", "<caret>", 
     "<underscore>", "<back-tic>"
  };

  static char *punc3[] = {
     "<o-brace>", "<v-bar>", "<c-brace>", "<tilde>"
  };

  if( isalpha(input) ) {
     input = toupper(input);
     printf("%s ", nato[input-'A']);
  } else if( input >= 32 && input <= 64 )
     printf("%s ", punc_nums1[input-32]);
  else if( input >= 91 && input <= 96 )
     printf("%s ", punc2[input-91]);
  else if( input >= 123 && input <= 126 )
     printf("%s ", punc3[input-123]);
  else if( input == '\n')
     printf("<return> ");

  return; 
}


