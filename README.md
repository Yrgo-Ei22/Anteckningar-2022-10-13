# Anteckningar 2022-10-03
Introduktion till hårdvarunära C-programmering samt repetition av arrayer och filpekare.

Filen led_blink.c innehåller ett enkelt C-program där en lysdiod ansluten till pin 9 / PORTB1 sätts
till att blinka var 100:e millisekund. Här finns också information om olika I/O-register på mikrodator
ATmega328P.

Filerna main.c, double_array.h samt double_array.c innehåller den repetitionsuppgift som genomfördes, där en
statisk array som rymmer 20 flyttal fylls till bredden med flyttal räknat från 0 med stegvärde 0.5 (0, 0.5, 1, 1.5...).
vilket skrivs till en fil döpt data.txt. Detta genomfördes via funktionen main i filen main.c via anrop
av funktioner specifikt skapade för double-arrayer. Funktionerna för implementering av double-arrayer deklareras 
i filen double_array.h och definieras i filen double_array.c.