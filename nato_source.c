#include "nato.h"

// Define the nato array
const char * const nato[] = {
     "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
     "Golf", "Hotel", "India", "Juliette", "Kilo", "Lima", 
     "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
     "Sierra", "Tango", "Uniform", "Victor", "Whiskey", 
     "Xray", "Yankee", "Zulu"
};

const char * const punc_nums1[] = {
     "<space>", "<exclemation>", "<d-quote>", "<num>", "<dollar>",
     "<percent>", "<ampersand>", "<s-quote>", "<o-parenthesis>",
     "<c-parenthesis>", "<asterisk>", "<plus>", "<comma>",
     "<hyphen>", "<dot>", "<slash>", "Zero", "One", "Two", "Tree",
     "Fower", "Fife", "Six", "Seven", "Eight", "Niner", "<colon>",
     "<semi-colon>", "<o-angle-brkt>", "<equals>", 
     "<c-angle-brkt>", "<question>", "<at-sign>"
};

const char * const punc2[] = {
     "<o-brkt>", "<backslash>", "<c-brkt>", "<caret>", 
     "<underscore>", "<back-tic>"
};

const char * const punc3[] = {
     "<o-brace>", "<v-bar>", "<c-brace>", "<tilde>"
}; 

char * getNato(char input) {
  
  if( isalpha(input) ) {
     input = toupper(input);
     return(nato[input-'A']);
  } else if( input >= 32 && input <= 64 )
     return(punc_nums1[input-32]);
  else if( input >= 91 && input <= 96 )
     return(punc2[input-91]);
  else if( input >= 123 && input <= 126 )
     return(punc3[input-123]);
  else if( input == '\n')
     return("<return> ");

  return(NULL);     // Return NULL if unsupported character
}

char getAlpha(char * nato) {
    return NULL;
}