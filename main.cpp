#include <iostream>
#include <iomanip>
#include "testlevel.h"
#include "Point.h"
#if test_level > 0
#include "RGBColor.h"
#endif
#if test_level > 1
#include "ColorBox.h"
#endif
#if test_level > 2
#include "TextBox.h"
#endif
#if test_level > 3
#include "Switch.h"
#endif
#include "WinAdapt.h"

using namespace std;

/* Diese Makrodefinition beinhaltet einen kleinen Codegenerator. Das Makro wird
 * mit zwei Parametern aufgerufen, nämlich der Bedingung, welche getestet werden soll, und
 * dem Text, der zur Erläuterung ausgegeben werden soll. Daraus wird dann je nach
 * Testergebnis eine Meldung ausgegeben und ggf. das Programm abgebrochen.
 */
#define test(cond, description) {cout <<"   " << setw(50) << left << description;\
    if(cond) {cout << " OK"<<endl;} else {cout << " FAILED"<<endl;abort();}}


#if test_level == 2
ColorBox f(Point(100, 100), Point(300, 200), RGBColor(100, 220, 100));
#endif

#if test_level == 3
TextBox t(Point(100, 100), Point(100, 30), "Hello World!");
#endif

#if test_level > 3
Switch s(Point(100, 100), "On", "Off");
#endif

#if test_level == 5
#define NUM_SWITCHES 10
Switch sArray[NUM_SWITCHES];
#endif

void VtlZyk(void)
{
}

void VtlMouse(int X, int Y)
{
#if test_level == 4
    s.onMouse(Point(X, Y));
#endif
#if test_level == 5
    Point m(X, Y);
    for (int i=0;i<NUM_SWITCHES;i++) {
	sArray[i].onMouse(m);
    }
#endif
}

void VtlKeyHit(int key)
{
}

void VtlInit(void)
{
    cout << "test_level: " << test_level << endl;

    {
	cout << "** Teste Klasse Punkt **" << endl;

	Point P1(10, 20);
	test( ((P1.X == 10) && (P1.Y == 20)), "Konstruktor von Punkt");
	Point P2(P1);
	test( ((P2.X == 10) && (P2.Y == 20)), "Kopie von Punkt");
	Point P(0, 0);
	P = P1;
	test( ((P.X == P1.X) && (P.Y == P1.Y)), "operator =");
	Point c(20, 20), cc(20, 20),
	      u(20, 19), lu(19, 19), l(19, 20), ld(19, 21),
	      d(20, 21), rd(21, 21), r(21, 20), ru(21, 19);
	test( (c==c) && (c==cc) && !(c==u) && !(c==r) && !(c==rd), "operator ==");
	test( !(c!=c) && !(c!=cc) && (c!=u) && (c!=r) && (c!=rd), "operator !=");
	test( (!(u<c) && (lu<c) && !(l<c) && !(ld<c)
		    && !(d<c) && !(rd<c) && !(r<c) && !(ru<c) ), "operator <");
	test( (!(u>c) && !(lu>c) && !(l>c) && !(ld>c)
		    && !(d>c) && (rd>c) && !(r>c) && !(ru>c) ), "operator >");
	test( (Point(5, 50) + Point(10, 200) == Point(15, 250)), "operator +");
	P = Point(5, 50);
	test( ((P += Point(10, 200)) == Point(15, 250) && P == Point(15, 250) ), "operator +=");
	test( (Point(15, 250) - Point(10, 200) == Point(5, 50)), "operator -");
	P = Point(15, 250);
	test( ((P -= Point(10, 200)) == Point(5, 50) && P == Point(5, 50) ), "operator -=");
	test( (Point(5, 7) * 2 == Point(10, 14)), "operator *");
	P = Point(5, 7);
	test( ((P *= 2) == Point(10, 14) && P == Point(10, 14)), "operator *=");
	P = Point(25, 17);
	test( ((P /= 2) == Point(12, 8) && P == Point(12, 8)), "operator /=");
	test( (Point(25, 17) / 2 == Point(12, 8)), "operator /");
    }

#if test_level > 0
    {
	cout << "** Teste Klasse Farbe **" << endl;

	RGBColor f( 3, 22, 111);
	test( (f.R==3) && (f.G==22) && (f.B==111), "Konstruktor von Farbe");
	test( f == RGBColor(3, 22, 111), "operator ==");
    }
#endif

#if test_level > 1
    {
	cout << "** Teste Klasse FarbRect **" << endl;

	Point Pos(100, 100), Size(300, 200);
	RGBColor C(50, 100, 200);
	ColorBox f(Pos, Size, C); // test Konstruktor
	ColorBox ff(f); // test Kopie
	test( (f.getPosition()==Pos), "FarbRect::getPos()");
	test( (f.getSize()==Size), "FarbRect::getSize()");
	test( (f.getColor()==C), "FarbRect::getFarbe()");
	Point newPos(150, 150), newSize(350, 250);
	RGBColor newC(3, 22, 111);
	f.setPosition(newPos);
	test( (f.getPosition()==newPos), "FarbRect::setPos()");
	f.setSize(newSize);
	test( (f.getSize()==newSize), "FarbRect::setSize()");
	f.setColor(newC);
	test( (f.getColor()==newC), "FarbRect::setFarbe()");
    }
#endif

#if test_level == 5
    Point p(s.getPosition()), d(10, 50);
    for (int i=0;i<NUM_SWITCHES;i++) {
	sArray[i]=s;
	sArray[i].setPosition(p + d*i);
    }
#endif
}

void VtlPaint(int xl, int yo, int xr, int yu)
{
#if test_level == 2
    f.show();
#endif

#if test_level == 3
    t.show();
#endif

#if test_level == 4
    s.show();
#endif
#if test_level == 5
    for (int i=0;i<NUM_SWITCHES;i++) {
	sArray[i].show();
    }
#endif
}

