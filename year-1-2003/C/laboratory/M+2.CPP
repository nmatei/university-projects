#include <stdio.h>
#include <math.h>
void main()
{
float u,v,t,du,dv,y;
t=1.93;u=v=0.3;du=0.9;dv=0.7;
while(u<=1)
{ v=0.3;
while(v<=1)
{
if(u*v<0.7) y=t*pow(logl(u),2)+v*pow(u,5)/sqrt(u);
else if (u*v==0.7) y=sqrt(abs(u-v)+t/u);
else y=log10(v-pow(cos(u),2));
printf("u=,v=,y=, %.2f   %.2f     %.2f    \n" ,u,v,y);
v=v+dv;
}
u=u+du;
}}

