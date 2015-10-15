#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#define LEFTPRESS 0xff01
#define LEFTCLICK 0xff10 
#define LEFTDRAG 0xff19 
#define MOUSEMOVE 0xff08 
int num[10][10];/*��Χ*/ 
int p[10][10];/*ͳ���׵�����*/ 
int loop;/*�������ı�־*/ 
int again=0;/*�Ƿ������ı���*/ 
int scorenum;/*һ��ʼͳ���м�����*/ 
char score[3];/*���һ���м�������*/ 
int Keystate; 
int MouseExist; 
int MouseButton; 
int MouseX; 
int MouseY; 
/*�������״����*/ 
typedef struct 
  { 
   unsigned int shape[32]; 
   char hotx; 
   char hoty; 
  }SHAPE; 

/*��ͷ��*/ 
SHAPE ARROW={ 
      { 
       0x3fff,0x1fff,0x0fff,0x07ff, 
       0x03ff,0x01ff,0x00ff,0x007f, 
       0x003f,0x00ff,0x01ff,0x10ff, 
       0x30ff,0xf87f,0xf87f,0xfc3f, 
       0x0000,0x7c00,0x6000,0x7000, 
       0x7800,0x7c00,0x7e00,0x7f00, 
       0x7f80,0x7e00,0x7c00,0x4600, 
       0x0600,0x0300,0x0300,0x0180 
      }, 
      0,0, 
     }; 

/*�������ʾ*/ 
void MouseOn() 
  { 
   _AX=0x01; 
   geninterrupt(0x33); 
  } 

/*�������ʾ*/ 
void MouseOff()/*���������*/ 
  { 
   _AX=0x02; 
   geninterrupt(0x33); 
  } 
void MouseSetXY(int x,int y)/*���õ�ǰλ��*/ 
  { 
   _CX=x; 
   _DX=y; 
   _AX=0x04; 
   geninterrupt(0x33); 
  } 
int LeftPress()/*�������*/ 
  { 
   _AX=0x03; 
   geninterrupt(0x33); 
   return(_BX&1); 
  } 
void MouseGetXY()/*�õ���ǰλ��*/ 
  { 
   _AX=0x03; 
   geninterrupt(0x33); 
   MouseX=_CX; 
   MouseY=_DX; 
  } 
 begain()/*��Ϸ��ʼ����*/ 
{ 
 int i,j; 
 loop: cleardevice(); 
 MouseOn(); 
 MouseSetXY(180,30); 
 MouseX=180; 
 MouseY=30; 
 scorenum=0; 
 setfillstyle(SOLID_FILL,7); 
 bar(190,60,390,290); 
 setfillstyle(SOLID_FILL,8); 
 for(i=100;i<300;i+=20)/*������*/ 
  for(j=200;j<400;j+=20) 
   bar(j-8,i+8,j+8,i-8); 
 setcolor(7); 
 setfillstyle(SOLID_FILL,YELLOW);/*����*/ 
 fillellipse(290,75,10,10); 
 setcolor(YELLOW); 
 setfillstyle(SOLID_FILL,0); 
  fillellipse(285,75,2,2); 
  fillellipse(295,75,2,2); 
 setcolor(0); 
  bar(287,80,293,81); 
 randomize(); 
 for(i=0;i<10;i++) 
  for(j=0;j<10;j++) 
   { 
   num[i][j]=random(7)+10;/*��10������������*/ 
   if(num[i][j]==10) 
    scorenum++; 
   } 
 sprintf(score,"%d",scorenum);
 setcolor(1); 
 settextstyle(0,0,2); 
 outtextxy(210,70,score); 
 scorenum=100-scorenum;/*Ϊ�˺����ж�ʤ��*/
 return 0;
}
gameove()/*��Ϸ��������*/ 
{ 
 int i,j; 
 setcolor(0); 
 for(i=0;i<10;i++) 
  for(j=0;j<10;j++) 
   if(num[i][j]==10)/*�ǵ��׵ľ���ʾ����*/ 
    { 
     setfillstyle(SOLID_FILL,RED); 
      bar(200+j*20-8,100+i*20-8,200+j*20+8,100+i*20+8); 
      setfillstyle(SOLID_FILL,0); 
      fillellipse(200+j*20,100+i*20,7,7); 
    }
    return 0;
}
int tongji(int i,int j)/*�����м�����*/ 
{ 
 int x=0;/*10��������*/ 
 if(i==0&&j==0) 
  { 
  if(num[0][1]==10) 
  x++; 
  if(num[1][0]==10) 
  x++; 
  if(num[1][1]==10) 
  x++; 
  } 
 else if(i==0&&j==9) 
 { 
  if(num[0][8]==10) 
  x++; 
  if(num[1][9]==10) 
  x++; 
  if(num[1][8]==10)  
  x++; 
 } 
 else if(i==9&&j==0) 
 { 
  if(num[8][0]==10) 
  x++; 
  if(num[9][1]==10)
  x++;
  if(num[8][1]==10)
  x++;
 }
 else if(i==9&&j==9)
 {
  if(num[9][8]==10)
  x++;
  if(num[8][9]==10)
  x++;
 }
}
