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
	bool GameOverSelf(const Sprite& s)const;//ײ������Ϸ����
	bool GameOverWall(void)const;//ײǽ
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
	bool GameOver(void)const;//��Ϸ������־
	void SnakeNew(void);//���������ߵ�״̬
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
{//�ı����࣬�������������ı�����ʾ������Ϣ
private:
	int x, y;//��������
	int w, h;//�ı��򳤿�
	TCHAR* ptr;//�ı���Ϣ
	COLORREF color;//�ı��������ɫ
	COLORREF tcolor;//������ɫ
public:
	Ctextbox(int x1, int y1, int w1, int h1,COLORREF c1,COLORREF c2,TCHAR text[]) {
		x = x1; y = y1; w = w1; h = h1;  color = c1; tcolor = c2; ptr = text;
	}
	void DrawLine(void)const;//�����߿�
	void ShowText(void)const;//��ʾ����
};

class Cshape;
class Ccircle;
class Crectangle;

class CUI
{//�����࣬������ӭ����������
	vector<Ctextbox> textboxs;//�ı�������,ʹ��ģ����vector����
	COLORREF color;//�����ɫ
public:
	CUI(COLORREF c1) : color(c1) {};
	void AddBox(const Ctextbox& t) {//�ڽ���������ı���
		textboxs.push_back(t);
	};
	void DrawUI()const;//��������
};


class Cshape {//����shape�����
protected :
	int x, y;//������״�Ļ�������

	int fillpattern;//ͼ�ε���䷽ʽ

	COLORREF color;//ͼ�ε���ɫ

public:
	Cshape(int x1, int y1, int f1, COLORREF c1) {
		x = x1; y = y1; fillpattern = f1; color = c1;
	}

	int GetX() const{//���xֵ
		return x;
	}

	int GetY() const{//���yֵ
		return y;
	}

	void SetXY(int x1, int y1) {//����xyֵ
		x = x1; y = y1;
	}

	int GetFill()const {//������ģʽ
		return fillpattern;
	}

	void SetFill(int f1){//�������ģʽ
		fillpattern = f1;
	}

	void SetColor(COLORREF c1) {//���û�����ɫ
		color = c1;
	}
	virtual void Draw(void)const=0;//���ô��麯����������״
};

class Ccircle : public Cshape//��Բ
{
protected:
	int radius;//�������ΪԲ�����꣬����Բ�İ뾶
public:
	Ccircle(int x1, int y1, int f1, COLORREF c1, int r1) :Cshape(x1, y1, f1, c1), radius(r1) {};
	void SetPoint(int x1, int y1, int r1) { Cshape::SetXY(x1, y1); radius = r1; };//����Բ�Ĳ���
	void SetType(int f1, COLORREF c1) { Cshape::SetColor(c1); Cshape::SetFill(f1); };//���û���ģʽ
	void Draw(void)const;//����̳е��麯��
};

class Crectangle :public Cshape//������
{
protected:
	int w, h;//�������Ϊ�����������꣬��������
public:
	Crectangle(int x1, int y1, int f1, COLORREF c1, int w1, int h1) :Cshape(x1, y1, f1, c1), w(w1), h(h1) {};
	void SetPoint(int x1, int y1, int w1, int h1) { Cshape::SetXY(x1, y1); w = w1; h = h1; };//���þ��β���
	void SetType(int f1, COLORREF c1) { Cshape::SetColor(c1); Cshape::SetFill(f1); };//���û���ģʽ
	void Draw(void)const;//����̳е��麯��
};