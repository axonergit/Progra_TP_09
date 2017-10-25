#ifndef LED_H
#define LED_H

int prenderLed(void * posPuerto, unsigned int tamanoPuerto, unsigned int numLed);
int blinkAll_On_Leds(void * posPuerto, unsigned int tamanoPuerto);
int PrenderLeds(void * posPuerto, unsigned int tamanoPuerto);
int apagarLeds(void * posPuerto, unsigned int tamanoPuerto);

#endif /* LED_H */

