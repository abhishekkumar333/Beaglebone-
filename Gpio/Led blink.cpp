#include <stdio.h>
int main(int argc, char **argv)
{
printf("LED_BLINK \n");
FILE *exp,*dir,*val;
int pin = 69;
char *d = "out";
int valh = 1,vall = 0,i;
exp = fopen("/sys/class/gpio/export","w");
if(exp == NULL)
{
printf("error exporting \n");
return -1;
}
fprintf(exp,"%d",pin);
fflush(exp);
fclose(exp);
dir = fopen("/sys/class/gpio/gpio69/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d);
fflush(dir);
fclose(dir);
val = fopen("/sys/class/gpio/gpio69/value","w");
if(val == NULL)
{
printf("error opening value \n");
return -1;
}
for(i=0;i<10;i++)
{
fprintf(val,"%d",valh);
fflush(val);
sleep(1);
fprintf(val,"%d",vall);
fflush(val);
sleep(1);
}
fclose(val);
}