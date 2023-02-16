#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Problema 1

void problema1() {
	int a = 4, b = 3, c = 12, d = 11;
	int* m = &a;
	int* n = &b;
	int* o = &c;
	int* p = &d;

	*n = *o - *p;
	m = &b;
	*m = a - *m;
	*o = *p - *m;
	o = &a;
	*o = *o - *m;
	*p = *o + c;
	p = &c;
	*p = a - *o;

	cout << a << " " << b << " " << c << " " << d << endl;
	cout << &a << " " << &b << " " << &c << " " << &d << endl;
	cout << m << " " << n << " " << o << " " << p << endl;
	cout << *m << " " << *n << " " << *o << " " << *p << endl;
}

// Problema 2

void problema2() {
	int m = 0, n = 3, b = 7, t = 4;
	int* a = &m;
	int* x = &n;
	int* y = &b;
	int* z = &t;

	*x = b + n;
	x = &b;
	*a = *x + *z;
	*x = m + *z;
	y = &t;
	*y = *a + b;
	z = &n;
	*a = *z + b;
	a = &b;
	*a = *y;

	cout << m << " " << n << " " << b << " " << t << endl;
	cout << &m << " " << &n << " " << &b << " " << &t << endl;
	cout << a << " " << x << " " << y << " " << z << endl;
	cout << *a << " " << *x << " " << *y << " " << *z << endl;
}

// Problema 3

void problema3() {
	int x = 32, y = 16, z = 64, t = 8;
	int* a = &x;
	int* b = &y;
	int* c = &z;
	int* d = &t;

	*d = *a - *c;
	*a = *c - *d;
	a = &t;
	*a = *c + *a;
	*b = t - *a + *c;
	y = *b * *c;
	a = &x;
	c = &y;
	*c = *a - *b;

	cout << x << " " << y << " " << z << " " << t << endl;
	cout << &x << " " << &y << " " << &z << " " << &t << endl;
	cout << a << " " << b << " " << c << " " << d << endl;
	cout << *a << " " << *b << " " << *c << " " << *d << endl;
}

// Problema 4

void problema4() {
	int c = 3, a = 7, b = 4, m = 12, n = 20;
	int* x = &a;
	int* y = &b;
	int* z = &m;
	int* t = &n;

	*y = sqrt(b + c * *t);
	y = &a;
	*y = *z - *y + c;
	*t = *x - m;
	t = &a;
	*t = *t - c + *y;
	x = &n;
	*x = c + *t - *x;
	y = &b;
	*y = *x - c;

	cout << c << " " << a << " " << b << " " << m << " " << n << endl;
	cout << &a << " " << &b << " " << &m << " " << &n << endl;
	cout << x << " " << y << " " << z << " " << t << endl;
	cout << *x << " " << *y << " " << *z << " " << *t << endl;
}

// Problema 5

void problema5() {
	int a = 9, b = 18, c = 27, d = 36;
	int* ai = &a;
	int* bi = &b;
	int* ci = &c;
	int* di = &d;

	*di = b - *ai;
	*bi = (*ai + *ci) * 2;
	*ai = (a + *ci) / 2;
	ai = &c;
	ci = &d;
	*bi = *di - a + *ai;
	*ai = 6 * *bi;
	*ci = *di / 2;
	di = &a;
	*di = *di + c;
	*ai = a + *di;

	cout << a << " " << b << " " << c << " " << d << endl;
	cout << &a << " " << &b << " " << &c << " " << &d << endl;
	cout << ai << " " << bi << " " << ci << " " << di << endl;
	cout << *ai << " " << *bi << " " << *ci << " " << *di << endl;
}

void problema6() {
	int e = 4, f = 8, g = 12, h = 16;
	int* a = &e;
	int* b = &f;
	int* c = &g;
	int* d = &h;
	int r = 2;

	*d = sqrt(*d);
	*a = *b - *d;
	a = &g;
	*a = *b - *c + r * *d;
	d = &e;
	*d = (*b / 8) * r;
	*b = *b + *d;
	*c = r * *b;
	c = &f;
	*c = *a;

	cout << e << " " << f << " " << g << " " << h << endl;
	cout << &e << " " << &f << " " << &g << " " << &h << endl;
	cout << a << " " << b << " " << c << " " << d << endl;
	cout << *a << " " << *b << " " << *c << " " << *d << endl;
}

void problema7() {
	int a = 4, b = 7, c = 27, d = 47;
	int* e = &a;
	int* f = &b;
	int* g = &c;
	int* h = &d;

	*e = a + *g - *h;
	*f = *g - *e;
	g = &a;
	*h = *f + *e;
	e = &c;
	*e = *h + *g;
	*g = *e / 2;
	g = &b;
	*h = *g + c;
	
	cout << a << " " << b << " " << c << " " << d << endl;
	cout << &a << " " << &b << " " << &c << " " << &d << endl;
	cout << e << " " << f << " " << g << " " << h << endl;
	cout << *e << " " << *f << " " << *g << " " << *h << endl;
}

void problema8() {
	int x1 = 62, x2 = 53, x3 = 44, x4 = 35;
	int* y1 = &x1;
	int* y2 = &x2;
	int* y3 = &x3;
	int* y4 = &x4;

	*y3 = x1 + *y2;
	y2 = &x4;
	*y4 = *y2 - *y1 + *y3;
	y3 = &x1;
	*y2 = *y3 * 2 + *y4;
	y2 = &x1;
	*y4 = *y2 - *y3;
	y3 = &x4;
	*y1 = *y3 - *y4;

	cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
	cout << &x1 << " " << &x2 << " " << &x3 << " " << &x4 << endl;
	cout << y1 << " " << y2 << " " << y3 << " " << y4 << endl;
	cout << *y1 << " " << *y2 << " " << *y3 << " " << *y4 << endl;
}

void problema9() {
	int a = 7, b = 5, c = 9, d = 2, e = 3;
	int* x = &a;
	int* y = &b;
	int* z = &c;
	int* t = &d;

	*t = *x - b;
	t = &e;
	*y = *t + *z;
	*x = *z + *y - *t;
	y = &d;
	*y = *x - a * 2;
	y = &a;
	*z = *y - *t;
	*x = *y * 2;
	x = &d;

	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
	cout << &a << " " << &b << " " << &c << " " << &d << " " << &e << endl;
	cout << x << " " << y << " " << z << " " << t << endl;
	cout << *x << " " << *y << " " << *z << " " << *t << endl;
}

void problema10() {
	int m = 4, n = 40, o = 80, p = 400;
	int* a = &m;
	int* b = &n;
	int* c = &o;
	int* d = &p;

	*d = *a + *d - 2 * *c;
	d = &m;
	*b = m + *d - *c;
	*a = *d - *b;
	a = &n;
	*b = n / 2 + *a;
	*c = m / 2 + *d - *b;
	c = &m;
	b = &p;
	*a = *c - *b * 2 + *a;

	cout << m << " " << n << " " << o << " " << p << endl;
	cout << &m << " " << &n << " " << &o << " " << &p << endl;
	cout << a << " " << b << " " << c << " " << d << endl;
	cout << *a << " " << *b << " " << *c << " " << *d << endl;
}






