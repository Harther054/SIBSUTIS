#include <stdlib.h>
#include <graphics.h>
int main()
{
 initwindow(640,360); // ������� ����������� ���� 640 �� 360 �������� 
 moveto(0,0);         // ������ � ����� (0,0)
 lineto(320,180);       // ������� � ����� (320,180)
 setcolor(GREEN);         //���� ����� ������
 circle (320,180,50);  // ������ ����������
 setcolor(COLOR(255,0,255)); //��������� ����� � ������� �������  
                                                     //COLOR                         
 moveto(640,360);
 lineto(320,180);
 setcolor(10);
 moveto(0,360);
 lineto(320,180);
 setcolor(COLOR(255,200,100));
 moveto(640,0);
 lineto(320,180);
 getch();            
 closegraph();        // ��������� ����������� ����
 return 0;
}

