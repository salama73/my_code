	#define F_CPU 16000000UL
	#include <avr/io.h>
	#include <avr/delay.h>
	#define Servo_pin PA0
	void my_servo(uint8_t number_pin,uint8_t degree);
	int main(void)
	{
		DDRA =0XFF;
		while (1)
		{
			my_servo(Servo_pin,0);
			_delay_ms(1000);
			my_servo(Servo_pin,90);
			_delay_ms(1000);
			my_servo(Servo_pin,180);
			_delay_ms(1000);
			
		}
	}
	void my_servo(uint8_t number_pin,uint8_t degree)
	{
		if (degree==0)
		{
			for (int i = 0; i < 50; i++)
			{
				PORTA=0XFF;
				_delay_us(500);
				PORTA=0X00;
				_delay_us(19500);
			}
		}
		else if (degree==90)
		{
			for (int i = 0; i < 50; i++)
			{
				PORTA=0XFF;
				_delay_us(1445);
				PORTA=0X00;
				_delay_us(18555);
			}
		}
		else if (degree==180)
		{
			for (int i = 0; i < 50; i++)
			{
				PORTA=0XFF;
				_delay_us(2389);
				PORTA=0X00;
				_delay_us(17611);
			}
		}
		
	}



