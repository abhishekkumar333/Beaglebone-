#include <stdio.h>
int main(int argc, char **argv)
{
printf("LED_PUSH_BUTTON\n");
FILE *exp,*dir,*valled,*valbttn;
char *d = "out",*d1 = "in";
int pin = 69,pin1 = 68;
int valin;
int valh = 1,vall = 0;
exp = fopen("/sys/class/gpio/export","w");
if(exp == NULL)
{
printf("error exporting \n");
return -1;
}
fprintf(exp,"%d",pin);
fflush(exp);
fprintf(exp,"%d",pin1);
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
dir = fopen("/sys/class/gpio/gpio68/direction","w");
if(dir == NULL)
{
printf("error opening direction \n");
return -1;
}
fprintf(dir,"%s",d1);
fflush(dir);
fclose(dir);
valled = fopen("/sys/class/gpio/gpio69/value","w");
if(valled == NULL)
{
printf("error opening value \n");
return -1;
}
valbttn = fopen("/sys/class/gpio/gpio68/value","r");
if(valbttn == NULL)
{
printf("error opening value \n");
return -1;
}
fscanf(valbttn,"%d",&valin);
if(valin == 0)
{
fprintf(valled,"%d",valh);
fflush(valled);
}
else
{
fprintf(valled,"%d",vall);
fflush(valled);
}
fclose(valled);
fclose(valbttn);
}