#include<stdio.h>
#include<conio.h>

void main()
{
  int i,j,n,S=0,k;
  int M[25],L[25],K[25];
  clrscr();
  printf("Introdu lungimea tablourilor: n= ");scanf("%d",&n);
  for (i=0;i<n;i++)
    {
      printf("M[%d]=",i);scanf("%d",&M[i]);
      printf("L[%d]=",i);scanf("%d",&L[i]);
    }
  for (i=0;i<n;i++)
     { 	for (j=M[i];j<(L[i]+1) && j<n;j++)
	    S+=M[j]+L[j];
	    K[i]=S;
	    S=0;
     }
  clrscr();
printf("\nM = { ");
  for (i=0;i<n-1;i++)
     printf("%d ;\t",M[i]);
     printf("%d }",M[i]);
printf("\nL = { ");
  for (i=0;i<n-1;i++)
     printf("%d ;\t",L[i]);
     printf("%d }",L[i]);
printf("\n\nK = { ");
  for (i=0;i<n-1;i++)
     printf("%d ;\t",K[i]);
     printf("%d }",K[i]);
getch();
}


