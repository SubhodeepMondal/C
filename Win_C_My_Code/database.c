#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n=0;
	FILE *fp,*ft;
	char another,choice='0';
	struct emp
	{
		char name[40];
		int age;
		float bs;
	};
	struct emp e;
	char empname[40];
	long int recsize;
	fp=fopen("EMP.DAT","rb+");
	if(fp==NULL)
	{
		fp=fopen("EMP.DAT","wb+");
	}
	recsize=sizeof(e);
	while(choice<5)
	{
		printf("1. Add records");
		
		printf("2.LIst Records.");
		
		printf("3.List Records.");
		
		printf("4. Delete Records.");
		
		printf("0. Exit.");
		
		printf("your choice.");
		fflush(stdin);
		choice=getche();
		switch(choice)
		{
			case 1:
			fseek(fp,0,SEEK_END);
			another='y';
			while(another='y'&&another=='Y')
			{
				printf("\nEnter name , age and basic salary:");
				scanf("%s%d%f",e.name,&e.age,&e.bs);
				fwrite(&e,recsize,1,fp);
				printf("\nAdd another record(press Y):");
				fflush(stdin);
				another=getche();
			}
			break;
		case 2:
			rewind(fp);
			while(fread(&e,recsize,1,fp)==1)
			
				printf("\n%s%d%f",e.name,e.age,e.bs);
			break;
		case 3:
			do
			{
				printf("\nEnter the name of employee to modity");
				scanf("%s",empname);
				rewind(fp);
				while(fread(&e,recsize,1,fp)==1)
				{
					if(strcmp(e.name,empname)==0)
					printf("\nEnter new name, age and basic salary:");
					scanf("%s%d%f",e.name,&e.age,&e.bs);
					fseek(fp,-recsize,SEEK_CUR);
					fwrite(&e,recsize,1,fp);
					break ;
				}
				printf("\nModity another Record(Y/N):");
				fflush(stdin);
				another=getche();
			}while(another=='y'&&another=='Y');
		case 4:
			
			do
			{
				printf("\nEnter the name of employee to delete:");
				scanf("%s",empname);
				ft=fopen("TEMP.DAT","wb");
				rewind(fp);
				while(fread(&e,recsize,1,fp)==1)
				{
					if(stcmp(e.name,empname)!=0)
						fwrite(&e,recsize,1,ft);
				}
				fclose(fp);
				fclose(ft);
				remove("EMP.DAT");
				rename("TEMP.DAT","EMP.DAT");
				fp=fopen("EMP.DAT","rb+");
				printf("Delete another record(Y/N):");
				fflush(stdin);
				another=getche();
			}while(another=='Y'&&another=='y');\
		case 0:
			fclose(fp);
			
		}
	}
}
