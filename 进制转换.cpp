#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
int main()
{
    int input,i=0,end[50],how;char str[45];
    printf("����һ��ʮ��������");
    scanf("%d",&input);
    printf("���뽫��ת��Ϊ�����ƣ���2,8,16����");
    scanf("%d",&how);
    //printf("%b",input);
    //printf("%s",str);
    /*for(;input>0;input/=how)end[i++]=input%how;
    printf("�����");
    while(i-->0)end[i]>9?printf("%c",end[i]+55):printf("%d",end[i]);*/
    printf("%s",itoa(input,str,how));
    getch(); 
} 




//void toall(int input,int *i,int *end,int how);
void toall(int input,int *i,int *end,int how)
{
    for(;input>0;input/=how)end[(*i)++]=input%how;
}
