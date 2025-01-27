#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
char s[100],*ps1,*ps2,cuv[100][30];
int cont=0,i=0,j=0,k=0,n=0,m[25];
//**************
void L_sir()
{ while(s[cont]!='\0')
		cont++;
		cont--;
}//*************
void main()
{ textcolor(10);
float d;
clrscr();
printf("Introdu propozitia\n");
gets(s);
L_sir();
ps2=s;
i=0;
while(i<cont)
 {j=0;
	 while((ps2[i]!=' ')&&(ps2[i]!='.')&&(ps2[i]!=',')&&
		(ps2[i]!=';')&&(ps2[i]!='?')&&(ps2[i]!='!')&&(ps2[i]!='\0'))
		cuv[k][j++]=ps2[i++];
		m[k]=j;
	i++;k++;
 }
clrscr();
for(i=1;i<(k+1);i++)
	{textattr(14);
cprintf("Cuvintul %i este ",i);
	 textattr(10);
cprintf(cuv[i-1]);
	 textattr(11);
cprintf(" -> %i",m[i-1]);
	 printf("\n");
	}
for(i=0;i<k-1;i++)
 { j=0;
	 while(cuv[i][j]!='\0')
	 ps1[n++]=cuv[i][j++];
	 for(j=0;j<(abs(m[i]-m[i+1])+1);j++)
	 ps1[n++]='.';
 }
j=0;
while(cuv[k-1][j]!='\0')
ps1[n++]=cuv[k-1][j++];
ps1[n]='\0';
printf("\n");
textattr(12);
cprintf("Propozitia finala este:");
printf("\n");
i=0;
while(i<n)
 { s[i]=ps1[i];
	 i++;
 }
s[i+1]='\0';
puts(s);
for(i=0;i<k-1;i++)
 { d+=abs(m[i]-m[i+1]); }
printf("\nDistanta medie = %f",d/i);
getch();
}
