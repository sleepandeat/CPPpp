#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 
#include<windows.h>
#include<conio.h>
int main(int argc,char *argv[])
{
    int i; 
    printf("����һ���У�%d�����ֱ�Ϊ��",argc);
    while(argc--)printf("%s,",argv[argc]);
} 
