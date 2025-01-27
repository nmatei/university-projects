#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<alloc.h>
void main()
{  textcolor(14);
    int n,i,j,gol,*pn;
clrscr();
    printf("introdu dimensiunile matricei M[n][n]. n=");
    scanf("%d",&n);
    pn=(int *)malloc(sizeof(int)*n*n);
    for (i=0;i<n;i++)
      { for (j=0;j<n;j++)
	{
	  printf("M[%d][%d]=",i,j);
	  scanf("%d",(pn+i*n+j));
	}
	  printf("\n");
      }
clrscr();
    printf("\n");
    for (i=0;i<n;i++)
      {
	for (j=0;j<n;j++)
	  printf("%d \t",*(pn+i*n+j));
	  printf("\n");
      }
    printf("\nElementele de pe diagonala principala sunt:\n");
    for(i=0;i<n;i++)
      {
	printf("%d \t",*(pn+i*(n+1)));
      }
    printf("\n\nElementele de pe diagonala principala");
    printf("\n  in ordinea crescatoare sunt:\n");
    for (j=0;j<n-1;j++)
      for(i=j+1;i<n;i++)
	 if (*(pn+j*(n+1))>*(pn+i*(n+1)))
	    {
	      gol=*(pn+j*(n+1));
	      *(pn+j*(n+1))=*(pn+i*(n+1));
	      *(pn+i*(n+1))=gol;
	    }
    for(i=0;i<n;i++)
    printf("%d\t",*(pn+i*(n+1)));
 printf("\n Matricea modificata:\n");
    for (i=0;i<n;i++)
      {
	for (j=0;j<n;j++)
	  printf("%d \t",*(pn+i*n+j));
	  printf("\n");
      }
getch();
}
