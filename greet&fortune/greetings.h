#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int, char**);

int moon_phase(int year, int day)
{
   /* Formula from blog.truegeometry.com Moon Phases Calculation */
   int n, Y, C;
   float b, c, d, e, f, a, g;
   n = day;
   Y = year;
   C = 20; /* current century */
   b = ((float)Y-(float)C)/4;
   c = ((float)C-1)/4;
   d = ((float)Y*5)/4;
   e = ((float)C*5)/4;
   a = (14-(float)n)/12;
   f = ((float)n + (153*a))/5;
   g = (10*b) + c - d - e + f + 19.5;

   return ((int)g % 7);
}
