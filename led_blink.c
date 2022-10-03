/********************************************************************************
* led_blink.c: Blinkning av lysdiod ansluten till pin 9 p� Arduino Uno, vilket 
*              f�r mikrodator ATmega328P motsvarar PORTB1. F�r att g�ra koden
*              mer l�sbar samt g�ra det enklare byte pin-nummer utan att �ndra
*              en massa parametrar anv�nds makrot LED, som motsvarar heltalet 1. 
*              Detta makro ers�tt med motsvarande v�rde 1 innan kompileringen 
*              �ger rum.
*
*              Samtliga pinnar p� Arduino Uno �r ansluta till n�got av de tre
*              I/O-portarna B, C eller D:
*
*              Digitala pinnar 0 - 7 tillh�r I/O-port D (PORTD0 - PORTD7).
*              Digitala pinnar 8 - 13 tillh�r I/O-port B (PORTB0 - PORTD5).
*              Analoga pinnar A0 - A5 tillh�r I/O-port C (PORTC0 - PORTC5).
*
*              Tre typer av register anv�nds f�r respektive I/O-port:
*
*              1. Datariktningsregister DDRB, DDRC samt DDRD anv�nds f�r att
*                 v�lja datariktning f�r en given pin, d�r 1 = utport och
*                 0 = inport.
*
*              2. Portregister PORTB, PORTC samt PORTD anv�nds f�r att skriva
*                 till en given utport, d�r 1 = h�g och 0 = l�g. Dessa register 
*                 anv�nds ocks� f�r att aktivera interna pullup-resistorer f�r 
*                 inportar, vilket g�rs f�r digitala inportar s� att insignalen 
*                 alltid blir 0 (l�g) eller 1 (h�g).
*
*              3. Pinregister PINB, PINC samt PIND anv�nds f�r att l�sa av 
*                 insignalen fr�n en given pin (normalt en inport), 
*                 d�r 1 = h�g och 0 = l�g.
*
*              F�r att s�tta lysdioden till utport ettst�lls bit 1 i 
*              datariktningsregister DDRB (Data Direction Register B) 
*              via bitvis skiftning. DDRB = (1 << 1) inneb�r att v�rdet 
*              0000 0010 skrivs till detta register, vilket g�r lysdiodens 
*              pin 9 till enda utport. I detta program anv�nds makrot LED 
*              i st�llet f�r 1, vilket medf�r att instruktionen skrivs som 
*              DDRB = (1 << LED);
*
*              F�r att t�nda lysdioden ettst�lls bit 1 i port-register PORTB
*              via makrot LED_ON, som �r ekvivalent med PORTD |= (1 << LED),
*              I detta fall anv�nds bitvis OR |= (t�nk bitvis addition) f�r att 
*              ettst�lla bit 1 utan att p�verka �vriga bitar.
*
*              F�r att sl�cka lysdioden nollt�lls bit 1 i port-register PORTB
*              via makrot LED_OFF, som �r ekvivalent med PORTD &= ~(1 << LED).
*              Bitvis AND &= (t�nk bitvis multiplikation) kombinerat med 
*              negation ~ (t�nk bitvis invertering) f�r att nollst�lla bit 1
*              utan att p�verka �vriga bitar.
*
*              F�r att generera f�rdr�jning anv�nds funktionen _delay_ms fr�n
*              biblioteket util/delay.h, som tar emot f�rdr�jningstiden i ms
*              som ett heltal. Innan detta bibliotek importeras m�ste 
*              mikrodatorns klockfrekvens definieras via makrot F_CPU. 
*              Eftersom mikrodatorn i detta fall har en klockfrekvens p� 16 MHz 
*              (via en oscillator p� mikrokontrollerkortet Arduino Uno) s�tts 
*              detta makro till ekvivalent med 16000000UL. UL indikerar att
*              heltalet 16000000 tillh�r datatypen unsigned long, vilket �r 
*              en 32-bitars osignerat heltalstyp som �r tillr�cklig stor f�r
*              att rymma detta tal.
* 
*              En vanlig int �r endast 16-bitar i detta system, vilket medf�r 
*              tal mellan -32 768 - 32 767, allts� alldeles f�r lite f�r ett 
*              s�dant stort tal. Genom att l�gga till UL undviks att v�rdet p� 
*              klockfrekvensen inte trunkeras (f�rkortas) till en regulj�r int.
********************************************************************************/
#define F_CPU 16000000UL /* Definierar mikrodatorns klockfrekvens till 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>      /* Inkluderar bibliotek med information om I/O-portar s�som DDRD. */
#include <util/delay.h>  /* Inkluderar bibliotek f�r genering av f�rdr�jning. */

#define LED 1                        /* Lysdiod p� pin 9 / PORTB1. */
#define LED_ON PORTB |= (1 << LED)   /* T�nder lysdioden. */
#define LED_OFF PORTB &= ~(1 << LED) /* Sl�cker lysdioden. */

/********************************************************************************
* main: S�tter lysdiodens pin 9 till utport. D�refter s�tts lysdioden till att
*       blinka kontinuerligt var 100:e millisekund.
********************************************************************************/
int main(void)
{
   DDRB = (1 << LED); /* S�tter lysdioden till utport. */

   while (1) 
   {
      LED_ON;         /* T�nder lysdioden. */
      _delay_ms(100); /* H�ller lysdioden t�nd i 100 ms. */
      LED_OFF;        /* Sl�cker lysdioden. */
      _delay_ms(100); /* H�ller lysdioden sl�ckt i 100 ms. */
   }

   return 0;
}

