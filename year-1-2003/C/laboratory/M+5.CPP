#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{  //textcolor(10);
   int a[10],b[10],n,i,j,min,gol,M[10][10];
    clrscr();
	printf("n="); scanf("%i",&n);
	for (i=0;i<n;i++)
	  { for (j=0;j<n;j++)
		{
		  printf("M[%i][%i]=",i,j); scanf("%i",&M[i][j]);
		}
		printf("\n");
	  }
clrscr();
	printf("\n");
	for (i=0;i<n;i++)
	  {
		for (j=0;j<n;j++)
		  printf("%i \t",M[i][j]);
		printf("\n");
	  }
	printf("\nElementele de pe diagonala principala sunt:\n");
	for(i=0;i<n;i++)
	  {
		a[i]=M[i][i];
		printf("%i\t",a[i]);
	  }
	printf("\n\nElementele de pe diagonala principala");
	printf("\n  in ordinea crescatoare sunt:\n");
	for (j=0;j<n-1;j++)
	  for(i=j+1;i<n;i++)
		 if (a[j]>a[i])
			{
			  gol=a[j];
			  a[j]=a[i];
			  a[i]=gol;
			}
	for(i=0;i<n;i++)
	printf("%i\t",a[i]);

getch();
}
