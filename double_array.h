/********************************************************************************
* double_array.h: Innehåller funktionalitet för tilldelning och utskrift av
*                 arrayer innehållande flyttal. Allt i headerfilen skall 
*                 placeras mellan define (början) och endif (slutet).
* 
********************************************************************************/
#ifndef DOUBLE_ARRAY_H_ 
#define DOUBLE_ARRAY_H_ 

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* double_array_assign: Tilldelar flyttal till array av angiven storlek med
*                      godtyckligt stegvärde. Det första värdet som läggs till
*                      är alltid 0.
*
*                      - self: Pekare till arrayen.
*                      - size: Arrayens storlek (antalet flyttal den rymmer).-
*                      - step: Stegvärdet mellan varje tilldelat element.
********************************************************************************/
void double_array_assign(double* self, 
                         const int size,
                         const double step);

/********************************************************************************
* double_array_print: Skriver ut flyttal lagrat i array via angiven utström,
*                     där standardutenhet stdout används som default för
*                     utskrift i terminalen.
*
*                     - self: Pekare till arrayen.
*                     - size: Arrayens storlek (antalet flyttal den rymmer).
*                     - ostream: Pekare till angiven utström (default = stdout).
********************************************************************************/
void double_array_print(const double* self,
                        const int size,
                        FILE* ostream);

#endif /* DOUBLE_ARRAY_H_ */