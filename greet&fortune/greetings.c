#include "greetings.h"

int main(int argc, char *argv[]) {

   time_t now;
   struct tm *clock;
   char time_string[64];
   int hour, day, year, mp;
   char *phase[8] = {
      "new", "waxing crescent", "at first quarter", 
      "waxing gibbous", "full", "waning gibbous",
      "at last quarter", "waning crescent"
   };

   time(&now);
   clock = localtime(&now);
   hour = clock -> tm_hour;
   day = clock -> tm_mday; /* Day of Month */
   year = clock -> tm_year+1900; 
   strftime(time_string, 64, "Today is %A, %B, %d, %Y%nIt is %r%n", clock);

   /* printf("%s", ctime(&now)); */
   /* Welcome Message */
   printf("Good ");
   if(hour<12)
      printf("morning ");
   else if(hour<17)
      printf("afternoon ");
   else
      printf("evening ");

   if(argc<2)
      puts("Sexy!\n");
   else
      printf("%s!\n", argv[1]);

   /* Print Date & Time */
   printf("%s", time_string);

   /* Print Moon Phase */
   mp = moon_phase(year, day);
   printf("The moon is %s\n\n", phase[mp]);

   /* Add chastisement if odd hour */
   if(hour<4)
      printf("\bWTF are you doing here at THIS hour?!?\n");
   else if(hour>=17 && hour<=24)
      printf("\bYou need to GO HOME!\n");

   return 0;
}

