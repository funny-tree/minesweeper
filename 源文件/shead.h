#ifndef SHEADH
#define SHEADH

#include<graphics.h>
#include<windows.h>
#include<iostream>
using namespace std;
#define MUL 1.5   //������ͼ��С
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

//��ʼ����ͼ
void graph();
//���µ�ǰ��Ϸģ��
void outgraph();
//���µ�ǰʱ��ģ��
void time_out(int start); 
//��Ϸ�����������Ϸ����ʹ�
void answer(int dx, int dy);
//���ߴ�˧��
void fc();
//���һ������str�������ڽ�����ֱ�Ϊx,y,dx,dy�ľ��Σ������СΪb
void str_out(int x, int y, int dx, int dy, LPCTSTR str, int b);

//����һ���������start�Ļ�ˢ��ʱ�䣬û�еĲ��᣻
mouseback get_click(int start);
mouseback get_click();
//ˢ������
void refresh();

//����򿪸���
void open(int x, int y);
//�Ҽ��򿪸���
mouseback open2(int x, int y);
#endif 