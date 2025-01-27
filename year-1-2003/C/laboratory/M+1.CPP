#include<stdio.h>
#include<math.h>
int main()
{ float w,ff,q,r,s;
  q=5.01; r=0.203; s=1.3;
  w=s-sin(pow(r,2))+pow(log(r/q),3);
  ff=exp(-w)*sqrt(abs(r-w))/pow(s,2);
  printf("\nw=%f \n",w);
  printf("ff=%f",ff);
  printf("\n");
}
