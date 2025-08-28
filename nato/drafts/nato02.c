#include "nato.h"

int main(int argc, char *argv[]) {
   char phrase[MAX_INPUT];
   int ch;
   int i=0;
   FILE *n;
   int err_no=0;

   if( argc<2 ) {
      printf("Note: to parse text file, use '$ %s [FILENAME.txt]'\n", argv[0]);
      printf("Enter a word or pharase: "); 
      fgets(phrase, MAX_INPUT, stdin);

      i = 0;
      while(phrase[i]) {
         getNato(phrase[i]);
         i++;
         if( i==MAX_INPUT )
            break;
      }
      putchar('\n');
   }

   if( argc>=2 ) {
      int an;
      an = 1;
      while( an<argc ) {
         n = fopen(argv[an], "r");
         if( n==NULL ) {
            fprintf(stderr, "Unable to open '%s'\n", argv[an]);
            err_no = 1;
            ++an;
            continue;
         }
         while( (ch=fgetc(n))!=EOF )
            getNato(ch);
         printf("\n\t\t-----EOF-----\n");
         fclose(n);
         ++an;
      }
   }

   return err_no;
}
