/********************************************************************************
* led_blink.c: Blinkning av lysdiod ansluten till pin 9 på Arduino Uno, vilket 
*              för mikrodator ATmega328P motsvarar PORTB1. För att göra koden
*              mer läsbar samt göra det enklare byte pin-nummer utan att ändra
*              en massa parametrar används makrot LED, som motsvarar heltalet 1. 
*              Detta makro ersätt med motsvarande värde 1 innan kompileringen 
*              äger rum.
*
*              Samtliga pinnar på Arduino Uno är ansluta till något av de tre
*              I/O-portarna B, C eller D:
*
*              Digitala pinnar 0 - 7 tillhör I/O-port D (PORTD0 - PORTD7).
*              Digitala pinnar 8 - 13 tillhör I/O-port B (PORTB0 - PORTD5).
*              Analoga pinnar A0 - A5 tillhör I/O-port C (PORTC0 - PORTC5).
*
*              Tre typer av register används för respektive I/O-port:
*
*              1. Datariktningsregister DDRB, DDRC samt DDRD används för att
*                 välja datariktning för en given pin, där 1 = utport och
*                 0 = inport.
*
*              2. Portregister PORTB, PORTC samt PORTD används för att skriva
*                 till en given utport, där 1 = hög och 0 = låg. Dessa register 
*                 används också för att aktivera interna pullup-resistorer för 
*                 inportar, vilket görs för digitala inportar så att insignalen 
*                 alltid blir 0 (låg) eller 1 (hög).
*
*              3. Pinregister PINB, PINC samt PIND används för att läsa av 
*                 insignalen från en given pin (normalt en inport), 
*                 där 1 = hög och 0 = låg.
*
*              För att sätta lysdioden till utport ettställs bit 1 i 
*              datariktningsregister DDRB (Data Direction Register B) 
*              via bitvis skiftning. DDRB = (1 << 1) innebär att värdet 
*              0000 0010 skrivs till detta register, vilket gör lysdiodens 
*              pin 9 till enda utport. I detta program används makrot LED 
*              i stället för 1, vilket medför att instruktionen skrivs som 
*              DDRB = (1 << LED);
*
*              För att tända lysdioden ettställs bit 1 i port-register PORTB
*              via makrot LED_ON, som är ekvivalent med PORTD |= (1 << LED),
*              I detta fall används bitvis OR |= (tänk bitvis addition) för att 
*              ettställa bit 1 utan att påverka övriga bitar.
*
*              För att släcka lysdioden nolltälls bit 1 i port-register PORTB
*              via makrot LED_OFF, som är ekvivalent med PORTD &= ~(1 << LED).
*              Bitvis AND &= (tänk bitvis multiplikation) kombinerat med 
*              negation ~ (tänk bitvis invertering) för att nollställa bit 1
*              utan att påverka övriga bitar.
*
*              För att generera fördröjning används funktionen _delay_ms från
*              biblioteket util/delay.h, som tar emot fördröjningstiden i ms
*              som ett heltal. Innan detta bibliotek importeras måste 
*              mikrodatorns klockfrekvens definieras via makrot F_CPU. 
*              Eftersom mikrodatorn i detta fall har en klockfrekvens på 16 MHz 
*              (via en oscillator på mikrokontrollerkortet Arduino Uno) sätts 
*              detta makro till ekvivalent med 16000000UL. UL indikerar att
*              heltalet 16000000 tillhör datatypen unsigned long, vilket är 
*              en 32-bitars osignerat heltalstyp som är tillräcklig stor för
*              att rymma detta tal.
* 
*              En vanlig int är endast 16-bitar i detta system, vilket medför 
*              tal mellan -32 768 - 32 767, alltså alldeles för lite för ett 
*              sådant stort tal. Genom att lägga till UL undviks att värdet på 
*              klockfrekvensen inte trunkeras (förkortas) till en reguljär int.
********************************************************************************/
#define F_CPU 16000000UL /* Definierar mikrodatorns klockfrekvens till 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>      /* Inkluderar bibliotek med information om I/O-portar såsom DDRD. */
#include <util/delay.h>  /* Inkluderar bibliotek för genering av fördröjning. */

#define LED 1                        /* Lysdiod på pin 9 / PORTB1. */
#define LED_ON PORTB |= (1 << LED)   /* Tänder lysdioden. */
#define LED_OFF PORTB &= ~(1 << LED) /* Släcker lysdioden. */

/********************************************************************************
* main: Sätter lysdiodens pin 9 till utport. Därefter sätts lysdioden till att
*       blinka kontinuerligt var 100:e millisekund.
********************************************************************************/
int main(void)
{
   DDRB = (1 << LED); /* Sätter lysdioden till utport. */

   while (1) 
   {
      LED_ON;         /* Tänder lysdioden. */
      _delay_ms(100); /* Håller lysdioden tänd i 100 ms. */
      LED_OFF;        /* Släcker lysdioden. */
      _delay_ms(100); /* Håller lysdioden släckt i 100 ms. */
   }

   return 0;
}

