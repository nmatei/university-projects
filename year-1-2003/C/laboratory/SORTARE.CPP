#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <time.h>
#include <stdlib.h>

int a[15],b[15];
int n=15,nsr;
void sort_rapida(int *,int,int *);
void met_bulelor(int *,int);
void shell(int *,int);
void selectie(int *,int);
void insertSort(int *,int,int);
void afish(int *);
void copie(int *,int *);

void initializare()
{time_t t;
 int i;
 t=time(NULL);
 srand(t);
for(i=0;i<n;i++) a[i]=random(100);
}
int nsr1=0;
//*********************************************
void sort_rapida(int *t, int n,int *d)
{
 int i=0,j,k,temp,p;
 j=n-1;
 p=t[n/2];
 do{
	while(t[i]<p)i++;
	while(t[j]>p)j--;
	if(i<=j){temp=t[i];
		 t[i]=t[j];
		 t[j]=temp;
		 i++;j--;nsr1++;
		 }
 }while(i<=j);
if(j>0)if(j>5) met_bulelor(t,j+1);
	 else sort_rapida(t,j+1,d);
if(i<n-1)if(n-i<=5) met_bulelor(t+i,n-i);
	else sort_rapida(t+i,n-i,d);
}
//************************************************
void met_bulelor(int *tab,int n)
{int i,j,temp;
nsr=0;
for(i=0;i<n-1;i++)
 for(j=0;j<n-1;j++)
	if(tab[j]>tab[j+1])
		{temp=tab[j];
		 tab[j]=tab[j+1];
		 tab[j+1]=temp;
		 nsr++;
		}
}
//**********************************************
void shell(int *t,int n)
 {int i,j,k,temp,ns=0;
	for(i=n/2;i>0;i/=2)
	 for(j=i;j<n;j++)
	{
	for(k=j-i;k>=0 && t[k]>t[k+i];k-=i)
	 {temp=t[k];
		t[k]=t[k+i];
		t[k+i]=temp;
		ns++;
		}
		ns++;}
	printf("Metoda shell=>%d schimbari:\n",ns);
 }
//***************************************************
 void selectie(int *t,int n)
	{
	int i,j,j1,min,ns=0,control;
	for(i=0;i<n;i++)
	{min=t[i];j1=i;
	 control=0;
	 for(j=i+1;j<n;j++)
		if(t[j]<min)
		 {min=t[j];
		 j1=j;control++;}
	if(control>0)
	{t[j1]=t[i];
	 t[i]=min;
		ns++;}
	}
 printf("Metoda selectiei=>%d schimbari:\n",ns);
 }
//***************************************************
void insertSort(int *a,int lb,int ub)
{void afisare(int *);
 int t,i,j,ns=0;
	for (i=lb+1;i<=ub;i++)
		 {t=a[i];
		for (j=i-1;j>=lb && a[j]>t;j--)
			 {a[j+1]=a[j];ns++;
			 }
		a[j+1] = t;ns++;
	}
	printf("Metoda insertiei=>%d schimbari:\n",ns);
}
//***************************************************
void afisare(int *t)
{int i;
for(i=0;i<n;i++)
	printf("%3d",t[i]);
   printf("\n\n");
}
//***************************************
void copie(int *t1,int *t2)
{int i;
	for(i=0;i<n;i++)
 t2[i]=t1[i];
 }
//***********************************
void main()
{clrscr();
 _setcursortype(_NOCURSOR);
initializare();
copie(a,b);
printf("Tabelul ne sortat:\n");
afisare(a);

sort_rapida(a,n,a);
printf("Metoda rapida=>%d schimbari:\n",nsr1);
afisare(a);

copie(b,a);
met_bulelor(a,n);
printf("Metoda bulelor=>%d schimbari:\n",nsr);
afisare(a);

copie(b,a);
shell(a,n);
afisare(a);

copie(b,a);
selectie(a,n);
afisare(a);

copie(b,a);
insertSort(a,0,n-1);
afisare(a);

getch();
}
