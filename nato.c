#include "nato.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
   char phrase[MAX_INPUT];
   char word[WORDS];
   const char *result;
   char filename[128];
   int ch;
   int i=0;
   int piped_in=0;
   int cl_msg_in=0;
   char piped_chars[MAX_INPUT];
   int offset=0;
   FILE *fp;
   int err_no=0;
   char letter;
   size_t len;
   struct stat sb;
   char **cl_arguments = malloc( argc*sizeof(char *) );
   if( cl_arguments==NULL ) {
      perror( "Failed to allocate memory");
      return EXIT_FAILURE;
   }

   /* make copy of commandline argument to cl_arguments array */
   for(i=0; i<argc; i++) {
      cl_arguments[i] = strdup(argv[i]);
      if( cl_arguments[i]==NULL ) {
         perror("Failed to copy arguments");
         /* free previously allocated memory */
         for (int j=0; j<i; j++) {
            free(cl_arguments[j]);
         }
         free(cl_arguments);
         return EXIT_FAILURE;
      }
   }
   

   /* check stdin for data piped in from another program */
   if( fstat(STDIN_FILENO, &sb)==0 && S_ISFIFO(sb.st_mode) ) {
      while(fgets(piped_chars, sizeof(piped_chars), stdin) != NULL) {
         piped_in = 1;
      }
   }

   /* If user starts program without arguments */
   if( argc<2 ) {

      /* If no data piped in, get user input */
      if( !piped_in ) {
         printf("Note: to parse text file, use '$ %s -rN [FILENAME.txt]'\n", cl_arguments[0]);
         printf("See additional help using '$ %s -h'\n", cl_arguments[0]);
         printf("---------------------------------------------------\n");
         printf("Enter a word or phrase: "); 
         fgets(phrase, MAX_INPUT, stdin);
      } else {
         strcpy(phrase, piped_chars);
      }

      /* Convert input to NATO phonetics */
      i = 0;
      while(phrase[i]) {
         result = getNato(phrase[i]);
         if(result!=NULL)
            printf("%s ", result);
         i++;
         if( i==MAX_INPUT )
            break;
      }
      putchar('\n');
   }

   if( argc>=2 ) {

      /* If user starts program with the -c to convert NATO phonetics
         to regular text*/
      if( strcmp( cl_arguments[1], "-c") == 0) {
         if( argc>3 ) {
            /* this would denote an error, probably indicating user forgot to encapsulate
               imput text from the command-line */
            printf("Error: too many arguments for -c option.\n");
            printf("Did you forget to encapsulate input text [\"] or [\']?\n");
            printf("See [nato -h] for help.\n");
            return(EXIT_FAILURE);
         } else if( argc>2 ) {
            strcpy(phrase, cl_arguments[2]);
         } else if( piped_in ) {
            strcpy(phrase, piped_chars);
         } else {
            printf("Note: to parse text file, use '$ %s -rF [FILENAME.txt]'\n", cl_arguments[0]);
            printf("See additional help using '$ %s -h'\n", cl_arguments[0]);
            printf("---------------------------------------------------\n");
            printf("Enter NATO phonetics to convert back to text: "); 
            fgets(phrase, MAX_INPUT, stdin);
         }

         len = strlen(phrase);
         offset = 0;
         for(i=0; i<len; i++) {
            ch = phrase[i];
            if( ch!=' ' && ch!='\n' && ch!='\t' && offset<WORDS-1) {
               word[offset] = ch;
               ++offset;
            } else {
               word[offset] = '\0';
               if( offset>1 ) {
                  letter = getAlpha(word);
                  printf("%c", letter);
               }                  
               offset = 0;
            }
         }
         putchar('\n');
      }

      /* If user starts program with the -w to output NATO phonetics to
         given file, nato.txt if none specified */
      if( strcmp( cl_arguments[1], "-w" ) == 0 ) {
         if( argc>4 ) {
         /* this would denote an error, probably indicating user forgot to encapsulate
            imput text from the command-line */
            printf("Error: too many arguments for -w option.\n");
            printf("Did you forget to encapsulate input text [\"] or [\']?\n");
            printf("See [nato -h] for help.\n");
            return(EXIT_FAILURE);
         } else if( argc>3 ) {
            strcpy(filename, cl_arguments[2]);
            strcpy(phrase, cl_arguments[3]);
            cl_msg_in = 1;
         } else if( argc>2 ) {
            strcpy(filename, cl_arguments[2]);
         } else {
            snprintf(filename, 128, "%s/nato.txt", getenv("PWD"));
         }

         printf("Opening %s...\n", filename);
         fp = fopen(filename, "w");
         if( fp==NULL ) {
            perror("Failed to open file for edit");
            exit(EXIT_FAILURE);
         }

         if( !piped_in && !cl_msg_in ) {
            printf("Enter a word or phrase: "); 
            fgets(phrase, MAX_INPUT, stdin);
         } else if( piped_in && !cl_msg_in) {
            strcpy(phrase, piped_chars);
         }

         i = 0;
         while(phrase[i]) {
            result = getNato(phrase[i]);
            if(result!=NULL)
               fprintf(fp, "%s ", result);
            i++;
            if( i==MAX_INPUT )
               break; 
         }
         putchar('\n');
         fclose(fp);
      }

      /* If user starts program with the -a to output NATO phonetics to 
         append given file */
      if( strcmp( cl_arguments[1], "-a" ) == 0 ) {
         if( argc>4 ) {
         /* this would denote an error, probably indicating user forgot to encapsulate
            imput text from the command-line */
            printf("Error: too many arguments for -a option.\n");
            printf("Did you forget to encapsulate input text [\"] or [\']?\n");
            printf("See [nato -h] for help.\n");
            return(EXIT_FAILURE);
         } else if( argc>3 ) {
            strcpy(filename, cl_arguments[2]);
            strcpy(phrase, cl_arguments[3]);
            cl_msg_in = 1;
         } if( argc>2 ) {
            strcpy(filename, cl_arguments[2]);
         } else {
            snprintf(filename, 128, "%s/nato.txt", getenv("PWD"));
         }

         printf("Opening %s...\n", filename);
         fp = fopen(filename, "a+");
         if( fp==NULL ) {
            perror("Failed to open file for edit");
            exit(EXIT_FAILURE);
         }

         if( !piped_in && !cl_msg_in ) {
            printf("Enter a word or phrase: "); 
            fgets(phrase, MAX_INPUT, stdin);
         } else if( piped_in && !cl_msg_in) {
            strcpy(phrase, piped_chars);
         }
         
         i = 0;
         while(phrase[i]) {
            result = getNato(phrase[i]);
            if(result!=NULL)
               fprintf(fp, "%s ", result);
            i++;
            if( i==MAX_INPUT )
               break; 
            }
         fclose(fp);
      }

      /* If user starts program with the -rN argument to open a text file
         for converting to NATO phonetics */
      if( strcmp(cl_arguments[1], "-rN" ) == 0) {
         int an;
         an = 2;
         while( an<argc ) {
            fp = fopen(cl_arguments[an], "r");
            if( fp==NULL ) {
               fprintf(stderr, "Error opening file %s", cl_arguments[an]);
               perror("Failure");
               exit(EXIT_FAILURE);
               err_no = 1;
               ++an;
               continue;
            }
            while( (ch=fgetc(fp))!=EOF ) {
               result = getNato(ch);
               if( result!=NULL )
                  printf("%s ", result);
            }
            printf("\n\t\t-----EOF-----\n");
            fclose(fp);
            ++an;
         }
      }

      /* If user starts program with the -rF for reading a file and 
         converting from NATO phonetics back to unencoded text */
      if( strcmp( cl_arguments[1], "-rF" ) == 0 ) {
         if( argc>2 ) {
            strcpy(filename, cl_arguments[2]);
         } else {
            snprintf(filename, 128, "%s/nato.txt", getenv("PWD"));
         }
         printf("Opening %s...\n", filename);
         fp = fopen(filename, "r");
         if( fp==NULL ) {
            perror("Failed to open a file for reading");
            exit(EXIT_FAILURE);
         }
         while( (ch=fgetc(fp)) != EOF) {
            offset = 0;
            while( ch != ' ' && ch != '\n' && ch != '\t' && offset < WORDS - 1) {
               word[offset] = ch;
               ++offset;
               ch = fgetc(fp);  //read next char
            }
            word[offset] = '\0';
            if(offset > 0) {  // Only process if we actually read a word
               letter = getAlpha(word);               
               printf("%c", letter);
            }
         }
         putchar('\n');
      }

      /* If user starts program with just a message argument */
      if( cl_arguments[1][0] != '-' ) {
         strcpy(phrase, cl_arguments[1]);
         i = 0;
         while(phrase[i]) {
            result = getNato(phrase[i]);
            if(result!=NULL)
               printf("%s ", result);
            i++;
            if( i==MAX_INPUT )
               break;
         }
         putchar('\n');
      }
   }

   /* free dynamically allocated memory */
   for (i=0; i<argc; i++) {
      free(cl_arguments[i]);
   }
   free(cl_arguments);

   return err_no;
}
