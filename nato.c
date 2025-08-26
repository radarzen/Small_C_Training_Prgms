#include "nato.h"

int main(int argc, char *argv[]) {
   char phrase[MAX_INPUT];
   const char *result;
   char filename[128];
   int ch;
   int i=0;
   FILE *fp;
   int err_no=0;
   char cl_argument_1[ARG_INPUT];

   /* If user starts program without arguments */
   if( argc<2 ) {
      printf("Note: to parse text file, use '$ %s [FILENAME.txt]'\n", argv[0]);
      printf("See additional help using '$ %s -h'\n", argv[0]);
      printf("---------------------------------------------------\n");
      printf("Enter a word or phrase: "); 
      fgets(phrase, MAX_INPUT, stdin);

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
      strcpy(cl_argument_1, argv[1]);

      /* If user starts program with the -rN argument to open a text file
         for converting to NATO phonetics */
      if( strcmp(cl_argument_1, "-rN" ) == 0) {
         int an;
         an = 2;
         while( an<argc ) {
            fp = fopen(argv[an], "r");
            if( fp==NULL ) {
               fprintf(stderr, "Error opening file %s", argv[an]);
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

      /* If user starts program with the -w to output NATO phonetics to
         given file, nato.txt if none specified */
      if( strcmp( cl_argument_1, "-w" ) == 0 ) {
         if( argc>2 ) {
            strcpy(filename, argv[2]);
         } else {
            snprintf(filename, 128, "%s/nato.txt", getenv("PWD"));
         }
         printf("Opening %s...", filename);
         fp = fopen(filename, "w");
         if( fp==NULL ) {
            perror("Failed to open file for edit");
            exit(EXIT_FAILURE);
         }

         printf("Enter a word or phrase: "); 
         fgets(phrase, MAX_INPUT, stdin);

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

      /* If user starts program with the -a to output NATO phonetics to 
         append given file */
      if( strcmp( cl_argument_1, "-a" ) == 0 ) {
         if( argc>2 ) {
            strcpy(filename, argv[2]);
         } else {
            snprintf(filename, 128, "%s/nato.txt", getenv("PWD"));
         }
         printf("Opening %s...\n\n", filename);
         fp = fopen(filename, "a+");
         if( fp==NULL ) {
            perror("Failed to open file for edit");
            exit(EXIT_FAILURE);
         }

         printf("Enter a word or phrase: "); 
         fgets(phrase, MAX_INPUT, stdin);

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

      /* If user starts program with the -rF for reading a file and 
         converting from NATO phonetics back to unencoded text */
      if( strcmp( cl_argument_1, "-rF" ) == 0 ) {
         if( argc>2 ) {
            strcpy(filename, argv[2]);
         } else {
            snprintf(filename, 128, "%s/nato.txt", getenv("PWD"));
         }
         printf("Opening %s...\n\n", filename);
         fp = fopen(filename, "r");
         if( fp==NULL ) {
            perror("Failed to open file for edit");
            exit(EXIT_FAILURE);
         }

      }
   }

   return err_no;
}
