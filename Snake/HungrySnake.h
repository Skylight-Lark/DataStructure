#pragma once
#include<iostream>
#include<easyx.h>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<string>
#include<graphics.h>
using namespace std;

class food;
class Sprite
{
public:
	Sprite() :Sprite(0, 0, RED) {};
	Sprite(int x, int y) :Sprite(x, y, RED) {};
	Sprite(int x, int y, COLORREF color) :m_x(x), m_y(y), m_color(color) {};
    void draw();
	virtual void move(int dx,int dy);
	bool collision(const food &f);
	bool GameOverSelf(const Sprite& s)const;//撞自身游戏结束
	bool GameOverWall(void)const;//撞墙
protected:
	int m_x;
	int m_y;
	COLORREF m_color;
};

class snake
{
public:
	snake() :dir(VK_RIGHT){};
	void draw();
	void move();
	void Change_Dir(const ExMessage&msg);
	void control();
	void lengthen();
	bool collision(const food& f);
	bool GameOver(void)const;//游戏结束标志
	void SnakeNew(void);//重置设置蛇的状态
private:
	int dir;
	vector<Sprite> node{ {Sprite(320, 240), Sprite(310, 240), Sprite(300, 240)} };
	ExMessage msg = { 0 };
};

class food:public Sprite
{
public:
	food():Sprite(){};
	food(int x, int y) :Sprite(x, y) {};
	food(int x, int y, COLORREF color) :Sprite(x, y, color) {};
	void change();
	void move(int x, int y) override;
};

class GameScene
{
public:
	void Draw_scene();
private:

};


class Ctextbox
{//文本框类，用于制作界面文本框，显示文字信息
private:
	int x, y;//右上坐标
	int w, h;//文本框长宽
	TCHAR* ptr;//文本消息
	COLORREF color;//文本框填充颜色
	COLORREF tcolor;//文字颜色
public:
	Ctextbox(int x1, int y1, int w1, int h1,COLORREF c1,COLORREF c2,TCHAR text[]) {
		x = x1; y = y1; w = w1; h = h1;  color = c1; tcolor = c2; ptr = text;
	}
	void DrawLine(void)const;//画出边框
	void ShowText(void)const;//显示文字
};

class Cshape;
class Ccircle;
class Crectangle;

class CUI
{//界面类，包括欢迎、结束界面
	vector<Ctextbox> textboxs;//文本框数组,使用模板类vector数组
	COLORREF color;//界面底色
public:
	CUI(COLORREF c1) : color(c1) {};
	void AddBox(const Ctextbox& t) {//在界面里添加文本框
		textboxs.push_back(t);
	};
	void DrawUI()const;//画出界面
};


class Cshape {//定义shape虚基类
protected :
	int x, y;//几何形状的基点坐标

	int fillpattern;//图形的填充方式

	COLORREF color;//图形的颜色

public:
	Cshape(int x1, int y1, int f1, COLORREF c1) {
		x = x1; y = y1; fillpattern = f1; color = c1;
	}

	int GetX() const{//获得x值
		return x;
	}

	int GetY() const{//获得y值
		return y;
	}

	void SetXY(int x1, int y1) {//设置xy值
		x = x1; y = y1;
	}

	int GetFill()const {//获得填充模式
		return fillpattern;
	}

	void SetFill(int f1){//设置填充模式
		fillpattern = f1;
	}

	void SetColor(COLORREF c1) {//设置画笔颜色
		color = c1;
	}
	virtual void Draw(void)const=0;//设置纯虚函数，画出形状
};

class Ccircle : public Cshape//画圆
{
protected:
	int radius;//父类基点为圆心坐标，新增圆的半径
public:
	Ccircle(int x1, int y1, int f1, COLORREF c1, int r1) :Cshape(x1, y1, f1, c1), radius(r1) {};
	void SetPoint(int x1, int y1, int r1) { Cshape::SetXY(x1, y1); radius = r1; };//设置圆的参数
	void SetType(int f1, COLORREF c1) { Cshape::SetColor(c1); Cshape::SetFill(f1); };//设置画法模式
	void Draw(void)const;//子类继承的虚函数
};

class Crectangle :public Cshape//画矩形
{
protected:
	int w, h;//父类基点为矩形左上坐标，新增长宽
public:
	Crectangle(int x1, int y1, int f1, COLORREF c1, int w1, int h1) :Cshape(x1, y1, f1, c1), w(w1), h(h1) {};
	void SetPoint(int x1, int y1, int w1, int h1) { Cshape::SetXY(x1, y1); w = w1; h = h1; };//设置矩形参数
	void SetType(int f1, COLORREF c1) { Cshape::SetColor(c1); Cshape::SetFill(f1); };//设置画法模式
	void Draw(void)const;//子类继承的虚函数
};