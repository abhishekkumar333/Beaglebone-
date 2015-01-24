#include <stdio.h>
void lcd_cmd(unsigned char );
void lcd_data(char *);
void lcd_putchar(unsigned char);
void lcd_init();
FILE *exp1,*dir,*rs,*e,*d0,*d1,*d2,*d3,*d4,*d5,*d6,*d7;
int pin1 = 69,pin2 = 68,pin3 = 45,pin4 = 44,pin5 =23,pin6 = 26,pin7 = 47,pin8 = 46,pin9 = 27,pin10 = 65;
char *d = "out";
int v_high =1,v_low=0;
int main(int argc, char **argv)
{
printf("LCD_DISPLAY\n");
exp1 = fopen("/sys/class/gpio/export","w");
if(exp1 == NULL)
{
printf("error opening export \n");
return -1;
}
fprintf(exp1,"%d",pin1);
fflush(exp1);
fprintf(exp1,"%d",pin2);
fflush(exp1);
fprintf(exp1,"%d",pin3);
fflush(exp1);
fprintf(exp1,"%d",pin4);
fflush(exp1);
fprintf(exp1,"%d",pin5);
fflush(exp1);
fprintf(exp1,"%d",pin6);
fflush(exp1);
fprintf(exp1,"%d",pin7);
fflush(exp1);
fprintf(exp1,"%d",pin8);
fflush(exp1);
fprintf(exp1,"%d",pin9);
fflush(exp1);
fprintf(exp1,"%d",pin10);
fflush(exp1);
fclose(exp1);
dir = fopen("/sys/class/gpio/gpio69/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
dir = fopen("/sys/class/gpio/gpio68/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
dir = fopen("/sys/class/gpio/gpio45/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
dir = fopen("/sys/class/gpio/gpio44/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
dir = fopen("/sys/class/gpio/gpio23/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
dir = fopen("/sys/class/gpio/gpio26/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
dir = fopen("/sys/class/gpio/gpio47/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
dir = fopen("/sys/class/gpio/gpio46/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
dir = fopen("/sys/class/gpio/gpio27/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
dir = fopen("/sys/class/gpio/gpio65/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
rs = fopen("/sys/class/gpio/gpio69/value","w");
if(rs == NULL)
{
printf("error opening rs \n");
return -1;
}
e = fopen("/sys/class/gpio/gpio68/value","w");
if(rs == NULL)
{
printf("error opening e\n");
return -1;
}
d0 = fopen("/sys/class/gpio/gpio45/value","w");
if(rs == NULL)
{
printf("error opening d0 \n");
return -1;
}
d1 = fopen("/sys/class/gpio/gpio44/value","w");
if(rs == NULL)
{
printf("error opening d1 \n");
return -1;
}
d2 = fopen("/sys/class/gpio/gpio23/value","w");
if(rs == NULL)
{
printf("error opening d2 \n");
return -1;
}
d3 = fopen("/sys/class/gpio/gpio26/value","w");
if(rs == NULL)
{
printf("error opening d3 \n");
return -1;
}
d4 = fopen("/sys/class/gpio/gpio47/value","w");
if(rs == NULL)
{
printf("error opening d4 \n");
return -1;
}
d5 = fopen("/sys/class/gpio/gpio46/value","w");
if(rs == NULL)
{
printf("error opening d5 \n");
return -1;
}
d6 = fopen("/sys/class/gpio/gpio27/value","w");
if(rs == NULL)
{
printf("error opening d6 \n");
return -1;
}
d7 = fopen("/sys/class/gpio/gpio65/value","w");
if(rs == NULL)
{
printf("error opening d7 \n");
return -1;
}
lcd_init();
lcd_data("CRANES");
}
void lcd_command(unsigned char cmd)
{
//value pin d7
if((cmd & 0x0080) == 0x0080)
{
fprintf(d7,"%d",v_high);
fflush(d7);
}
else
{
fprintf(d7,"%d",v_low);
fflush(d7);
}
//value pin d6
if((cmd & 0x0040) == 0x0040)
{
fprintf(d6,"%d",v_high);
fflush(d6);
}
else
{
fprintf(d6,"%d",v_low);
fflush(d6);
}
//value pin d5
if((cmd & 0x0020) == 0x0020)
{
fprintf(d5,"%d",v_high);
fflush(d5);
}
else
{
fprintf(d5,"%d",v_low);
fflush(d5);
}
//value pin d4
if((cmd & 0x0010) == 0x0010)
{
fprintf(d4,"%d",v_high);
fflush(d4);
}
else
{
fprintf(d4,"%d",v_low);
fflush(d4);
}
//value pin d3
if((cmd & 0x0008) == 0x0008)
{
fprintf(d3,"%d",v_high);
fflush(d3);
}
else
{
fprintf(d3,"%d",v_low);
fflush(d3);
}
//value pin d2
if((cmd & 0x0004) == 0x0004)
{
fprintf(d2,"%d",v_high);
fflush(d2);
}
else
{
fprintf(d2,"%d",v_low);
fflush(d2);
}
//value pin d1
if((cmd & 0x0002) == 0x0002)
{
fprintf(d1,"%d",v_high);
fflush(d1);
}
else
{
fprintf(d1,"%d",v_low);
fflush(d1);
}
//value pin d0
if((cmd & 0x0001) == 0x0001)
{
fprintf(d0,"%d",v_high);
fflush(d0);
}
else
{
fprintf(d0,"%d",v_low);
fflush(d0);
}
fprintf(rs,"%d",v_low);
fflush(rs);
fprintf(e,"%d",v_high);
fflush(e);
fprintf(e,"%d",v_low);
fflush(e);
usleep(10);
}
void lcd_putchar(unsigned char data)
{
//value pin d7
if((data & 0x0080) == 0x0080)
{
fprintf(d7,"%d",v_high);
fflush(d7);
}
else
{
fprintf(d7,"%d",v_low);
fflush(d7);
}
//value pin d6
if((data & 0x0040) == 0x0040)
{
fprintf(d6,"%d",v_high);
fflush(d6);
}
else
{
fprintf(d6,"%d",v_low);
fflush(d6);
}
//value pin d5
if((data & 0x0020) == 0x0020)
{
fprintf(d5,"%d",v_high);
fflush(d5);
}
else
{
fprintf(d5,"%d",v_low);
fflush(d5);
}
//value pin d4
if((data & 0x0010) == 0x0010)
{
fprintf(d4,"%d",v_high);
fflush(d4);
}
else
{
fprintf(d4,"%d",v_low);
fflush(d4);
}
//value pin d3
if((data & 0x0008) == 0x0008)
{
fprintf(d3,"%d",v_high);
fflush(d3);
}
else
{
fprintf(d3,"%d",v_low);
fflush(d3);
}
//value pin d2
if((data & 0x0004) == 0x0004)
{
fprintf(d2,"%d",v_high);
fflush(d2);
}
else
{
fprintf(d2,"%d",v_low);
fflush(d2);
}
//value pin d1
if((data & 0x0002) == 0x0002)
{
fprintf(d1,"%d",v_high);
fflush(d1);
}
else
{
fprintf(d1,"%d",v_low);
fflush(d1);
}
//value pin d0
if((data & 0x0001) == 0x0001)
{
fprintf(d0,"%d",v_high);
fflush(d0);
}
else
{
fprintf(d0,"%d",v_low);
fflush(d0);
}
fprintf(rs,"%d",v_high);
fflush(rs);
fprintf(e,"%d",v_high);
fflush(e);
fprintf(e,"%d",v_low);
fflush(e);
usleep(10);
}
void lcd_data(char *msg)
{
while(*(msg) != '\0')
{
lcd_putchar(*msg);
msg++;
}
}
void lcd_init()
{
lcd_command(0x38);
usleep(30);
lcd_command(0x0E);
usleep(30);
lcd_command(0x01);
usleep(30);
lcd_command(0x80);
usleep(30);
}
