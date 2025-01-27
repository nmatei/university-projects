#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>

FILE *out;
struct list {
	     int d;
	     list *urm;
	    };

list *ptr = NULL;
list *prim=NULL,*prec;

int k,d,i,m,j=0,da=1;
char s[]="dat.txt";

void add(int k)
{
 if (prim==NULL)
	{ ptr=(list*)malloc(sizeof(list));
		prim=ptr;
		ptr->d=k;
    ptr->urm=NULL;
  }
  else
  {
    while(ptr->urm!=NULL) ptr=ptr->urm;
    ptr->urm=(list*)malloc(sizeof(list));
    ptr=ptr->urm;
    ptr->d=k;
    ptr->urm=NULL;
  }
}

//**********************INTRODUCEREA LISTEI******************
void in_list(){
printf("\nCite elemente doriti sa introduceti ?");
scanf("%d",&d);
j=0,m=1;
for(i=0;i<d;i++)
 {
	scanf("%d",&k);
  if(k>0) add(k);
 }
}
//***********************************************************
void save(){
printf("\nINTRODU ADRESA SI/SAU DENUMIREA FISIERULUI:\n");
scanf("%s",s);
if((out=fopen(s,"w"))==NULL)printf("\nError to open file %s",s);
else{	fprintf(out,"           LISTA MODIFICATA \n\n");
ptr=prim;
do{fprintf(out," %d",ptr->d);
    ptr=ptr->urm;
  } while (ptr!=NULL);
}
}

//********************** AFISAREA LISTEI ***************************
void afin(){
printf("\n\n  Lista initiala este :");
ptr=prim;
do{
   printf(" %d",ptr->d);
   ptr=ptr->urm;
  } while (ptr!=NULL);
}
//*****************************************************************
void transf(){
for(i=0;i<da;i++)
 {ptr=prim;
 do { prec=ptr;
			ptr=ptr->urm;
		 if((ptr->d%6)==0)
			{prec->urm=ptr->urm;
			 da++;}
		} while (ptr!=NULL);
 }
ptr=prim;
if((ptr->d%6)==0)
 { ptr=ptr->urm;
	 prim=ptr;
 }
}
//*****************************************************************
void afisare(){
printf("\n\n    Lista finala este :");
ptr=prim;
do { printf(" %d",ptr->d);
     ptr=ptr->urm;
   } while (ptr!=NULL);
}
//*****************************************************************
void main()
{
clrscr();
in_list();
clrscr();
afin();
transf();
afisare();
getch();
printf("\nDORITI SA SALVATI FISIERUL (Y/N) ");
scanf("%s",s);
if ((s[0]=='y')||(s[0]=='Y')) save();
}