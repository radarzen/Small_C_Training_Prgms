#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define BSIZE 256

int main(int argc, char *argv[]) {
   char default_filename[BSIZE];
   snprintf(default_filename, sizeof(default_filename), "%s/lib/fortune.txt", getenv("HOME"));

   int custom_flag=0, force_default=0;
   FILE *fp;
   char buffer[BSIZE];
   char *r, *entry, *filename;
   int items=0, saying=0;
   char **list_base;

   do {

      if( !force_default) {
         filename = (char *)malloc(sizeof(char) * strlen(default_filename)+1);
         if( filename==NULL ) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
         }
      } else {
         filename = (char *)realloc(filename, sizeof(char) * strlen(default_filename)+1);
         if( filename==NULL ) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
         }
      }

      strcpy(filename, default_filename);

      if( argc>1 && !force_default ) {
         filename = (char *)realloc(filename, sizeof(char) * strlen(argv[1])+1);
         if( filename==NULL ) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
         }
         strcpy(filename, argv[1]);
         custom_flag = 1;
      }

      force_default = 0;

      fp = fopen(filename, "r");
      if( fp==NULL ) {
         if( custom_flag ) {
            fprintf(stderr, "Unable to open requested file.\n");
            fprintf(stderr, "Using default file instead.\n");
            custom_flag = 0;
            force_default = 1;
         } else {
            perror( "Error opening the file");
            exit(EXIT_FAILURE);
         }
      }
   } while( force_default == 1 );

   list_base = (char **)malloc(sizeof(char *) * 100);
   if( list_base==NULL ) {
      fprintf(stderr, "Unable to allocate memory\n");
      exit(1);
   }

   while( !feof(fp) ) {
      r = fgets(buffer, BSIZE, fp);
      if( r==NULL ) 
         break;
      entry = (char *)malloc(sizeof(char) * strlen(buffer)+1);
      if( entry==NULL ) {
         fprintf(stderr, "Unable to allocate memory\n");
         exit(1);
      }
      strcpy(entry, buffer);
      *(list_base+items) = entry;
      if( items%100==0 ) {
         list_base = (char **)realloc(list_base, sizeof(char *)*(items+100));
         if( list_base==NULL ) {
            fprintf(stderr, "Unable to reallocate memory\n");
            exit(1);
         }
      }
      items++;
   }

   fclose(fp);

   srand( (unsigned)time(NULL) );
   saying = rand() & (items-1);
   printf("%s", *(list_base+saying));
    
   free(list_base);
   free(entry);
   free(filename);

   return 0;
}

