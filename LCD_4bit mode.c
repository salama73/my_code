#define F_CPU 16000000UL      
#include <avr/io.h>      
#include <util/delay.h>       
#define lcdDirection  DDRA  
#define lcdPort PORTA 
#define en PA2
#define rs PA1
//Configure The LCD to send Addresses
void LCD_cmd( unsigned char cmd )  
{
	lcdPort = (lcdPort & 0x0F) | (cmd & 0xF0);            // send upper nibble of 8 bit
	lcdPort &= ~ (1<<rs);								 // rs=0 i.e select command reg
	lcdPort |= (1<<en);									// give high pulse to enable pin
	_delay_us(1);
	lcdPort &= ~ (1<<en);							  // give low pulse to enable pin
	_delay_us(200);
	lcdPort = (lcdPort & 0x0F) | (cmd << 4);		// sending lower nibble of 8 bit i.e 1byte
	lcdPort |= (1<<en);							   // give high pulse to enable pin
	_delay_us(1);
	lcdPort &= ~ (1<<en);						// give low pulse to enable pin
	_delay_ms(2);
}
//Used To Send a Single Character
void LCD_Character( unsigned char character )
{
	lcdPort = (lcdPort & 0x0F) | (character & 0xF0);			// send upper nibble of character
	lcdPort |= (1<<rs);										   //  set rs to select data register
	lcdPort|= (1<<en);										  // set enable pin
	_delay_us(1);
	lcdPort &= ~ (1<<en);									// reset enable pin
	_delay_us(200);
	lcdPort = (lcdPort & 0x0F) | (character << 4);         //send lower nibble
	lcdPort |= (1<<en);                                   // set enable pin
	_delay_us(1);
	lcdPort &= ~ (1<<en);                               // reset enable pin
	_delay_ms(2);
}
//Used To Send a Single Character
void LCD_String (char *string)                
{
	int i;
	for(i=0;string[i]!=0;i++)
	{
		LCD_Character (string[i]);
	}
}
//clear LCD
void	lcd_Clear()
{
	LCD_cmd (0x01);                   // send hex 01 to Clear display
	_delay_ms(2);
	LCD_cmd(0x80);                   // send hex 80 to Force Cursor to beginning of 1st line
}
//  Initializing 16x2 LCD with 4 bit mode
void LCD_init()
{
	lcdDirection = 0xFF;            // set LCD port direction in output
	_delay_ms(20);           
	LCD_cmd(0x02);                // send for 4 bit initialization of LCD "shift cursor to left"
	LCD_cmd(0x28);               // 2 line 5*7 matrix in 4-bit mode
	LCD_cmd(0x0c);              // Display on cursor off
	LCD_cmd(0x06);             // take cursor to next position "shift cursor to right"
	LCD_cmd(0x01);            // Clear display screen
	_delay_ms(2);
}
int main()
{
    while(1)
	{
	LCD_init();
	LCD_String("SALAMA"); // Write string on 1st row of 16x2 LCD
	LCD_cmd(0xC0); //    move to 2nd row
	LCD_String("MOHAMED"); // write string on second line
	_delay_ms(2000);
	lcd_Clear();
	_delay_ms(2000);
	}
}