#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
  int n,i,m,f=0,j,nn,nnn,pp; clrscr();
  int a[10],b[10],b1=4,b2=9,b3=6;
  float p,ff;
  double intreg;
	printf("Numarul in baza %d : ",b1);
	scanf("%d.%d",&n,&f);
//************* Baza 10 **************
	for (i=0;n;i++)
	 { b[i]=n%10;
		  n=n/10;
	 }
		m=i;n=0;
  for (i=0;i<m;i++)
	  n+=b[i]*pow(b1,i);
  for (i=0;f;i++)
	  { b[i]=f%10;
	f=f/10;
	  }
  m=i;p=0;
  for (i=0;i<m;i++)
	p+=b[i]*pow(b1,-1*(i+1));
  printf("\nNumarul in baza 10 : %f\n",p+n);
  ff=n+p;
  nn=ff;
  ff=ff-nn;
  n=nn;
  p=ff;
//************** Baza 9 **************
for (i=0;;i++)
	 {
		 a[i]=n%b2;
		 n=n/b2;
		 if (n==0) break;
	  j=i+1;
	 }
 printf("\nNumarul in baza %d : ",b2);
 for (i=j;i>-1;i--) printf("%i",a[i]);
 f=0;
 for(i=0;i<6;i++)
  { a[i]=0;
	 f=p*b2;
	 p*=b2;
		pp=p;
		p=p-pp; //p=modf(p,&intreg);
	 a[i]=f;
  }
  m=i;  p=0;
  printf(".");
  for(i=0;i<m;i++) printf("%d",a[i]);
//************** Baza 6 **************
 n=nn;
 p=ff;
 for (i=0;;i++)
  {  a[i]=n%b3;
	  n=n/b3;
	  if (n==0) break;
	  j=i+1;
  }
 printf("\nNumarul in baza %d : ",b3);
 for (i=j;i>-1; i--) printf("%i",a[i]);
 f=0;
 for(i=0;i<6;i++)
  { a[i]=0;
	 f=p*b3;
	 p*=b3;
		pp=p;
		p=p-pp;
	 a[i]=f;
  }
  m=i;  p=0;
  printf(".");
  for(i=0;i<m;i++)
	 printf("%d",a[i]);
 printf("\n");
 getch();
}
