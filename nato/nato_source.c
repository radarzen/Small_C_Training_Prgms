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

const char * const * const array_pointers[] = {
   nato, punc_nums1, punc2, punc3
};

const size_t array_sizes[] = {
   sizeof(nato) / sizeof(nato[0]),
   sizeof(punc_nums1) / sizeof(punc_nums1[0]),
   sizeof(punc2) / sizeof(punc2[0]),
   sizeof(punc3) / sizeof(punc3[0])
};

/* functions */
const char * getNato(char input) {
  
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

char getAlpha(char * nato_rev) {
   int i = 0, j = 0;
   const char *check_word = nato_rev;
   const char *n;
   char *substr_return = "return";
   size_t num_elements;
   size_t num_arrays;
   int ascii_start[]={ 65, 32, 91, 123 };

   num_arrays = sizeof(array_pointers) / sizeof(array_pointers[0]);

   for(i=0; (unsigned long int) i<num_arrays; i++) {
      num_elements = array_sizes[i];
      for(j=0; (unsigned long int) j<num_elements; j++) {
         n = array_pointers[i][j];
         check_word = nato_rev;  /* reset for each candidate */
         while( *n!='\0' ) {
            if( (*n|0x20)!=(*check_word|0x20) )
               break;
            n++;
            check_word++;
         }
         if( *n=='\0' && *check_word=='\0' )
            return(j + ascii_start[i]);
      }
   }

   /* Use '?' for unknown chars, but first, check for return key-word */
   if( strstr(check_word, substr_return) ) {
      return('\n');
   } else {
      return ('?');
   }
}
