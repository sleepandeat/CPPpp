#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 
#include<windows.h>
#include<conio.h>
long rand_time;
struct food
{
    long l_time;
    int wait_time;
    int  chois[5];
    char show_time[20];
    struct food *next;
}; 
struct food *head,*node1,*node2;
int use_time[]={5,2,10,1,5};
void gotoxy(int x, int y)
{
     COORD coord;
	 coord.X = x,coord.Y=y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void now_time(char *rt_time,long *int_time)
{
    struct tm * timeinfo;
	//time(rand_time);
	rand_time+=rand()%600+10;
    *int_time=rand_time;
	timeinfo = localtime(&rand_time);
	wsprintf(rt_time,"%02d:%02d:%02d",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
}
//1����˿(5����)  2����������2���ӣ�  3�������㣨10���ӣ�  4�����ײˣ�1���ӣ�  5����������5���ӣ�
void link_node(struct food *new_node)
{
     int i;new_node->wait_time=0;
     for(i=0;i<5;i++)
       if(new_node->chois[i]!=0)
          new_node->wait_time+=use_time[i];
     if(head==NULL)
     {
         head=new_node;
         return;
     }
     node1=head;
     while(node1!=NULL)
     {
        node2=node1;
        for(i=0;i<5;i++)
           if(node2->chois[i]!=0)
              new_node->wait_time+=use_time[i];
        node1=node1->next;
     }
     node2->next=new_node;
}
int main()
{
    char name[][50]={"���ײ�","������","������","��˿","������"},str[50],data[256]; 
    int  waitDishes[5];
    int i=0,j,tt=0;FILE *p;
    struct food *new_node;
    memset(waitDishes,0,sizeof(waitDishes));
    srand(time(NULL));time(&rand_time);
    //printf("˵����\n5���������һ�Σ������������ѭ���������ļ���Ϊ����������.txt��\n���������ʼ....");getch();
    printf("�����������������");scanf("%d",&tt);
    while(tt--)
    {
        //system("cls");
        if((p=fopen("��������.txt","w"))==NULL)
        {
            printf("�����ļ�ʧ�ܣ���ȷ����������д����ļ���Ȩ�ޡ�\n�����������...");getch();
        } 
        new_node=(struct food *)malloc(sizeof(struct food));
        memset(new_node->chois,0,sizeof(new_node->chois));
        for(i=rand()%5+1;i>0;i--)//����㼸�ݲ� 
        {
            j=rand()%5;
            waitDishes[j]++;//�ò�Ʒ������������ 
            new_node->chois[j]++;//ѡ��Ĳ�Ʒ��� 
        }
        now_time(new_node->show_time,&new_node->l_time);
        new_node->next=NULL;
        link_node(new_node);
    } 
    node1=head;i=1; 
    fputs("----------------����ʱ��----------------\n�� ��˿ ��5����\n����������2����\n�������㡿10����\n�����ײˡ�1����\n����������5����\n",p);
    strcpy(data,"--------------��ǰ������Ʒ--------------\n");//printf("%s",data);
    fputs(data,p);
    wsprintf(data,"������\t����ʱ��\tԤ�Ƶȴ�ʱ��\t��Ʒ������\n",i,node1->show_time);//printf("%s",data);
    fputs(data,p);
    while(node1!=NULL)
    {
      wsprintf(data,"%d\t%s\t%d����\t\t",i,node1->show_time,node1->wait_time);//printf("%s",data);
      fputs(data,p);
      for(j=0;j<5;j++)
        if(node1->chois[j]!=0)
        {
           wsprintf(data,"%-6s��%d  ",name[j],node1->chois[j]);//printf("%s",data);
           fputs(data,p);
        }
      i++;node1=node1->next;//printf("\n");
      fputs("\n",p);
    }
    strcpy(data,"--------------�ܹ��賴����--------------\n");//printf("%s",data);
    fputs(data,p);
    for(j=0;j<5;j++)
      if(waitDishes[j]!=0)
      {
         wsprintf(data,"��%s����%d��\n",name[j],waitDishes[j]);//printf("%s",data);
         fputs(data,p);
      }
    strcpy(data,"---------------���ȳ���Ʒ---------------\n");//printf("%s",data);
    fputs(data,p);
    for(j=0;j<5;j++)
      if(head->chois[j]!=0)
      {
         wsprintf(data,"��%s���ܹ��賴��%d��\n",name[j],waitDishes[j]>3?3:waitDishes[j]);//printf("%s",data);
         fputs(data,p);
      }
    fclose(p);//Sleep(5000);
    node1=head;
    while(node1!=NULL)
    {
       node2=node1;node1=node1->next;free(node2);
    }
    while(kbhit())getch();
    printf("�ļ������ڱ��ļ����µġ���������.txt���У���������˳�....");getch();
}
/*
1����˿(5����)  2����������2���ӣ�  3�������㣨10���ӣ�  4�����ײˣ�1���ӣ�  5����������5���ӣ�
*/
