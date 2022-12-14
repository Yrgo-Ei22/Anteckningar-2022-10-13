/********************************************************************************
* double_array.c: Funktionsdefinitioner f?r tilldelning och utskrift av arrayer
*                 inneh?llande flyttal.
********************************************************************************/
#include "double_array.h"

/********************************************************************************
* double_array_assign: Tilldelar flyttal till array av angiven storlek med
*                      godtyckligt stegv?rde. Det f?rsta v?rdet som l?ggs till
*                      ?r alltid 0.
*
*                      - self: Pekare till arrayen.
*                      - size: Arrayens storlek (antalet flyttal den rymmer).
*                      - step: Stegv?rdet mellan varje tilldelat element.
********************************************************************************/
void double_array_assign(double* self, 
                         const int size, 
                         const double step) 
{
   double num = 0;

   for (int i = 0; i < size; ++i)
   {
      self[i] = num; 
      num += step;   
   }

   return;
}

/********************************************************************************
* double_array_print: Skriver ut flyttal lagrat i array via angiven utstr?m,
*                     d?r standardutenhet stdout anv?nds som default f?r
*                     utskrift i terminalen.
*
*                     - self: Pekare till arrayen.
*                     - size: Arrayens storlek (antalet flyttal den rymmer).
*                     - ostream: Pekare till angiven utstr?m (default = stdout).
********************************************************************************/
void double_array_print(const double* self,
                        const int size,
                        FILE* ostream)
{
   if (!ostream) ostream = stdout;

   fprintf(ostream, "--------------------------------------------------------------------------------\n");

   for (int i = 0; i < size; ++i)
   {
      fprintf(ostream, "%.1lf\n", self[i]); 
   }

   fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
   return;
}
