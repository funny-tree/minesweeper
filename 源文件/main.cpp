#include"shead.h"
using namespace std;
int main() {
	int x, y, start , end ;
	mouseback mb;
	graph();//���컭��
	refresh();//����ը��
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
			//�����ǽ���һ������������Ǹ��ݵ�����в���
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
		answer(x, y);//���������
		while (1) {//���¿�ʼ
			mb = get_click();
			if (mb.xx >= 68 * MUL && mb.xx <= 92 * MUL && mb.yy >= 8 * MUL && mb.yy <= 32 * MUL) {
				refresh();
				clearrectangle(0, 0, 68 * MUL, 40 * MUL);
				fc();
				str_out(0, 0, 68, 24, L"������Ʒ", 10);
				break;
			}
		}
	}
}
