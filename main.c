/********************************************************************************
* main.c: Tilldelning till en flyttalsarray samt skrivning av arrayens inneh�ll
*         till en textfil. Textfilens inneh�ll l�ses ocks� in rad f�r rad
*         och skrivs ut i terminalen via funktionen file_read.
* 
*         Annars f�r att l�sa inneh�llet i en given fil direkt fr�n en terminal,
*         klicka Tools -> Command Line -> Developer Command Prompt. En terminal
*         dyker upp. I denna terminal, skriv kommandot "type" f�ljt av filnamnet.
*         D�rmed g�ller f�r att l�sa inneh�llet i filen data.txt, skriv 
*         f�ljande kommando (utan dollartecken):
* 
*         $ type data.txt
********************************************************************************/
#include "double_array.h"

/********************************************************************************
* file_read: L�ser inneh�llet fr�n angiven fils�kv�g rad f�r rad och skriver
*            ut i terminalen.
*
*            - filepath: Pekare till angiven fils�kv�g.
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
*       till bredden med flyttal r�knat fr�n 0 med stegv�rdet 0.5. Arrayens
*       inneh�ll skrivs sedan till filen "data.txt". Efter skrivning l�ses
*       inneh�llet fr�n denna fil rad f�r rad och skrivs ut i terminalen.
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