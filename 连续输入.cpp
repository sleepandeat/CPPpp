#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(void)
{
	int a , b;char i;
printf("�������������м�ո�\n");
scanf("%d%c",&a,&i);
do
{
	scanf("%d%c",&b,&i);
	if(a>b&&i=='\n');
	else
		a=b;
}while(i!='\n');
printf("%d",a);getch(); 
return 0;
} 
/*
int main()
{
    int a,b=0,i=0,j;
    char str[1000],data[10];
    printf("�������⼸�������ÿո������\n"); 
    gets(str); 
    while(str[i++]!='\0')
    {
        for(j=0;str[i]!=' '&&str[i]!='\0';i++,j++)
            data[j]=str[i]; 
        data[j]='\0';
        a=atoi(data);
        if(a>b)b=a;
    }
    printf("�����Ϊ��%d",b);
    getch();
} 
*/
