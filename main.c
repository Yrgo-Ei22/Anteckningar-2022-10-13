/********************************************************************************
* main.c: Tilldelning till en flyttalsarray samt skrivning av arrayens innehåll
*         till en textfil. Textfilens innehåll läses också in rad för rad
*         och skrivs ut i terminalen via funktionen file_read.
* 
*         Annars för att läsa innehållet i en given fil direkt från en terminal,
*         klicka Tools -> Command Line -> Developer Command Prompt. En terminal
*         dyker upp. I denna terminal, skriv kommandot "type" följt av filnamnet.
*         Därmed gäller för att läsa innehållet i filen data.txt, skriv 
*         följande kommando (utan dollartecken):
* 
*         $ type data.txt
********************************************************************************/
#include "double_array.h"

/********************************************************************************
* file_read: Läser innehållet från angiven filsökväg rad för rad och skriver
*            ut i terminalen.
*
*            - filepath: Pekare till angiven filsökväg.
********************************************************************************/
int file_read(const char* filepath)
{
   FILE* istream = fopen(filepath, "r");

   if (!istream)
   {
      fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
      return 1;
   }
   else
   {
      char s[100] = { '\0' };

      while (fgets(s, (int)sizeof(s), istream))
      {
         printf("%s", s);
      }

      fclose(istream);
      return 0;
   }
}

/********************************************************************************
* main: Deklarerar en statisk array som rymmer 20 flyttal. Denna array fylls
*       till bredden med flyttal räknat från 0 med stegvärdet 0.5. Arrayens
*       innehåll skrivs sedan till filen "data.txt". Efter skrivning läses
*       innehållet från denna fil rad för rad och skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   double data[20];
   FILE* ostream = fopen("data.txt", "w");

   double_array_assign(data, 20, 0.5);
   double_array_print(data, 20, ostream);

   fclose(ostream); 
   file_read("data.txt");
   return 0;
}