#pragma once
#include<iostream>
#include<easyx.h>
#include<cstdlib>
#include<vector>
using namespace std;

class Sprite
{
public:
	Sprite() :Sprite(0, 0, RED) {};
	Sprite(int x, int y) :Sprite(x, y, RED) {};
	Sprite(int x, int y, COLORREF color) :m_x(x), m_y(y), m_color(color) {};
	virtual void draw()
	{
		setfillcolor(m_color);
		fillrectangle(m_x, m_y, m_x + 10, m_y + 10);
	}

	void move(int dx,int dy) 
	{
		this->m_x += dx;
		this->m_y += dy;
	}

protected:
	int m_x;
	int m_y;
	COLORREF m_color;
};


class snake: public Sprite
{
public:
	snake() :Sprite(0, 0, RED), dir(VK_RIGHT){};
	snake(int x, int y) :Sprite(x, y, RED), dir(VK_RIGHT) {};
	snake(int x, int y, COLORREF color) :Sprite(x, y, color), dir(VK_RIGHT) {};


	void Get_Keyboard(const ExMessage& mes)
	{
		if (mes.message == WM_KEYDOWN)
		{
			dir = mes.vkcode;
			cout << dir << endl;
		}
	}

	void Move_Body()
	{
		for ( int i = node.size()-1; i>0; i--)
		{
			node[i] = node[i - 1];
		}
		switch(dir)
		{
		case VK_UP:
			node[0].move(0,-10);
			break;
		case VK_DOWN:
			node[0].move(0, 10);
			break;
		case VK_RIGHT:
			node[0].move(10, 0);
			break;
		case VK_LEFT:
			node[0].move(-10, 0);
			break;
		default:
			break;
		}
	}

private:
	int dir;
};


class GameScene
{
public:
	GameScene()
	{
		node.push_back(snake(20, 0));
		node.push_back(snake(10, 0));
		node.push_back(snake(0, 0));
	}
	void Draw_Snake()
	{
		for (auto v1 = node.begin(); v1 != node.end(); v1++)
		{
			(*v1).draw();
		}
	}
	void Game_Run()
	{
		BeginBatchDraw();
		cleardevice();
		Draw_Snake();
		EndBatchDraw();
		while (peekmessage(&mes,EX_KEY))
		{
			player.Get_Keyboard(mes);
		}
		player.Move_Body();
	}

private:
	vector<Sprite> node;
	ExMessage mes = { 0 };
};
