#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char tag[3]={"\0"};//ID3V1��־
    char mname[30]={"\0"};//������
    char artist[30]={"\0"};//������
    char album[30]={"\0"};//ר��
    char year[4]={"\0"};//���
    char comments[28]={"\0"};//ע��
    char reseved[1];//����λ(ûʲô��˼)
    char track[1];//����(����),���ǵڼ��׸�
    char genre[1];//���
    FILE *p;
    if((p=fopen("d:/1.mp3","rb"))==NULL)return 0;
    fseek(p,-128,SEEK_END);
    fread(tag,3,1,p);
    if(strstr(tag,"TAG")==NULL)
    {
        printf("���������ļ�");getch();return 0;                       
    }
    fread(mname,30,1,p);
    fread(artist,30,1,p);
    fread(album,30,1,p);
    fread(year,3,1,p);
    fread(comments,28,1,p);
    fread(reseved,1,1,p);
    fread(track,1,1,p);
    fread(genre,1,1,p);
    printf("%s\n��������%s\n��Ƭ����%s\n��  �֣�%s\n��  ����%s\nע  �ͣ�%s\n��  �죺%s\n��  ��%s",tag,mname,artist,album,year,comments,track,genre);
    fclose(p);
    getch();
} 
