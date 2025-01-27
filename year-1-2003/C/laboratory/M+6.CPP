 #include<stdio.h>
 #include<conio.h>
 #include<math.h>
 #include<string.h>
   void main()
{    textcolor(10);
	 char s1[100],s2[100],cuv[100][100],m[100];
	 int i=0,j=0,k=0;clrscr();
	 float d;
	 printf("introdu propozitia\n");
	 gets(s1);
	 clrscr();
	 puts(s1);
	 k=0;
	 while(i<strlen(s1))
	{  j=0;
	while((s1[i]!=' ')&&(s1[i]!='.'))
	   {
	   s2[j]=s1[i];j++;i++;
	   }
	s2[j]='\0';
	m[k]=strlen(s2);
	i++;
	strcpy(cuv[k++],s2);
	puts(s2);
	}
	   clrscr();
	   char finit[200]="";
	   for(i=0;i<k-1;i++)
	 {
	 strcat(finit,cuv[i]);
	 for(j=0;j<(abs(m[i]-m[i+1])+1);j++) strcat(finit,".");
	 }
	for(i=1;i<k+1;i++)
	{  textattr(14);
	cprintf("Cuvintul %i este ",i);
	   textattr(10);
	cprintf(cuv[i-1]);
	   textattr(11);
	cprintf(" (%i)",m[i-1]);
	   printf("\n");
	}
	   printf("\n");
	   strcat(finit,cuv[k-1]);
	   puts(finit);
	for(i=0;i<k-1;i++)
	{
	  d+=abs(m[i]-m[i+1]);
	}
	printf("\ndistanta medie = %f",d/i);
	getch();
}