#ifndef SHEADH
#define SHEADH

#include<graphics.h>
#include<windows.h>
#include<iostream>
using namespace std;
#define MUL 1.5   //调整绘图大小
struct mouseback {
	int xx, yy;
	bool bb;
};
struct ele {
	int data;
	bool know, bomb, flag;
};

extern int allspace;
extern ele el[12][12];

//初始化制图
void graph();
//更新当前游戏模块
void outgraph();
//更新当前时间模块
void time_out(int start); 
//游戏结束，输出游戏结果和答案
void answer(int dx, int dy);
//作者大帅脸
void fc();
//输出一段文字str，居中于角坐标分别为x,y,dx,dy的矩形，字体大小为b
void str_out(int x, int y, int dx, int dy, LPCTSTR str, int b);

//接受一个点击，有start的会刷新时间，没有的不会；
mouseback get_click(int start);
mouseback get_click();
//刷新数据
void refresh();

//左键打开格子
void open(int x, int y);
//右键打开格子
mouseback open2(int x, int y);
#endif 