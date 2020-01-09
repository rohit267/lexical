#include<string.h> 

#include<stdio.h>
//#include<stdlib.h>
#include<ctype.h>

//#include<conio.h>

FILE *f4,*f5;

void keyword(char str[20])

{

	f4=fopen("keyword","a");

	f5=fopen("variables","a");

	if(strcmp(str,"for")==0||strcmp("while",str)==0

	||strcmp("do",str)==0||strcmp("int",str)==0||

	strcmp("float",str)==0||strcmp("char",str)==0||

	strcmp("double",str)==0||strcmp("static",str)==0||

	strcmp("switch",str)==0||strcmp("case",str)==0||strcmp("main",str)==0||strcmp("void",str)==0)

	{

	fprintf(f4,"%s",str);

	

	putc(' ',f4);}

	else

	{

	fprintf(f5,"%s",str);

	

		putc(' ',f5);}

	fclose(f4);

	fclose(f5);

}

int main()

{

	FILE *f1,*f2,*f3;

	int tokenvalue=0,num[100],i=0,j=0,lineno=0;

	char input[15],string1[20],c;

	printf("enter the file name");

	scanf("%s",input);

	f4=fopen("keyword","w");

	f5=fopen("variables","w");

	fclose(f4);

	fclose(f5);

	f1=fopen(input,"r");

	f2=fopen("identifier","w"); f3=fopen("specialchar","w");

	

	while((c=getc(f1))!=EOF)

	{

		if(isdigit(c))

		{

			tokenvalue=c-'0';
			
			
			c=getc(f1);
			

			while(isdigit(c))

			{

				tokenvalue=tokenvalue*10+(c-'0');
				
				c=getc(f1);

			}

			num[i++]=tokenvalue;
			//printf("%d",num[0]);
			ungetc(c,f1);


		}

		else

		{   if(isalpha(c))

			{

				putc(c,f2);

				c=getc(f1);

				while(isdigit(c)||isalpha(c)||c=='_'||c=='$'||c=='['||c==']')

				{

				putc(c,f2);

				c=getc(f1);	

				}

				ungetc(c,f1);

				putc(' ',f2);

			}

			

		

	/*	else if(c==' '||c=='\t')

			printf(" ");*/

		

		else if(c=='\n')

			lineno++;

		else 

			putc(c,f3);

		} 

		}

		fclose(f1);

			fclose(f2);

				fclose(f3);

		

		f2=fopen("identifier","r");

		while(!feof(f2))

		{

			fscanf(f2,"%s",string1);

			keyword(string1);	

		}

		fclose(f2);

		f3=fopen("specialchar","r");

		printf("special charecters are");

		while((c=getc(f3))!=EOF)

		{printf("%c",c);

				}	

				printf("\n");

				 fclose(f3); 

				 printf("Total no. of lines are: %d",lineno);	

				 printf("Total Constants are: ");
					for(j=0;j<i;j++)
						printf(" %d ",num[j] );
	

		f4=fopen("keyword","r");

		printf("\n keywords:"); 

		while(!feof(f4))

		{

			fscanf(f4,"%s",string1);

			printf(" %s ",string1);	

		}

		f5=fopen("variables","r");

		printf("\n variables:");	

			while(!feof(f5))

		{

			fscanf(f5,"%s",string1);

			printf("  %s   ",string1);	

		}	

		fclose(f4);

	fclose(f5);

	return(0);

}
