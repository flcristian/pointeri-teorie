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

void exercitiu1() {
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

void exercitiu2() {
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