#include"HungrySnake.h"
void Sprite::draw()
{
	setfillcolor(m_color);
	fillrectangle(m_x, m_y,m_x+10,m_y+10);
}

void Sprite::move(int dx,int dy)
{
	m_x += dx;
	m_y += dy;
}

void snake::draw()
{
	for (auto v1=node.begin();v1!=node.end();v1++)
	{
		(*v1).draw();
	}
}

void snake::SnakeNew()
{//�����ߵ�״̬
	node = { {Sprite(320, 240), Sprite(310, 240), Sprite(300, 240)} };
	dir = VK_RIGHT;
	msg = { 0 };
}

void snake::move()
{
	for (int i = node.size()-1; i >0; i--)
	{
		node[i] = node[i-1];
	}
	switch (dir)
	{
	case VK_UP:
		node[0].move(0, -10);
		break;

	case VK_DOWN:
		node[0].move(0, 10);
		break;

	case VK_RIGHT:
		node[0].move(10,0);
		break;

	case VK_LEFT:
		node[0].move(-10,0);
		break;
	default:
		break;
	}
	
		
}

void snake::Change_Dir(const ExMessage&msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case VK_UP:
			if (dir != VK_DOWN)
				dir = msg.vkcode;
			break;

		case VK_DOWN:
			if (dir != VK_UP)
				dir = msg.vkcode;
			break;

		case VK_RIGHT:
			if (dir != VK_LEFT)
				dir = msg.vkcode;
			break;

		case VK_LEFT:
			if (dir != VK_RIGHT)
				dir = msg.vkcode;
			break;
		default:
			break;
		}
	}
}

void snake::control()
{
	while (peekmessage(&msg,EX_KEY))
	{
		Change_Dir(msg);
	}
	move();
}

void snake::lengthen()
{
	node.push_back(Sprite());
}

bool snake::collision(const food& f)
{
	return node[0].collision(f);
}

bool snake::GameOver(void)const
{//��Ϸ������־
	int tag = 0;
	if (node[0].GameOverWall())
	{
		tag = 1;//ײ��ǽ����
	}
	for (auto s = node.begin() + 1; s != node.end(); s++) {
		if (node[0].GameOverSelf(*s) == 1) {//ײ��������
			tag = 1;
			break;
		}
	}
	return tag;
}

bool Sprite::collision(const food &f)
{
	return f.m_x == this->m_x && f.m_y == this->m_y;
}

bool Sprite::GameOverSelf(const Sprite& s)const
{//��Ϸ������־
	int tag = 0;
	if (m_x == s.m_x && m_y == s.m_y)
	{
		tag = 1;//��������ĳ�������غ�ʱtagΪ1
	}
	return tag;
}

bool Sprite::GameOverWall(void)const
{
	int tag = 0;
	if ((m_y == 10 && m_x >= 10 && m_x <= 620) ||
		(m_x == 620 && m_y >= 10 && m_y <= 460) ||
		(m_y == 460 && m_x >= 10 && m_x <= 620) ||
		(m_x == 10 && m_y >= 10 && m_y <= 460))

	{
		tag = 1;//ײǽʱtagΪ1
	}
	return tag;
}

void food::move(int x, int y)
{
	m_x = x;
	m_y = y;
}

void food::change()
{
	srand((unsigned)time(NULL));
	int x, y;
	do
	{
	   x = rand() % 64 * 10;
       y = rand() % 48 * 10;
	} while(x>=600||x<=30||y>=450||y<=30);
	
	move(x, y);
}

void GameScene::Draw_scene()
{
	for (int i = 0; i < 64; i++)
	{
		setfillcolor(LIGHTGRAY);
		fillrectangle(i * 20, 0, i * 20 + 18, 10);
		fillrectangle(i * 20, 470, i * 20 + 18, 480);
	}

	for (int i = 0; i < 48; i++)
	{
		setfillcolor(LIGHTGRAY);
		fillrectangle(0, 20 * i+10, 10, 20 * i + 28);
		fillrectangle(630, 20 * i + 10, 640, 20 * i + 28);
	}
}

void Ctextbox::DrawLine(void)const//�����߿�
{
	setfillcolor(color);// ���������ɫ
	setfillstyle(BS_SOLID);//�������ģʽ
	solidrectangle(x, y, x + w, y + h);//������
}

void Ctextbox::ShowText(void)const//��ʾ����
{
	settextcolor(tcolor);//������ɫ
	settextstyle(h-10, 0, _T("Consolas"));//��������
	outtextxy(x+5, y+5, ptr);//�����ʾ����
}

void CUI::DrawUI()const//������������
{
	Crectangle rec(0, 0, 0, BLACK, 640, 480);
	rec.Draw();
	for (int i = 0; i < 64; i++)
	{
		setfillcolor(LIGHTGRAY);
		fillrectangle(i * 20, 0, i * 20 + 18, 10);
		fillrectangle(i * 20, 470, i * 20 + 18, 480);
	}
	for (int i = 0; i < 48; i++)
	{
		setfillcolor(LIGHTGRAY);
		fillrectangle(0, 20 * i + 10, 10, 20 * i + 28);
		fillrectangle(630, 20 * i + 10, 640, 20 * i + 28);
	}
	
	for (auto t1 = textboxs.begin(); t1 != textboxs.end(); t1++)
	{
		(*t1).DrawLine();
		(*t1).ShowText();
	}
}

void Ccircle::Draw(void)const
{//����Բ��ͼ��
	setfillstyle(fillpattern);
	setfillcolor(color);
	solidcircle(x, y, radius);
}

void Crectangle::Draw(void)const
{//��������ͼ��
	setfillstyle(fillpattern);
	setfillcolor(color);
	solidrectangle(x, y, x + w, y + h);
}