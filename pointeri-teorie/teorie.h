#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void size() {
	cout << sizeof(int) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(string) << endl;
}

void operatori() {
	int x = 7;
	cout << &x << endl; // & = adresa
	cout << *(&x) << endl; // * = dereferentiere : OBS! Trebuie sa fie utilizat langa adresa.
}

void pointeri() {
	int t = 101;
	int* p = &t;
	cout << "t : " << t << endl;
	cout << "&t : " << &t << endl;
	cout << "p : " << p << endl;
	cout << "*p : " << *p << endl;
	cout << "Daca *p = 29 atunci" << endl;
	*p = 29;
	cout << "t : " << t << endl;
}

void exercitiuPointeri1() {
	int a = 7, b = 12, c = 15;
	int* p = &a;
	int* t = &b;
	int* m = &c;
	*p = *t + b;
	p = &b;
	*p = 19;
	m = &a;
	*m = 21;
	*m = *t + *p;

	cout << a << " " << b << " " << c << endl;
	cout << p << " " << t << " " << m << endl;
	cout << &a << " " << &b << " " << &c << endl;
	cout << *p << " " << *t << " " << *m << endl;
}

void exercitiuPointeri2() {
	int a = 9, b = 24, c = 71, d = 4;
	int* m = &a;
	int* n = &b;
	int* o = &c;
	int* p = &d;
	*n = *o + *p - d;
	o = &a;
	*o = *n - *o;
	o = &b;
	*p = *o - d;
	*n = *p + a;
	n = &a;
	*m = *p - *o;
	*n = *m - a;
	n = &b;

	cout << a << " " << b << " " << c << " " << d << endl;
	cout << m << " " << n << " " << o << " " << p << endl;
	cout << &a << " " << &b << " " << &c << " " << &d << endl;
	cout << *m << " " << *n << " " << *o << " " << *p << endl;
}

void exercitiuPointeri3() {
	int a = 15, b = 9, c = 27, d = 42, e = 7;
	int* x = &a;
	int* y = &b;
	int* z = &c;
	int* m = &d;
	int* n = &e;

	*m = *y + *x - 2 * *n;
	m = &a;
	*n = *m + 2 * *n;
	*x = 3 * *y - *z;
	z = &a;
	*z = a - *y;
	z = &b;
	n = &c;
	*m = *n + *z - *y;
	y = &a;
	*y = *m - e + 2 * d;
	*m = *y - b;
	m = &e;
	*n = *x + 2 * *y;
	n = &d;
	*x = *z + 4;
	*n = *z;

	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
	cout << &a << " " << &b << " " << &c << " " << &d << " " << &e << endl;
	cout << x << " " << y << " " << z << " " << m << " " << n << endl;
	cout << *x << " " << *y << " " << *z << " " << *m << " " << *n << endl;
}

void exercitiuPointeri4() {
	int a = 4, b = 9, c = 14, d = 19, e = 2;
	int* x = &a;
	int* y = &b;
	int* z = &c;
	int* m = &d;
	int* n = &e;
	
	*n = *x + *y - *z;
	m = &a;
	n = &b;
	*y = *m - 2 * b + *z;
	*n = (*m + 3 * a) / 2;
	x = &e;
	*x = *y + *z / 2;
	*y = *x;
	y = &a;
	*m = *x + 2 * *n;
	*n = (-1) * *m;
	*x = *y + 43 - *n;
	x = &a;
	*z = *x - *y;
	z = &a;
	*z = *z + 2 * e;
	*x = *z - *y;

	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
	cout << &a << " " << &b << " " << &c << " " << &d << " " << &e << endl;
	cout << x << " " << y << " " << z << " " << m << " " << n << endl;
	cout << *x << " " << *y << " " << *z << " " << *m << " " << *n << endl;
}

void referinte() {
	int x = 40;
	int y = 32;
	int& a = x;
	
	a = y - 4; // => x = y - 4 = 32 - 4 = 28 => x = 28
	y = a - sqrt(y / 2); // => y = x - sqrt(y / 2) = 28 - 4 = 24 => y = 24;

	cout << "x : " << x << endl;
	cout << "y : " << y << endl;
}

// Apelare prin valoare

void fv(int a, int b) {
	a = a - 3;
	b = b + 7;
}

void exempluApelareValoare() {
	int x = 12, y = 13;
	fv(x, y);

	cout << x << endl;
	cout << y << endl;
}

// Apelare prin referinte

void fr(int& a, int& b) {
	a = a - 3;
	b = b + 7;
}

void exempluApelareReferinta() {
	int x = 12, y = 13;
	fr(x, y);

	cout << x << endl;
	cout << y << endl;
}

// Apelare prin adresa

void fa(int* a, int* b) {
	*a = *a - 3;
	*b = *b + 7;
}

void exempluApelareAdresa() {
	int x = 12, y = 13;
	fa(&x, &y);

	cout << x << endl;
	cout << y << endl;
}








