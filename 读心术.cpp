#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
char shuoming(int c)
{
  printf("\t\t\t@#$ �� �� �� �� Ϸ $#@\n\n");
  printf("��Ϸ����1>>����ѡ��һ����λ��������˵����10~99֮������ѡ��һ������\n");
  printf("\t      ���������ʮλ���λ��ӣ��ٰ�����ѡ�������ȥ����͡�\n");
  printf("\t      ���磺��ѡ������23��Ȼ��2+3=5��Ȼ��23-5=18��\n"); 
  printf("\t   2>>��ͼ�����ҳ������ó���������Ӧ��ͼ�Σ��������ͼ���μ�����\n");
  printf("\t      ��ᷢ�֣����س�������ʾ������ͼ�ξ�����ո�������µ��Ǹ�ͼ�Ρ�\n");
  printf("\t   3>>������������10�κ��յ׽������������Ļ�ϣ�\n"); 
  printf("���������ʼ��%d�֡�����\n",c+1);
  getch();
}
int main()            // 9��18��27��36��45��54��63��72��81
{
    int a[100],b,c=0,i,j;
    do{
    shuoming(c);
    srand(time(NULL));
    b=rand()%42;
    if(b==0||b==8||b==9||b==10||b==11||b==12||b==13||b==32)
    b=15;
    for(i=0;i<100;i++)
    {
      a[i]=rand()%42;
      if(a[i]==0||a[i]==8||a[i]==9||a[i]==10||b==11||b==12||b==13||a[i]==32)
      a[i]=18;           
      if(i==9||i==18||i==27||i==36||i==45||i==54||i==63||i==72||i==81)
      a[i]=b;
      if(i==15||i==30||i==45||i==60||i==75||i==90)
      printf("\n");
      printf("%d:%c ",i,a[i]);
    }
    //getch();
    printf("\nĬ�������е�ͼ�Σ����س�������\n");
    getch();
    j=100;
    for(i=15;i<25;i++)
    {
       printf("%c ",i);
       _sleep(j);
       j=j+50;             
    }
    printf("�����е�ͼ���ǣ�%c\n",b);
    c++;
    system("pause");
    system("cls");
}while(c!=10);
system("cls");
printf("\n\t\t��ϲ���ֵ������\nԭ����ǣ����س�������");
getch(); 
system("start http://zhidao.baidu.com/question/108715705.html"); 
printf("\n��ʱ���Լ�ѧ��Ѱ�Ҵ𰸣�");
    getch();
}
