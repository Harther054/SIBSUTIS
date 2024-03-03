#include <stdlib.h>
#include <graphics.h>
int main()
{
 initwindow(640,360); // открыть графическое окно 640 на 360 пикселей 
 moveto(0,0);         // курсор в точку (0,0)
 lineto(320,180);       // отрезок в точку (320,180)
 setcolor(GREEN);         //цвет линий зелёный
 circle (320,180,50);  // рисуем окружность
 setcolor(COLOR(255,0,255)); //смешиваем цвета с помощью функции  
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
 closegraph();        // закрываем графическое окно
 return 0;
}

