#include"shead.h"
IMAGE k[9], uk, face, f[2], b[2], t[10];
ele el[12][12];
int allspace = 0;
void loading(){
	loadimage(k, L"./pic/k10.jpg", 16 * MUL, 16 * MUL);
	loadimage(k + 1, L"./pic/k11.jpg", 16 * MUL, 16 * MUL);
	loadimage(k + 2, L"./pic/k12.jpg", 16 * MUL, 16 * MUL);
	loadimage(k + 3, L"./pic/k13.jpg", 16 * MUL, 16 * MUL);
	loadimage(k + 4, L"./pic/k14.jpg", 16 * MUL, 16 * MUL);
	loadimage(k + 5, L"./pic/k15.jpg", 16 * MUL, 16 * MUL);
	loadimage(k + 6, L"./pic/k16.jpg", 16 * MUL, 16 * MUL);
	loadimage(k + 7, L"./pic/k17.jpg", 16 * MUL, 16 * MUL);
	loadimage(k + 8, L"./pic/k18.jpg", 16 * MUL, 16 * MUL);
	loadimage(&uk, L"./pic/k0.jpg", 16 * MUL, 16 * MUL);
	loadimage(&face, L"./pic/face.jpg", 24 * MUL, 24 * MUL);
	loadimage(f, L"./pic/f1.jpg", 16 * MUL, 16 * MUL);
	loadimage(f + 1, L"./pic/f2.jpg", 16 * MUL, 16 * MUL);
	loadimage(b, L"./pic/b0.jpg", 16 * MUL, 16 * MUL);
	loadimage(b + 1, L"./pic/b1.jpg", 16 * MUL, 16 * MUL);
	loadimage(t, L"./pic/m0.jpg", 12 * MUL, 22 * MUL);
	loadimage(t + 1, L"./pic/m1.jpg", 12 * MUL, 22 * MUL);
	loadimage(t + 2, L"./pic/m2.jpg", 12 * MUL, 22 * MUL);
	loadimage(t + 3, L"./pic/m3.jpg", 12 * MUL, 22 * MUL);
	loadimage(t + 4, L"./pic/m4.jpg", 12 * MUL, 22 * MUL);
	loadimage(t + 5, L"./pic/m5.jpg", 12 * MUL, 22 * MUL);
	loadimage(t + 6, L"./pic/m6.jpg", 12 * MUL, 22 * MUL);
	loadimage(t + 7, L"./pic/m7.jpg", 12 * MUL, 22 * MUL);
	loadimage(t + 8, L"./pic/m8.jpg", 12 * MUL, 22 * MUL);
	loadimage(t + 9, L"./pic/m9.jpg", 12 * MUL, 22 * MUL);
}
void time_out(int start){
	clearrectangle(92 * MUL, 0, 160 * MUL, 40 * MUL);
	int x1, x2, x3, x4, x = time(0) - start;
	x1 = x % 10;
	x2 = (x % 60) / 10;
	x3 = (x / 60) % 10;
	x4 = (x / 60) / 10;
	putimage(99 * MUL, 9 * MUL, t + x4);
	putimage(111 * MUL, 9 * MUL, t + x3);
	putimage(129 * MUL, 9 * MUL, t + x2);
	putimage(141 * MUL, 9 * MUL, t + x1);
	setfillcolor(RGB(255, 0, 0));
	solidcircle(126 * MUL, 15 * MUL, 2 * MUL);
	solidcircle(126 * MUL, 25 * MUL, 2 * MUL);
}
//由于数组[x]中的内容要画在x-1格内，所以以下均有x=x-1.y=y-1
//画一个旗子，其中n==0时为普通旗子，==1时为插做了的旗子
void flag(int x, int y, int n) {
	x -= 1, y -= 1;
	putimage((x * 16 + 8) * MUL, (y * 16 + 48) * MUL, f + n);
}
//画一个未被开过的格子
void rec(int x, int y){
	x -= 1, y -= 1;
	putimage((x * 16 + 8) * MUL, (y * 16 + 48) * MUL, &uk);
}
//画一个被开过的格子
void num(int x, int y, int num) {
	x -= 1, y -= 1;
	putimage((x * 16 + 8) * MUL, (y * 16 + 48) * MUL, k + num);
}
//画一个炸弹，其中n==0时为普通炸弹，==1时为踩到的炸弹
void bomb(int x, int y, int n) {
	x -= 1, y -= 1;
	putimage((x * 16 + 8) * MUL, (y * 16 + 48) * MUL, b + n);
}
//作者专属大帅脸
void fc() {
	putimage(68 * MUL, 8 * MUL, &face);
}
void str_out(int x, int y, int dx, int dy, LPCTSTR str, int b) {
	settextcolor(RGB(0, 0, 0));
	settextstyle(b * MUL, 0, L"宋体");
	outtextxy(((dx - x) * MUL - textwidth(str)) / 2, ((dy - y) * MUL - textheight(str)) / 2, str);
}
mouseback get_click(int start) {
	mouseback mb;
	ExMessage msg;
	while (1) {
		time_out(start);
		while (peekmessage(&msg, EX_MOUSE)) {
			if (msg.message == WM_LBUTTONDOWN || msg.message == WM_RBUTTONDOWN) {
				mb.xx = msg.x;
				mb.yy = msg.y;
				if (msg.lbutton && !msg.rbutton) {
					mb.bb = 1;
					return mb;
					break;
				}
				else if (!msg.lbutton && msg.rbutton) {
					mb.bb = 0;
					return mb;
					break;
				}
			}
		}
		Sleep(40);
	}
}
mouseback get_click() {
	mouseback mb;
	ExMessage msg;
	while (1) {
		while (peekmessage(&msg, EX_MOUSE)) {
			if (msg.message == WM_LBUTTONDOWN || msg.message == WM_RBUTTONDOWN) {
				mb.xx = msg.x;
				mb.yy = msg.y;
				if (msg.lbutton && !msg.rbutton) {
					mb.bb = 1;
					return mb;
					break;
				}
				else if (!msg.lbutton && msg.rbutton) {
					mb.bb = 0;
					return mb;
					break;
				}

			}
		}
		Sleep(40);
	}
}
void graph() {
	initgraph(160 * MUL, 200 * MUL);//显示命令窗口
	setbkcolor(RGB(181, 181, 181));//设定颜色
	cleardevice();
	loading();
	fc();
	str_out(0, 0, 68, 24, L"滑稽出品", 10);
}
void refresh() {
	//刷新数值
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			el[i][j].data = 0;
			el[i][j].bomb = 0;
			el[i][j].flag = 0;
			el[i][j].know = 0;
		}
	}
	allspace = 0;
	//创造炸弹
	srand(time(0));
	int x, y;
	for (int i = 0; i < 10; i++) {
		x = 1 + rand() % 9;
		y = 1 + rand() % 9;
		if (el[x][y].bomb) {
			i--;
			continue;
		}
		int j, k;
		for (j = -1; j <= 1; j++) {
			for (k = -1; k <= 1; k++) {
				if (j == 0 && k == 0)el[x + j][y + k].bomb = 1;
				else el[x + j][y + k].data++;
			}
		};
	}
}
void outgraph() {
	clearrectangle(0, 40 * MUL, 160 * MUL, 200 * MUL);
	int x, y;
	for (x = 1; x < 10; x++) {
		for (y = 1; y < 10; y++) {
			if (el[x][y].flag)flag(x, y, 0);
			else if (!el[x][y].know)rec(x, y);
			else if (el[x][y].bomb)bomb(x, y, 0);
			else num(x, y, el[x][y].data);
		}
	}
}
void answer(int dx, int dy) {
	clearrectangle(0, 40 * MUL, 160 * MUL, 200 * MUL);
	int x, y;
	for (x = 1; x < 10; x++) {
		for (y = 1; y < 10; y++) {
			if (el[x][y].flag) {
				if (el[x][y].bomb)flag(x, y, 0);
				else flag(x, y, 1);
			}
			else if (el[x][y].bomb)bomb(x, y, 0);
			else if (!el[x][y].know)rec(x, y);
			else num(x, y, el[x][y].data);
		}
	}
	if (el[dx][dy].bomb)bomb(dx, dy, 1);
	clearrectangle(0, 0, 68 * MUL, 40 * MUL);
	if (allspace >= 71)str_out(0, 0, 68, 40, L"你赢了", 20);
	else str_out(0, 0, 68, 40, L"你输了", 20);
}
void open(int x, int y) {//连锁挖矿
	if (x < 1 || x > 9 || y < 1 || y > 9) return;//检查边界
	if (el[x][y].bomb || el[x][y].know || el[x][y].flag)return;
	else if (el[x][y].data) {
		el[x][y].know = 1;
		allspace++;
	}
	else {
		el[x][y].know = 1;
		allspace++;
		int i, j;
		for (i = -1; i <= 1; i++) {
			for (j = -1; j <= 1; j++) {
				if (i != 0 || j != 0)open(x + i, y + j);
			}
		}
	}
}
mouseback open2(int x, int y) {
	int fg = 0, i, j;
	mouseback abc = { 0,0,0 };
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (el[x + i][y + j].flag)fg++;
		}
	}
	if (fg == el[x][y].data) {
		for (i = -1; i <= 1; i++) {
			for (j = -1; j <= 1; j++) {
				if (i != 0 || j != 0) {
					if (!el[x + i][y + j].flag) {
						if (!el[x + i][y + j].bomb)	open(x + i, y + j);
						else {
							abc.xx = x + i;
							abc.yy = y + j;
							abc.bb = 1;
						}
					}
				}
			}
		}
	}
	return abc;
}
