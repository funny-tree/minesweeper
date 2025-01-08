#include"shead.h"
using namespace std;
int main() {
	int x, y, start , end ;
	mouseback mb;
	graph();//创造画布
	refresh();//创造炸弹
	while (1) {
		start = time(0);
		while (allspace < 71) {
			time_out(start);
			while (1) {
				outgraph();
				mb = get_click(start);
				if (mb.xx >= 8 * MUL && mb.xx <= 152 * MUL && mb.yy >= 48 * MUL && mb.yy <= 192 * MUL) {
					break;
				}
				else if (mb.xx >= 68 * MUL && mb.xx <= 92 * MUL && mb.yy >= 8 * MUL && mb.yy <= 32 * MUL) {
					refresh();
					start = time(0);
					continue;
				}
			}
			//以上是接受一个点击，以下是根据点击进行操作
			x = ((mb.xx - 8 * MUL) / 16 / MUL) + 1;
			y = ((mb.yy - 48 * MUL) / 16 / MUL) + 1;
			if (mb.bb) {
				if (!el[x][y].flag)
				{
					if (el[x][y].bomb)break;
					else open(x, y);
				}
			}
			else {
				if (el[x][y].flag)el[x][y].flag = 0;
				else if (!el[x][y].know)el[x][y].flag = 1;
				else {
					mouseback abc;
					abc = open2(x, y);
					if (abc.bb) {
						x = abc.xx;
						y = abc.yy;
						break;
					}
				}
			}
		}
		answer(x, y);//输出答案与结果
		while (1) {//重新开始
			mb = get_click();
			if (mb.xx >= 68 * MUL && mb.xx <= 92 * MUL && mb.yy >= 8 * MUL && mb.yy <= 32 * MUL) {
				refresh();
				clearrectangle(0, 0, 68 * MUL, 40 * MUL);
				fc();
				str_out(0, 0, 68, 24, L"滑稽出品", 10);
				break;
			}
		}
	}
}
