#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
//****************
void meniu();          
void meniu1();        
void rom_eng();     
void eng_rom();     
void cuvintul_R();  
void cuvintul_E();  
void salvare_R();   
void cut();             
void cut_R();         
void cut_R1();       
void add();            
void ajutor();         
void autor();          
void fereastra();
void buton();
void save();
void save1();
void dir();
void culoare();
//****************
struct dic_rom_eng
	{ char rom1[15],eng1[15],sp1;
	} *s1,a;
//****************
struct dic_eng_rom
	{ char eng2[15],rom2[15],sp2;
	} *s2,b;
//****************
struct save_f
	{ char x[15],y[15],sp3;
	} s3[100],c;
//****************
  char ch1[20];
  char fisier[15];
  int k=1,k1=1,k2=1,i,j,i1,j1,j2=0,n=0,n1=0,m=0,cutt=0;
  FILE *f1,*f2,*f3;
//**********************************************************************
void culoare(int text,int back)
{textattr(text);textbackground(back);
}
//**********************************************************************
void ajutor()
{  culoare(15,3);
gotoxy(19,5); cprintf("ษอออออออออออออออออ Ajutor อออออออออออออออออป");
for(i=0;i<16;i++)
  { gotoxy(19,6+i);cprintf("บ");gotoxy(62,6+i);cprintf("บ");}
gotoxy(19,22);cprintf("ศออออออออออออออออออออออออออออออออออออออออออผ");
culoare(0,3);
gotoxy(20,6); cprintf(" Esc - pentru a iesi din orice subprogram ");
gotoxy(20,7); cprintf(" Alt + D -> Dictionar                     ");
gotoxy(20,8); cprintf("         + R -> Roman - Englez            ");
gotoxy(20,9); cprintf("         + E -> Englez - Roman            ");
gotoxy(20,10);cprintf("         + I -> Iesire                    ");
gotoxy(20,11);cprintf(" Alt + M -> Modificare                    ");
gotoxy(20,12);cprintf("         + A -> Adaugare                  ");
gotoxy(20,13);cprintf("         + S -> Stergere                  ");
gotoxy(20,14);cprintf("         + D -> Directorii [schimbarea    ");
gotoxy(20,15);cprintf("           fisierului in care salvati]    ");
gotoxy(20,16);cprintf(" Alt + j -> Ajutor                        ");
gotoxy(20,17);cprintf(" Alt + u -> Autor                         ");
gotoxy(20,18);cprintf(" Enter   -> adaugarea cuvintului in       ");
gotoxy(20,19);cprintf("            fisierul                      ");
gotoxy(20,20);cprintf("        [disponibil in regimul dictionar] ");
gotoxy(20,21);cprintf("                                          ");
gotoxy(42,19);cprintf("[%s]",fisier);
gotoxy(21,18); getch();culoare(0,1);
j1=m;
if(k2==1)meniu();
if(k2==2)rom_eng();
if(k2==3)eng_rom();
if(k2==5)cut();
if(k2==6)dir();
}
//*************************************************************************
void autor()
{clrscr();i=0;
char s11[]="LUCRAREA DE CURS Nr:1";
char s22[]="A efectuat: Studentul Grupei TI-023: ";
gotoxy(25,2);while(i!=21)
{printf("%c",s11[i++]);delay(20);}
i=0;gotoxy(17,4);
while(i!=36)
{printf("%c",s22[i++]); delay(20);}
culoare(10,1);gotoxy(15,6);  i=100;
cprintf("ÛÛ     ÛÛ    ÛÛ   ÛÛÛÛÛÛ  ÛÛÛÛÛ  ÛÛ");gotoxy(15,7);delay(i);
cprintf("ÛÛÛ   ÛÛÛ   ÛÛÛÛ    ÛÛ    ÛÛ     ÛÛ");gotoxy(15,8);delay(i);
cprintf("ÛÛÛÛ ÛÛÛÛ  ÛÛ  ÛÛ   ÛÛ    ÛÛÛÛ   ÛÛ");gotoxy(15,9);delay(i);
cprintf("ÛÛ ÛÛÛ ÛÛ  ÛÛÛÛÛÛ   ÛÛ    ÛÛ     ÛÛ");gotoxy(15,10);delay(i);
cprintf("ÛÛ  Û  ÛÛ  ÛÛ  ÛÛ   ÛÛ    ÛÛ     ÛÛ");gotoxy(15,11);delay(i);
cprintf("ÛÛ     ÛÛ  ÛÛ  ÛÛ   ÛÛ    ÛÛÛÛÛ  ÛÛ");gotoxy(10,13);delay(i);

cprintf("ÛÛ   ÛÛ  ÛÛ   ÛÛÛ    ÛÛÛ   ÛÛ       ÛÛ    ÛÛÛÛÛ");gotoxy(10,14);delay(i);
cprintf("ÛÛÛ  ÛÛ  ÛÛ  ÛÛ ÛÛ  ÛÛ ÛÛ  ÛÛ      ÛÛÛÛ   ÛÛ   ");gotoxy(10,15);delay(i);
cprintf("ÛÛÛÛ ÛÛ  ÛÛ  ÛÛ     ÛÛ ÛÛ  ÛÛ     ÛÛ  ÛÛ  ÛÛÛÛ ");gotoxy(10,16);delay(i);
cprintf("ÛÛ ÛÛÛÛ  ÛÛ  ÛÛ     ÛÛ ÛÛ  ÛÛ     ÛÛÛÛÛÛ  ÛÛ   ");gotoxy(10,17);delay(i);
cprintf("ÛÛ  ÛÛÛ  ÛÛ  ÛÛ ÛÛ  ÛÛ ÛÛ  ÛÛ     ÛÛ  ÛÛ  ÛÛ   ");gotoxy(10,18);delay(i);
cprintf("ÛÛ   ÛÛ  ÛÛ   ÛÛÛ    ÛÛÛ   ÛÛÛÛÛ  ÛÛ  ÛÛ  ÛÛÛÛÛ");
culoare(15,1); gotoxy(20,20);cprintf("E-mail: matei_nick@yahoo.com ");
gotoxy(10,22);cprintf("Acest program a fost facut in limbajul de programare 'C' ");
gotoxy(10,23);cprintf("si cu ajutorul lui Dumnezeu a fost finisat pe 19.06.2004");
culoare(0,1); getch(); clrscr(); meniu();
}
//*************************************************************************
void cuvintul_R()
{j=0;m=0; ch1[i+1]='\0';
for(j1=0;j1<n;j1++)
 if(stricmp(ch1,s1[j1].rom1)<=0)
  {j=j1;j1=n;}
}
//*************************************************************
void cuvintul_E()
{j=0;m=0; ch1[i+1]='\0';
for(j1=0;j1<n;j1++)
 if(stricmp(ch1,s2[j1].eng2)<=0)
  {j=j1;j1=n;}
}
//***************************************************************
void save()
{
strcpy(s3[n1].x,"                 ");
strcpy(s3[n1].y,"                 ");
s3[n1].sp3='\n';
if(k2==2)
  {strcpy(s3[n1].x,s1[j].rom1);
   strcpy(s3[n1].y,s1[j].eng1);}
 if(k2==3)
  {strcpy(s3[n1].x,s2[j].eng2);
  strcpy(s3[n1].y,s2[j].rom2);}
n1++; m++;
}
//***************************************************************
void save1()
{ culoare(15,10);
gotoxy(10,4); cprintf("ษอออออออออออออ Salvare (+/-) Sortare อออออออออออป");
gotoxy(10,5); cprintf("บ                                               บ");
gotoxy(10,6); cprintf("บ                                               บ");
gotoxy(10,7); cprintf("บ                                               บ");
gotoxy(10,8); cprintf("บ                                               บ");
gotoxy(10,9); cprintf("บ                                               บ");
gotoxy(10,10);cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออผ");
culoare(4,10);
gotoxy(12,6);cprintf("Doriti sa sortati datele din fisier (d/n)?: ");
if(tolower(ch1[19]=getch())=='d')
for(m=0;m<n1-1;m++)
 for(j1=m+1;j1<n1;j1++)
  if(stricmp(s3[m].x,s3[j1].x)>0)
   { c=s3[m];
     s3[m]=s3[j1];
     s3[j1]=c;
   }
gotoxy(12,8);cprintf("Datele vor fi scrise in fisierul %s ",fisier);
getch(); culoare(15,4);
if(!(f3=fopen(fisier,"w")))
  {clrscr();
   cprintf("\n\n\n Eroare !!! fisierul %s nu poate fi deschis !!!",fisier);
   getch();
  }
fwrite(s3,sizeof(struct save_f),n1,f3);
fclose(f3); culoare(15,1);
}
//***************************************************************
void dir()
{ culoare(15,1); clrscr(); culoare(15,4);
gotoxy(15,2); cprintf("ษออออออออออออออ Directorii อออออออออออออป");
gotoxy(15,3); cprintf("บ                                       บ");
gotoxy(15,4); cprintf("บ Introduceti numele fisierului de tip  บ");
gotoxy(15,5); cprintf("บ (*.txt) in care doriti sa salvati     บ");
gotoxy(15,6); cprintf("บ cuvintele traduse :                   บ");
gotoxy(15,7); cprintf("บ                                       บ");
gotoxy(15,8); cprintf("บ                                       บ");
gotoxy(15,9); cprintf("บ                                       บ");
gotoxy(15,10); cprintf("ศอออออออออออออออออออออออออออออออออออออออผ");
culoare(15,10); gotoxy(22,8); cprintf("                          ");
gotoxy(23,8); gets(fisier);
culoare(15,4); j=0;
if(stricmp(fisier,"rom.txt")==0)
{gotoxy(15,12);cprintf(" !!! Eroare nu puteti inscrie in fisierul < rom.txt > !!! ");
 strcpy(fisier,"save.txt"); j=1; getch();
}
if(stricmp(fisier,"eng.txt")==0)
{gotoxy(15,12);cprintf(" !!! Eroare nu puteti inscrie in fisierul < eng.txt > !!! ");
 strcpy(fisier,"save.txt"); j=1; getch();
} i=0;
while(fisier[i]!='\0') i++; i--;
if(fisier[i--]!='t'||fisier[i--]!='x'||fisier[i--]!='t'||fisier[i--]!='.')
    {gotoxy(15,14);cprintf(" !!! Eroare fisierul trebuie creat cu extensia *.txt !!! ");
     strcpy(fisier,"save.txt"); j=1; getch();
    }
while(fisier[i]!='\0') i++; i=i-5;
for(i;i>=0;i--)
 if(fisier[i]=='.' || fisier[i]==',' || fisier[i]==':' || fisier[i]==';')
   {gotoxy(5,16);cprintf(" !!! Eroare numele fisierului nu poate contine '.,:;' !!! ");
    strcpy(fisier,"save.txt"); j=1; getch();
   }
if(strlen(fisier)>12)
   {gotoxy(5,18);cprintf(" !!! Eroare numele fisierului nu poate fi mai lung de 8 caractere !!! ");
    strcpy(fisier,"save.txt"); j=1; getch();
   }
k2=1; if(j==0) n1=0; meniu();
}
//***************************************************************
void fereastra()
{culoare(0,7); for(i=0;i<5;i++)
{gotoxy(13,3+i);cprintf("บ                                        บ");}
gotoxy(13,2);cprintf("ษออออออออออออออออออออออออออออออออออออออออป");
gotoxy(13,8);cprintf("ศออออออออออออออออออออออออออออออออออออออออผ");
culoare(15,10); gotoxy(19,6);cprintf("                              ");
culoare(15,15); gotoxy(13,10);
cprintf("ษอออออออออออออออออออหออออออออออออออออออออป");gotoxy(13,21);
cprintf("ศอออออออออออออออออออสออออออออออออออออออออผ");
for(i=0;i<10;i++)
{gotoxy(13,11+i);cprintf("บ                   ");
 gotoxy(54,11+i);cprintf("บ");
 gotoxy(33,11+i);cprintf("บ                    ");
}
culoare(0,15);
  gotoxy(57,10); cprintf("ษออออออออออออออออป");
  gotoxy(57,21); cprintf("ศออออออออออออออออผ");
  for(i=0;i<10;i++)
   {gotoxy(57,11+i);cprintf("บ                บ");}
culoare(4,15); gotoxy(59,10); cprintf(" %s ",fisier);
culoare(0,7); gotoxy(2,25);
cprintf(" F1 Ajutor    Esc Meniu                                                       ");
culoare(4,7); gotoxy(3,25);cprintf("F1"); gotoxy(16,25);cprintf("Esc");
}
//***************************************************************
void eng_rom()
{ clrscr(); fereastra();culoare(0,7);
gotoxy(19,4);cprintf(" Write the word to find:");
i=0; i1=0; j=0; m=j1; culoare(15,4);
 gotoxy(57,2); cprintf("ษอออออออออออออป");
 gotoxy(57,3); cprintf("บ If you want บ");
 gotoxy(57,4); cprintf("บ to copy in  บ");
 gotoxy(57,5); cprintf("บ             บ");
 gotoxy(57,6); cprintf("บ             บ");
 gotoxy(57,7); cprintf("บ   <Enter>   บ");
 gotoxy(57,8); cprintf("ศอออออออออออออผ");
 gotoxy(59,5); cprintf("%s",fisier);
do
 {culoare(0,15);
for(j1=0;j1<10;j1++)
{gotoxy(14,11+j1);cprintf("               ");
 gotoxy(34,11+j1);cprintf("               ");
}
for(j1=j,i1=0;j1<n&&j1<(j+10);j1++,i1++)
 {gotoxy(14,11+i1);cprintf("              ");
  gotoxy(14,11+i1);cprintf(" %s",s2[j1].eng2);}
for(j1=j,i1=0;j1<n&&j1<(j+10);j1++,i1++)
 {gotoxy(34,11+i1);cprintf("              ");
  gotoxy(34,11+i1);cprintf(" %s",s2[j1].rom2);}
for(j1=n1-1,i1=0;j1>=0 && i1<10;j1--,i1++)
  {gotoxy(59,11+i1);cprintf("              ");
   gotoxy(59,11+i1);cprintf("%s",s3[j1].x);}
culoare(15,10);
gotoxy(14,11);cprintf("                   ");
gotoxy(14,11);cprintf(" %s",s2[j].eng2);
gotoxy(34,11);cprintf("                    ");
gotoxy(34,11);cprintf(" %s",s2[j].rom2);
if(i<0)i=0; if(i>28)i=0;
gotoxy(20+i,6); ch1[i]=getche(); i1=i;
switch(ch1[i])
 { case 27 :culoare(0,1);clrscr();k2=1;
	    if(m!=0) save1();meniu();break;
   case 8  :i=i-2;i1=i;gotoxy(21+i,6);cprintf(" ");break;
   case 13 :i1++;save();break;
   case 0: ch1[i]=getche(); i1++;
	   switch(ch1[i])
	     { case 80 :if(j<n-1){j++;for(j1=0;j1<=i;j1++)
		       ch1[j1]=s2[j].eng2[j1];}
		       gotoxy(21+i,6);cprintf("  ");break;
	       case 72 :if(j>0){j--;for(j1=0;j1<=i;j1++)
		       ch1[j1]=s2[j].eng2[j1];}
		       gotoxy(21+i,6);cprintf("  ");break;
	       case 59 :ajutor();getch();break; // F1
	     }break;
 }
if(i1==i){cuvintul_E(); i++;}
 } while(1);
}
//*************************************************************************
void rom_eng()
{ clrscr(); fereastra(); culoare(0,7);
gotoxy(19,4);cprintf(" Introduceti cuvintul cautat: ");
i=0; i1=0; j=0; m=j1; culoare(15,4);
 gotoxy(57,2); cprintf("ษอออออออออออออออป");
 gotoxy(57,3); cprintf("บ Daca doriti   บ");
 gotoxy(57,4); cprintf("บ sa copiati in บ");
 gotoxy(57,5); cprintf("บ               บ");
 gotoxy(57,6); cprintf("บ               บ");
 gotoxy(57,7); cprintf("บ    <Enter>    บ");
 gotoxy(57,8); cprintf("ศอออออออออออออออผ");
 gotoxy(59,5);cprintf("%s",fisier);
do
 { culoare(0,15);
for(j1=0;j1<10;j1++)
 {gotoxy(14,11+j1);cprintf("               ");
  gotoxy(34,11+j1);cprintf("               ");
 }
for(j1=j,i1=0;j1<n&&j1<(j+10);j1++,i1++)
 {gotoxy(14,11+i1);cprintf("              ");
  gotoxy(14,11+i1);cprintf(" %s",s1[j1].rom1);}
for(j1=j,i1=0;j1<n&&j1<(j+10);j1++,i1++)
 {gotoxy(34,11+i1);cprintf("              ");
  gotoxy(34,11+i1);cprintf(" %s",s1[j1].eng1);}
for(j1=n1-1,i1=0;j1>=0 && i1<10;j1--,i1++)
  {gotoxy(59,11+i1);cprintf("              ");
   gotoxy(59,11+i1);cprintf("%s",s3[j1].x);}
culoare(15,10);
gotoxy(14,11);cprintf("                   ");
gotoxy(14,11);cprintf(" %s",s1[j].rom1);
gotoxy(34,11);cprintf("                    ");
gotoxy(34,11);cprintf(" %s",s1[j].eng1);
if(i<0)i=0; if(i>28)i=0;
gotoxy(20+i,6); ch1[i]=getche(); i1=i;
switch(ch1[i])
 { case 27 :culoare(0,1);clrscr();k2=1;
	    if(m!=0) save1(); meniu();break;
   case 8  :i=i-2;i1=i;gotoxy(21+i,6);cprintf(" ");break;
   case 13 :i1++;save();break;
   case 0: ch1[i]=getche(); i1++;
	   switch(ch1[i])
	     {case 80 :if(j<n-1){j++;for(j1=0;j1<=i;j1++)
		       ch1[j1]=s1[j].rom1[j1];}
		       gotoxy(21+i,6);cprintf("  ");break;
	      case 72 :if(j>0){j--;for(j1=0;j1<=i;j1++)
		       ch1[j1]=s1[j].rom1[j1];}
		       gotoxy(21+i,6);cprintf("  ");break;
	      case 59 :ajutor();getch();break; // F1
	     }break;
 }
if(i1==i) {cuvintul_R();i++;}
 } while(1);
}
//*************************************************************************
void add()
{clrscr();culoare(0,7);
for(i=0;i<5;i++)
{gotoxy(18,5+i);cprintf("บ                                        บ");}
gotoxy(18,4); cprintf("ษออออออออออออออออออออออออออออออออออออออออป");
gotoxy(18,10);cprintf("ศออออออออออออออออออออออออออออออออออออออออผ");
culoare(15,10); gotoxy(28,6);cprintf("                              ");
gotoxy(28,8);cprintf("                              ");
culoare(1,7); gotoxy(20,6);cprintf("Romana: ");
gotoxy(20,8);cprintf("Engleza:");
culoare(4,7);gotoxy(18,2); cprintf(" Cite cuvinte doriti sa introduceti?:");
gotoxy(60,2);cprintf("     "); gotoxy(61,2);cscanf("%d",&m);
if(m>10)m=10; culoare(15,10); i=n; n=n+m;
if(m!=0)
{free(s1);
 s1=(struct dic_rom_eng*)malloc(sizeof(struct dic_rom_eng)*n);
for(i=0;i<n-m;i++)
 {strcpy(s1[i].rom1,"                 ");
  strcpy(s1[i].eng1,"                 ");
  s1[i].sp1='\n';
 }
for(i=0;i<n-m;i++)
 {strcpy(s1[i].eng1,s2[i].eng2); strcpy(s1[i].rom1,s2[i].rom2);}
}
gotoxy(10,5);cprintf("     ");
gotoxy(10,6);cprintf("     ");
gotoxy(10,7);cprintf("     ");
while(i<n)
	{ fflush(stdin);
	  gotoxy(29,6);cprintf("                         ");
	  gotoxy(29,8);cprintf("                         ");
	  gotoxy(11,6);cprintf(" %d",n-i);
	  strcpy(s1[i].rom1,"                 ");
	  strcpy(s1[i].eng1,"                 ");
	  gotoxy(29,6);gets(s1[i].rom1); fflush(stdin);
	  gotoxy(29,8);gets(s1[i].eng1); fflush(stdin);
	  s1[i].sp1='\n';fflush(stdin);
	i++;
  }
getch(); salvare_R();
}
//*************************************************************************
void salvare_R()
{ culoare(10,4);
//*** SORTARE ***
for(i=0;i<n-1;i++)
 for(j=i+1;j<n;j++)
  if(stricmp(s1[i].rom1,s1[j].rom1)>0)
   { a=s1[i];
     s1[i]=s1[j];
     s1[j]=a;
   }
if(!(f1=fopen("rom.txt","w")))
 { clrscr();
   cprintf("\n\n\n Eroare !!! fisierul 'rom.txt' nu poate fi deschis !!!");
   getch();exit(0);
 }
fwrite(s1,sizeof(struct dic_rom_eng),n,f1);
fclose(f1);
if(!(f2=fopen("eng.txt","w")))
  { clrscr();
    cprintf("\n\a Eroare !!! fisierul 'eng.txt' nu a fost deschis !!!");
    getch();exit(0);
  }
fclose(f2);
free(s2);
s2=(struct dic_eng_rom*)malloc(sizeof(struct dic_eng_rom)*n);
for(i=0;i<n;i++)
 {strcpy(s2[i].rom2,"                 ");
  strcpy(s2[i].eng2,"                 ");
  s2[i].sp2='\n';
 }
for(i=0;i<n;i++)
 { strcpy(s2[i].eng2,s1[i].eng1); strcpy(s2[i].rom2,s1[i].rom1); }
//*** SORTARE ***
for(i=0;i<n-1;i++)
 for(j=i+1;j<n;j++)
  if(stricmp(s2[i].eng2,s2[j].eng2)>0)
   { b=s2[i];
     s2[i]=s2[j];
     s2[j]=b;
   }
if(!(f2=fopen("eng.txt","w")))
 { clrscr();
   cprintf("\n\a Eroare !!! fisierul 'eng.txt' nu a fost deschis !!!");
   getch();exit(0);
 }
fwrite(s2,sizeof(struct dic_eng_rom),n,f2); fclose(f2);
culoare(0,1); clrscr(); k2=1; meniu();
}
//*************************************************************************
void cut_R()
{ culoare(0,1); clrscr(); culoare(0,7);
for(i=0;i<5;i++)
{gotoxy(18,3+i);cprintf("บ                                        บ");}
gotoxy(18,2);cprintf("ษออออออออออออออออออออออออออออออออออออออออป");
gotoxy(18,8);cprintf("ศออออออออออออออออออออออออออออออออออออออออผ");
gotoxy(24,4);cprintf(" Doriti sa taiati -> ");cputs(s1[j].rom1);
j1=2; buton();
while(1)
{ch1[0]=getch();
switch (ch1[0])
	{ case 77 :(j1<2)?(j1++):(j1=1);buton();break;
	  case 75 :(j1>1)?(j1--):(j1=2);buton();break;
	  case 80 :(j1<2)?(j1++):(j1=1);buton();break;
	  case 72 :(j1>1)?(j1--):(j1=2);buton();break;
	  case 27 :_setcursortype(_NORMALCURSOR);cut();break;
	  case 13 :_setcursortype(_NORMALCURSOR);cut_R1();break;
	}
}}
//**********************************************************************
void buton()
{ _setcursortype(_NOCURSOR); culoare(0,7);
  gotoxy(25,6); cprintf("บ  DA  บ");
  gotoxy(40,6); cprintf("บ  NU  บ"); culoare(0,10);
if(j1==1){gotoxy(26,6); cprintf("  DA  ");}
if(j1==2){gotoxy(41,6); cprintf("  NU  ");}
}
//**********************************************************************
void cut_R1()
{ if(j1==1){n--;
for(j1=j;j1<n;j1++)
 s1[j1]=s1[j1+1];
 strcpy(s1[j1].rom1,"                 ");
 strcpy(s1[j1].eng1,"                 ");
 strcpy(s2[j1].rom2,"                 ");
 strcpy(s2[j1].eng2,"                 ");
}cut();
}
//*********************************************************************
void cut()
{culoare(14,1); clrscr();
fereastra(); culoare(0,7);
gotoxy(19,4);cprintf(" Tasta  DELETE  pentru a taia:  ");
culoare(4,3); gotoxy(26,4);cprintf(" DELETE ");
i=0;j=0;
do
 { culoare(0,15);
for(j1=0;j1<10;j1++)
  {gotoxy(14,11+j1);cprintf("               ");
   gotoxy(34,11+j1);cprintf("               ");
  }
for(j1=j,i1=0;j1<n&&j1<(j+10);j1++,i1++)
 {gotoxy(14,11+i1);cprintf("              ");
  gotoxy(14,11+i1);cprintf(" %s",s1[j1].rom1);}
for(j1=j,i1=0;j1<n&&j1<(j+10);j1++,i1++)
 {gotoxy(34,11+i1);cprintf("              ");
  gotoxy(34,11+i1);cprintf(" %s",s1[j1].eng1);}
culoare(4,10);
gotoxy(2,11);cprintf(" DELETE ? ");
gotoxy(14,11);cprintf("                   ");
gotoxy(14,11);cprintf(" %s",s1[j].rom1);
gotoxy(34,11);cprintf("                    ");
gotoxy(34,11);cprintf(" %s",s1[j].eng1);
culoare(15,10);
if(i<0)i=0;
if(i>28)
{i=0;gotoxy(20,6);cprintf("                             ");}
 gotoxy(20+i,6);ch1[i]=getche();i1=i;
 switch(ch1[i])
  { case 27 :salvare_R();break;
		case 8  :i=i-2;i1=i;gotoxy(21+i,6);cprintf(" ");break;
    case 13 :i--;break;
    case 0: ch1[i]=getche(); i1++;
	   switch(ch1[i])
	     {case 83 :cut_R();break; // DELETE
	      case 80 :if(j<n-1){j++;for(j1=0;j1<=i;j1++)
		       ch1[j1]=s1[j].rom1[j1];}
		       gotoxy(21+i,6);cprintf("  ");break;
	      case 72 :if(j>0){j--;for(j1=0;j1<=i;j1++)
		       ch1[j1]=s1[j].rom1[j1];}
		       gotoxy(21+i,6);cprintf("  ");break;
	      case 59 :ajutor();getch();break; // F1
	     }break;
  }
if(i1==i){cuvintul_R(); i++;}
 } while(1);
}
//*************************************************************************
void meniu1()
{culoare(15,1); gotoxy(1,4);
cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
culoare(0,7); gotoxy(3,1);
cprintf("ษอออออออออออหออออออออออออหออออออออหอออออออป");gotoxy(3,2);
cprintf("บ Dictionar บ Modificare บ Ajutor บ Autor บ");gotoxy(3,3);
cprintf("ศอออออออออออสออออออออออออสออออออออสอออออออผ");
culoare(0,10);gotoxy(4,2);
if (k==1) cprintf(" Dictionar "); gotoxy(16,2);
if (k==2) cprintf(" Modificare "); gotoxy(29,2);
if (k==3) cprintf(" Ajutor "); gotoxy(38,2);
if (k==4) cprintf(" Autor ");
culoare(4,7);gotoxy(5,2);
if (k!=1) cprintf("D"); gotoxy(17,2);
if (k!=2) cprintf("M"); gotoxy(31,2);
if (k!=3) cprintf("j"); gotoxy(40,2);
if (k!=4) cprintf("u");
culoare(4,10);gotoxy(5,2);
if (k==1) cprintf("D"); gotoxy(17,2);
if (k==2) cprintf("M"); gotoxy(31,2);
if (k==3) cprintf("j"); gotoxy(40,2);
if (k==4) cprintf("u"); culoare(1,1);
for(i=0;i<4;i++)
{gotoxy(2,5+i);cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");}
if(k==1)
{ culoare(0,15);                gotoxy(3,3);
  cprintf("บ           ศออออป");gotoxy(3,4);
  cprintf("บ Roman - Englez บ");gotoxy(3,5);
  cprintf("บ Englez - Roman บ");gotoxy(3,6);
  cprintf("บ Iesire < Esc > บ");gotoxy(3,7);
  cprintf("ศออออออออออออออออผ"); culoare(0,10); gotoxy(4,4);
if (k1==1) cprintf(" Roman - Englez ");gotoxy(4,5);
if (k1==2) cprintf(" Englez - Roman ");gotoxy(4,6);
if (k1==3) cprintf(" Iesire < Esc > "); culoare(4,7); gotoxy(5,4);
if (k1!=1) cprintf("R"); gotoxy(5,5);
if (k1!=2) cprintf("E"); gotoxy(5,6);
if (k1!=3) cprintf("I"); culoare(4,10); gotoxy(5,4);
if (k1==1) cprintf("R"); gotoxy(5,5);
if (k1==2) cprintf("E"); gotoxy(5,6);
if (k1==3) cprintf("I"); culoare(0,0);
for(i=0;i<4;i++){gotoxy(21,5+i);cprintf("  ");}
gotoxy(4,8);cprintf("                 ");
  }
if(k==2)
	{ culoare(0,15);               gotoxy(15,3);
    cprintf("บ            ศออป");gotoxy(15,4);
    cprintf("บ => Adaugare   บ");gotoxy(15,5);
    cprintf("บ => Stergere   บ");gotoxy(15,6);
    cprintf("บ => Directorii บ");gotoxy(15,7);
    cprintf("ศอออออออออออออออผ");culoare(0,10); gotoxy(16,4);
if (k1==1) cprintf(" => Adaugare   ");gotoxy(16,5);
if (k1==2) cprintf(" => Stergere   ");gotoxy(16,6);
if (k1==3) cprintf(" => Directorii ");culoare(4,7); gotoxy(20,4);
if (k1!=1) cprintf("A"); gotoxy(20,5);
if (k1!=2) cprintf("S"); gotoxy(20,6);
if (k1!=3) cprintf("D"); culoare(4,10);gotoxy(20,4);
if (k1==1) cprintf("A"); gotoxy(20,5);
if (k1==2) cprintf("S"); gotoxy(20,6);
if (k1==3) cprintf("D"); culoare(0,0);
for(i=0;i<4;i++){gotoxy(32,5+i);cprintf("  ");}
gotoxy(16,8);cprintf("                ");
}}
//*************************************************************************
void meniu()
{ int ch; culoare(15,1); clrscr();
_setcursortype(_NOCURSOR); gotoxy(1,4);
cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
for(i=0;i<19;i++)
 {gotoxy(1,5+i);cprintf("บ"); gotoxy(80,5+i);cprintf("บ");}
cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
culoare(0,15);gotoxy(1,1);
for(i=0;i<4;i++)
cprintf("                                                                     ");
culoare(15,1);gotoxy(1,4); gotoxy(48,2);cprintf(" RO / ENG ");
gotoxy(62,2);cprintf(" ENG / RO ");
meniu1();
culoare(10,1);gotoxy(20,12);
cprintf(" ÛÛÛÛÛ   ÛÛ   ÛÛÛ  ÛÛÛÛÛÛ  ÛÛ   ÛÛÛ  ");gotoxy(20,13);
cprintf(" ÛÛ  ÛÛ  ÛÛ  ÛÛ ÛÛ   ÛÛ    ÛÛ  ÛÛ ÛÛ ");gotoxy(20,14);
cprintf(" ÛÛ  ÛÛ  ÛÛ  ÛÛ      ÛÛ    ÛÛ  ÛÛ ÛÛ ");gotoxy(20,15);
cprintf(" ÛÛ  ÛÛ  ÛÛ  ÛÛ      ÛÛ    ÛÛ  ÛÛ ÛÛ ");gotoxy(20,16);
cprintf(" ÛÛ  ÛÛ  ÛÛ  ÛÛ ÛÛ   ÛÛ    ÛÛ  ÛÛ ÛÛ ");gotoxy(20,17);
cprintf(" ÛÛÛÛÛ   ÛÛ   ÛÛÛ    ÛÛ    ÛÛ   ÛÛÛ  ");gotoxy(20,18);
cprintf("                     **                        ");
culoare(0,7);gotoxy(2,25);
cprintf(" F1 Ajutor   F2 Autor   Esc Exit                                              ");
culoare(4,7); gotoxy(3,25);cprintf("F1");
gotoxy(15,25);cprintf("F2");gotoxy(26,25);cprintf("Esc");
while (1)
 {culoare(0,1);
  ch=getch();
  switch (ch)
	{ case 77 :(k<4)?(k++):(k=1);k1=1;meniu1();break;
	  case 75 :(k>1)?(k--):(k=4);k1=1;meniu1();break;
	  case 80 :if(k==1){(k1<3)?(k1++):(k1=1);} else
		   if(k==2){(k1<3)?(k1++):(k1=1);}
		   meniu1();break;
	  case 72 :if(k==1){(k1>1)?(k1--):(k1=3);} else
		   if(k==2){(k1>1)?(k1--):(k1=3);}
			 meniu1();break;
	  case 27 :free(s1);free(s2);exit(0);
	  case 59 :ajutor();getch();break; // F1
	  case 60 :_setcursortype(_NOCURSOR);textcolor(15);autor();getch();break;  // F2
	  case 32 :k=1;k1=1;meniu1();break; // Alt + D
	  case 50 :k=2;k1=1;meniu1();break; // Alt + M
	  case 36 :k=3;k1=1;meniu1();break; // Alt + j
	  case 22 :k=4;k1=1;meniu1();break; // Alt + u
	  case 114 :if(k==1)
		  {_setcursortype(_NORMALCURSOR);textcolor(10);k1=1;k2=2;j1=0;rom_eng();}break; // r
	  case 82 :if(k==1)
		  {_setcursortype(_NORMALCURSOR);textcolor(10);k1=1;k2=2;j1=0;rom_eng();}break; // R
	  case 101 :if(k==1)
		  {_setcursortype(_NORMALCURSOR);textcolor(10);k1=2;k2=3;j1=0;eng_rom();}break; // e
	  case 69 :if(k==1)
		  {_setcursortype(_NORMALCURSOR);textcolor(10);k1=2;k2=3;j1=0;eng_rom();}break; // E
	  case 105 :if(k==1) free(s1);free(s2);exit(0);break; // I
	  case 73 :if(k==1) free(s1);free(s2);exit(0);break; // i
	  case 97 :if(k==2)
		  {_setcursortype(_NORMALCURSOR);textcolor(10);k1=1;k2=4;add();}break; // a
	  case 65 :if(k==2)
			{_setcursortype(_NORMALCURSOR);textcolor(10);k1=1;k2=4;add();}break; // A
	  case 115 :if(k==2)
		  {_setcursortype(_NORMALCURSOR);textcolor(10);k1=2;k2=5;cut();}break; // s
	  case 83 :if(k==2)
		  {_setcursortype(_NORMALCURSOR);textcolor(10);k1=2;k2=5;cut();}break; // S
	  case 100 :if(k==2)
		  {_setcursortype(_NORMALCURSOR);k1=3;k2=6;dir();}break; // d
	  case 68 :if(k==2)
		  {_setcursortype(_NORMALCURSOR);k1=3;k2=6;dir();}break; // D
	  case 13 : switch (k)
		 { case 1 :_setcursortype(_NORMALCURSOR);textcolor(10);
			   if(k1==1){ k2=2; j1=0; rom_eng(); } else
			   if(k1==2){ k2=3; j1=0; eng_rom(); } else
			   if(k1==3) free(s1);free(s2);exit(0);getch();break;
		   case 2 :_setcursortype(_NORMALCURSOR);textcolor(10);
			   if(k1==1){ k2=4; add(); } else
			   if(k1==2){ k2=5; cut(); } else
			   if(k1==3){ k2=6; dir(); } getch();break;
		   case 3 :textcolor(10);k2=1;ajutor();getch();break;
		   case 4 :_setcursortype(_NOCURSOR);textcolor(15);
			   k2=1;autor();getch();break;
}}}}
//*************************************************************************
void main()
{culoare(0,1);clrscr(); n=0;
if(!(f1=fopen("rom.txt","r")))
 { culoare(10,4);clrscr();
   cprintf("\n\a Eroare !!! fisierul 'rom.txt' nu a fost deschis !!!");
   getch();exit(0);
 }
fseek(f1,0L,SEEK_END);
n=ftell(f1)/sizeof(struct dic_rom_eng);
fseek(f1,0L,SEEK_SET); free(s1);
s1=(struct dic_rom_eng*)malloc(sizeof(struct dic_rom_eng)*n);
fread(s1,sizeof(struct dic_rom_eng),n,f1); fclose(f1);
strcpy(fisier,"save.txt");
salvare_R(); meniu();
getch();
}
