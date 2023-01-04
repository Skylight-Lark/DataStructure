#include"HungrySnake.h"

int main()
{
	int ui = 1;
	ExMessage m;
	initgraph(640, 480);
	TCHAR pt1[] = _T("贪吃蛇");//创建文本框
	TCHAR pt2[] = _T("开始游戏");//创建文本框
	TCHAR pt3[] = _T("结束游戏");//创建文本框
	TCHAR pt4[] = _T("游戏结束");//创建文本框
	TCHAR pt5[] = _T("继续游戏");//创建文本框
	TCHAR pt6[] = _T("结束游戏");//创建文本框
	Ctextbox t1(200, 35, 225, 90, BLACK, LIGHTGRAY,pt1);
	Ctextbox t2(215,200,195,60,LIGHTGRAY,WHITE,pt2);
	Ctextbox t3(215, 320, 195, 60, LIGHTGRAY, WHITE, pt3);
	Ctextbox t4(155, 35, 305, 90, BLACK, RED, pt4);
	Ctextbox t5(215, 200, 195, 60, LIGHTGRAY, WHITE, pt5);
	Ctextbox t6(215, 320, 195, 60, LIGHTGRAY, WHITE, pt6);
	CUI begin(BLACK);//创建界面
	CUI end(BLACK);//创建界面
	begin.AddBox(t1);
	begin.AddBox(t2);
	begin.AddBox(t3);
	end.AddBox(t4);
	end.AddBox(t5);
	end.AddBox(t6);

	GameScene scene;
	snake player;
	food f(80, 80, WHITE);

	while (true)
	{
		if (ui == 1) {
			BeginBatchDraw();
			cleardevice();
			begin.DrawUI();
			EndBatchDraw();
			m = getmessage(EX_MOUSE);
			if (m.x >= 215 && m.x <= 215 + 195 &&
				m.y >= 200 && m.y <= 200 + 60 && m.lbutton == 1) {
				ui = 2;
				continue;
			}
			if (m.x >= 215 && m.x <= 215 + 195 &&
				m.y >= 320 && m.y <= 320 + 60 && m.lbutton == 1) {
				return 0;
			}
			Sleep(45);
		}
		else if (ui == 2) {
			player.control();
			BeginBatchDraw();
			cleardevice();
			scene.Draw_scene();
			player.draw();
			f.draw();
			
			EndBatchDraw();
			
			Sleep(45);
			if (player.collision(f))//蛇的状态改变标志
			{
				f.change();//蛇的方向改变
				player.lengthen();//蛇的长度改变
			}
			if (player.GameOver()) {//游戏结束标志
				ui = 3;
				Sleep(500);
				continue;
			}
		}
		else if (ui == 3) {
			BeginBatchDraw();
			cleardevice();
			end.DrawUI();
			EndBatchDraw();
			m = getmessage(EX_MOUSE);
			if (m.x >= 215 && m.x <= 215 + 195 &&
				m.y >= 200 && m.y <= 200 + 60 && m.lbutton == 1) {
				ui = 2;
				continue;
			}
			if (m.x >= 215 && m.x <= 215 + 195 &&
				m.y >= 320 && m.y <= 320 + 60 && m.lbutton == 1) {
				return 0;
			}
			Sleep(45);
		}
	}
	getchar();
}