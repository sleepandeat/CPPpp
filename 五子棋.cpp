#include<windows.h>
#include<stdio.h>
HANDLE hInput;  /*  ��ȡ��׼�����豸��� */
INPUT_RECORD inRec;/*  �������ݼ�¼ */
DWORD numRead; /*  �����Ѷ�ȡ�ļ�¼�� */
int Y,X;/* X��Y������ */
int data[60][22];
HWND hwnd;
int input()
{
	while(1){
			COORD pos = {0,0};
			ReadConsoleInput(hInput, &inRec, 1, &numRead);
			pos = inRec.Event.MouseEvent.dwMousePosition;
			Y=(int)pos.Y;
			X=(int)pos.X;
	       if(X!=0&&Y!=0&&X<60&&Y<22&&X%4==0&&Y%2==0)
	       {
    			if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwEventFlags  == RIGHTMOST_BUTTON_PRESSED)  /* ������˫�� */
    						return 1;
    			else if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) /* ����Ҽ����� */
    						return 2;
    			else if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* ���������� */
        					return 3;
			} 
          }
} 
void HideCursor()//���ؿ���̨�Ĺ�� 
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)
{
     COORD coord;
	 coord.X = x,coord.Y=y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void chushihua()
{
     int i,j;
     for(i=0;i<=22;i++)
     {
        for(j=0;j<=30;j++)
           if(j==0)
             if(i==0)printf("�X");
             else if(i==22)printf("�^");
             else if(i%2==0)printf("�d");
             else printf("�U");
           else if(j==30)
             if(i==0)printf("�[");
             else if(i==22)printf("�a");
             else if(i%2==0)printf("�g");
             else printf("�U");
           else if(i==0)
             if(j%2==0)printf("�j");
             else printf("�T");
           else if(i==22)
             if(j%2==0)printf("�m");
             else printf("�T");
           else if(i%2==0&&j%2==0)printf("�p");
           else if(i%2==0)printf("�T");
           else if(j%2==0)printf("�U");
           else printf("  ");
        printf("\n");
     }
     gotoxy(64,2);printf("����������");
     gotoxy(65,4);printf("���������");
     gotoxy(65,6);printf("�Ҽ�������");
     gotoxy(65,8);printf(" ��������");
     gotoxy(65,10);printf("�޻�ʤ�ж�");
} 
int main()
{ 
	int rt;
	BOOL black=TRUE; 
	HideCursor(); //���ؿ���̨�Ĺ�� 
	chushihua();memset(data,0,sizeof(data));
	hwnd=FindWindow("ConsoleWindowClass",NULL);/*  ����̨���ھ�� */
	hInput = GetStdHandle(STD_INPUT_HANDLE); /*  �����豸��� */
    while(1)
    {					
		ReadConsoleInput(hInput, &inRec, 1, &numRead); /* ��ȡ1�������¼� */
		switch(inRec.EventType)
		{
			case MOUSE_EVENT:
                 {
					rt=input();
					switch(rt)
                    {
				       case 2://�Ҽ�����
				            if(black)
                            {
                                 if(data[Y][X]==0)data[Y][X]=1;
                                 else {MessageBox(hwnd,"�����ظ�����һ��λ��","����",MB_ICONERROR);continue;} 
                                 gotoxy(X,Y);printf("��");black=!black;
                            }
				            else MessageBox(hwnd,"�ð�����","����",MB_ICONERROR);
                            break;
                       case 3://������� 
                            //gotoxy(62,2);printf("%d %d",X,Y);
				            if(!black)
                            {
                                if(data[Y][X]==0)data[Y][X]=1;
                                else {MessageBox(hwnd,"�����ظ�����һ��λ��","����",MB_ICONERROR);continue;} 
                                gotoxy(X,Y);printf("��");black=!black;
                            }
				            else MessageBox(hwnd,"�ú�����","����",MB_ICONERROR);
                            break;
                    }
                  }
                  break;
         }
     }
} 
