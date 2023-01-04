/*
常对象只能调用常成员函数
常成员函数只能调用常成员函数
普通对象和普通成员函数可以调用常函数
*/
//#include <iostream>
//using namespace std;
//
//void main()
//{
//
//	int a[3][3] = { 1,2,3,
//				 4,5,6,
//				 7,8,9 };
//	cout << *(&a[1][1] + 2) << endl;
//	cout << a << endl << a + 1 << endl << *a + 1 << endl;
//	cout << *a << endl << *a + 1 << endl << a[0] << endl;
//	cout << *(&a[0][0] + 2) << endl;
//	cout << *(a + 1)[1] << endl;
//	cout << *(&a[1][1] + 2) << endl;
//	/*cout << *a[1][2] << endl;*/
//}
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//    A() { cout << "A structor is called.\n"; f(); }
//    virtual void f()
//    {
//        cout << "A::f( )is called.\n";
//    }
//    void h() { f(); }
//};
//
//class B : public A
//{
//public:
//    B() { cout << "B structor is called.\n";  f(); }
//    void f() { cout << "B::f( )is called.\n"; }
//    void g() { f(); }
//};
//
//class C : public B
//{
//public:
//    C() { cout << "C structor is called.\n"; f(); }
//    void f() { cout << "C::f( )is called.\n"; }
//};
//void main()
//{
//    C c;
//    c.g();
//    c.h();
//}
#include <iostream>
using namespace std;

class A {
	/*int a;
	const int b;
	static const int c=0;
	static const  int d = 10;
	int& e;
	int f[d];*/
public:
	/*A(int aa, int bb, int& ee) :a(aa), b(bb), e(ee)
	{
		memset(f, 0, 4 * d);
	}*/
	//void plus() { e++; }
	///*void show()
	//{
	//	cout << "a=" << a << endl;
	//	cout << "b=" << b << endl;
	//	cout << "c=" << c << endl;
	//	cout << "d=" << d << endl;
	//	cout << "e=" << e << endl;
	//	cout << "f[3]=" << f[3] << endl;
	//}*/
	//void show()
	//{
	//	cout << hex << &a << endl;
	//	cout << hex << &b << endl;
	//	cout << hex << &c << endl;
	//	cout << hex << &d << endl;
	//	cout << hex << &e << endl;
	//	cout << hex << f << endl;
	//}
};
void main(void)
{
	/*int ee = 111;
	A m_a(1, 2, ee);*/
	/*m_a.show();*/
	/*ee++;*/
	/*m_a.show();
	m_a.plus();
	m_a.show();*/
	cout << sizeof(A) << endl ;
}
