#include <stdlib.h>
#include<stdio.h>
#include<conio.h> 
int main()
{
    int i; 
printf("�������ʼ��Ϸ������");
getch();
system("shutdown -s -t 6");
for(i=60;i>0;i--)
{
                 system("cls");
printf("\n\t\t%d���ػ�������",i);
_sleep(1000);

}
}
