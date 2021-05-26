#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define rs PA2
#define en PA3
void lcd_init();
void dis_cmd(char);
void dis_data(char);
void lcdcmd(char);
void lcddata(char);
int main(void)
{
unsigned char data0[]="Project";
unsigned char data1[]="McDEV";
int i=0,x;
DDRA=0xFF;
lcd_init();
while(data0[i]!='\0')
{
dis_data(data0[i]);
_delay_ms(100);
i++;
}
dis_cmd(0xC0);
i=0;
while(data1[i]!='\0')
{
dis_data(data1[i]);
_delay_ms(100);
i++;
}
while(1)
{
for(x=0;x<16;x++)
{
dis_cmd(0x1c);
_delay_ms(100);
} }}
void lcd_init() // function for initialize
{
dis_cmd(0x02); // to initialize LCD in 4-bit mode.
dis_cmd(0x28);
dis_cmd(0x0C);
dis_cmd(0x06);
dis_cmd(0x83);
}
void dis_cmd(char cmd_value)
{
char cmd_value1;
cmd_value1 = cmd_value & 0xF0; //mask lower nibble because PA4-PA7 pins are used.
lcdcmd(cmd_value1); // send to LCD
cmd_value1 = ((cmd_value<<4) & 0xF0); //shift 4-bit and mask
lcdcmd(cmd_value1); // send to LCD
}
void dis_data(char data_value)
{
char data_value1;
data_value1=data_value&0xF0;
lcddata(data_value1);
data_value1=((data_value<<4)&0xF0);
lcddata(data_value1);
}
void lcdcmd(char cmdout)
{
PORTA=cmdout;
PORTA&=~(1<<rs);
PORTA|=(1<<en);
_delay_ms(1);
PORTA&=~(1<<en);
}
void lcddata(char dataout)
{
PORTA=dataout;
PORTA|=(1<<rs);
PORTA|=(1<<en);
_delay_ms(1);
PORTA&=~(1<<en);
}
