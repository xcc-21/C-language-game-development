#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>

#define window_height 480
#define window_width  640               //窗口大小

IMAGE main_map;
IMAGE character_vice;
IMAGE character;

int map_init_x,map_init_y;
int character_x,character_y;
int character_picture_i,character_picture_j;

char input;

void starup_show()
{
   initgraph(640,480);
   map_init_x=map_init_y=0;                         //地图初始时时截取从（0,0）开始的部分//
   character_x=332;
   character_y=86;
   character_picture_i=0;
   character_picture_j=0;
   loadimage(&main_map,_T("资源文件夹\\总地图.jpg"),640,1088);
   loadimage(&character_vice,_T("资源文件夹\\桌面行走图遮罩图.jpg",197,282));
   loadimage(&character,_T("资源文件夹\\桌面行走图.jpg",197,282));
   BeginBatchDraw();
}

void map_show()
{
   putimage(0,0,window_width,window_height,&main_map,map_init_x,map_init_y);
   putimage(character_x,character_y,65,70,&character_vice,character_picture_i*65,character_picture_j*70,NOTSRCERASE); //每个小人的像素是（65，70）//
   putimage(character_x,character_y,65,70,&character,character_picture_i*65,character_picture_j*70,SRCINVERT);
   FlushBatchDraw();
}


void UpdateWithInput()
{
    if (kbhit())
	{
    input=getch();
	if (character_picture_i==2)
   {
		character_picture_i=-1;
    }
	if (input=='A')
	{
		map_init_x-=10;
		character_picture_j=2;
	}
	if (input=='D')
	{
		map_init_x+=10;
		character_picture_j=1;
	}
	if (input=='S')
	{
		map_init_y+=10;
		character_picture_j=0;
	}
	if (input=='W')
	{
		map_init_y-=10;
		character_picture_j=3;
	}
    character_picture_i++;
	}
}

void main()
{
   starup_show();
   while(1)
   {
    map_show();
    UpdateWithInput();
   }
   EndBatchDraw();
   getch();
}