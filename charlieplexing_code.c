#include "derivative.h"

#define pinA (1<<1) //PTA1
#define pinA(1<<12)	//PTA12
#define pinA (1<<2)	//PTD4

#define High (PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK)
#define Low (PORT_PCR_MUX(1) &~PORT_PCR_DSE_MASK | PORT_PCR_PE_MASK &~PORT_PCR_PS_MASK)
#define Tristate (PORT_PCR_MUX(1) &~PORT_PCR_DSE_MASK &~PORT_PCR_PE_MASK &~PORT_PCR_PS_MASK)

void delay()
{
	int count;
	for(count=0; count < 1000000; count++) 
	
	{
		asm("nop"); //no-operation // Do nothing 
	}
}


}

/*
* Turn on the given LED
*
* @paramledNum LED to turn on (1..6)
*
*/
void setLED(int ledNum)
{
	if(ledNum == 1)
	{
		PORTA_PCR1 = High;  //high
		PORTC_PCR3 = Tristate; //4-state
		PORTD_PCR4 = Low;  //low
		GPIOA_PDDR |= pinA; //out
		GPIOC_PDDR &= ~pinB; //in
		GPIOD_PDDR |= pinC; //out
		GPIOA_PDOR |= pinA; //out
		GPIOC_PDOR &= ~pinB; //in
		GPIOD_PDOR &= ~pinC; //out
	}

	if(ledNum == 2)
	{
		PORTA_PCR1 = Low;
		PORTC_PCR3 = Tristate; 
		PORTD_PCR4 = High;  
		GPIOA_PDDR |= pinA; //out
		GPIOC_PDDR &= ~pinB; //in
		GPIOD_PDDR |= pinC; //out	
		GPIOA_PDOR &= ~pinA; 
		GPIOC_PDOR &= ~pinB; 
		GPIOD_PDOR |= pinC; 
	}

	if(ledNum == 3)
	{
		PORTA_PCR1 = High;  
		PORTC_PCR3 = Low; 
		PORTD_PCR4 = Tristate;
		GPIOA_PDDR |= pinA; //out
		GPIOC_PDDR |= pinB; //out
		GPIOD_PDDR &= ~pinC; //in		
		GPIOA_PDOR |= pinA; 
		GPIOC_PDOR &= ~pinB; 
		GPIOD_PDOR &= ~pinC; 
		}

	if(ledNum == 4)
	{
		PORTA_PCR1 = Low;  
		PORTC_PCR3 = High; 
		PORTD_PCR4 = Tristate;
		GPIOA_PDDR |= pinA; //out
		GPIOC_PDDR |= pinB; //out
		GPIOD_PDDR &= ~pinC; //in				
		GPIOA_PDOR &= ~pinA; 
		GPIOC_PDOR |= pinB; 
		GPIOD_PDOR &= ~pinC; 
	}

	if(ledNum == 5)
	{
		PORTA_PCR1 = Tristate; //Z
		PORTC_PCR3 = High; //H
		PORTD_PCR4 = Low; //L
		GPIOA_PDDR &= ~pinA; //in
		GPIOC_PDDR |= pinB; //out
		GPIOD_PDDR |= pinC; //out					
		GPIOA_PDOR &= ~pinA; 
		GPIOC_PDOR |= pinB; 
		GPIOD_PDOR &= ~pinC; 
	}

	if(ledNum == 6)
	{
		PORTA_PCR1 = Tristate; //Z 
		PORTC_PCR3 = Low; //L
		PORTD_PCR4 = High; //H
		GPIOA_PDDR &= ~pinA; //in
		GPIOC_PDDR |= pinB; //out
		GPIOD_PDDR |= pinC; //out		
		GPIOA_PDOR &= ~pinA; 
		GPIOC_PDOR &= ~pinB; 
		GPIOD_PDOR |= pinC; 
	}
}

int main(void) 
{
	// Enable clock to PORT A 
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTC_MASK;
		
	for(;;)
	{
		setLED(1);
		delay();
		setLED(2);
		delay();
		setLED(3);
		delay();
		setLED(4);
		delay();
		setLED(5);
		delay();
		setLED(6);
		delay();
	}

	 	return 0; 
}
