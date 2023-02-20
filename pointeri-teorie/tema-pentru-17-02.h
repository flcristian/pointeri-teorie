#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Problema 1
// Se citește n număr natural. 
// Calculați suma numerelor naturale
// mai mici sau egale cu n.

void rezolvare1(int n, int& suma) {
	suma = (n * (n + 1)) / 2;
}

void problema1() {
	int n, suma;
	cout << "Introduceti n : ";
	cin >> n;

	rezolvare1(n, suma);
	cout << "Suma este : " << suma << endl;
}

// Problema 2
// Să se scrie un program care citește 
// numărul natural n și determină suma 2+4+..+(2n).

void rezolvare2(int n, int* suma) {
	*suma = (n * (n + 1));
}

void problema2() {
	int n, suma;
	cout << "Introduceti n : ";
	cin >> n;

	rezolvare2(n, &suma);
	cout << "Suma este : " << suma << endl;
}

// Problema 3
// Să se scrie un program care citește 
// numărul natural n și determină 
// suma S=1*2+2*3+3*4...+n*(n+1).

void rezolvare3(int n, int& suma) {
	suma = 0;
	for (int i = 0; i <= n; i++) {
		suma += i * (i + 1);
	}
}

void problema3() {
	int n, suma;
	cout << "Introduceti n : ";
	cin >> n;

	rezolvare3(n, suma);
	cout << "Suma este : " << suma << endl;
}

// Problema 4
// Să se scrie un program care citește numărul 
// natural n și determină valoarea lui
// n != 1 * 2 * 3*...*n.

void rezolvare4(int n, int* factorial) {
	*factorial = 1;
	for (int i = 2; i <= n; i++) {
		*factorial *= i;
	}
}

void problema4() {
	int n, factorial;
	cout << "Introduceti n : ";
	cin >> n;

	rezolvare4(n, &factorial);
	cout << "Factorialul este : " << factorial << endl;
}

// Problema 5
// Se dă numărul natural nenul n. 
// Să se determine produsul primelor n numere impare.

void rezolvare5(int n, int& p) {
	p = 1;
	for (int i = 1; i < n; i++) {
		p *= (2 * i) + 1;
	}
}

void problema5() {
	int n, p;
	cout << "Introduceti n : ";
	cin >> n;

	rezolvare5(n, p);
	cout << "Produsul este : " << p << endl;
}

// Problema 6
// Se dă numărul natural nenul n. 
// Să se determine produsul primelor 
// n pătrate perfecte nenule.

void rezolvare6(int n, int* p) {
	*p = 1;
	for (int i = 2; i <= n; i++) {
		*p *= pow(i, 2);
	}
}

void problema6() {
	int n, p;
	cout << "Introduceti n : ";
	cin >> n;

	rezolvare6(n, &p);
	cout << "Produsul este : " << p << endl;
}

// Problema 7
// Să se scrie un program care citește numărul 
// natural n și determină suma S=1!+2!+3!+...+n!.

void factorial(int nr, int* f) {
	*f = 1;
	for (int i = 2; i <= nr; i++) {
		*f *= i;
	}
}

void rezolvare7(int n, int& suma) {
	suma = 0;
	for (int i = 1; i <= n; i++) {
		int f;
		factorial(i, &f);
		suma += f;
	}
}

void problema7() {
	int n, suma;
	cout << "Introduceti n : ";
	cin >> n;

	rezolvare7(n, suma);
	cout << "Suma este : " << suma << endl;
}

// Problema 8
// Să se scrie un program care citește 
// numărul natural n și determină suma S=1^1+2^2+ ... + n^n.

void rezolvare8(int n, int* suma) {
	*suma = 1;
	for (int i = 2; i <= n; i++) {
		*suma += pow(i, i);
	}
}

void problema8() {
	int n, suma;
	cout << "Introduceti n : ";
	cin >> n;

	rezolvare8(n, &suma);
	cout << "Suma este : " << suma << endl;
}

// Problema 9
// Se dau n numere naturale. Pentru fiecare numar n, 
// calculati 1+(1+2)+(1+2+3)+(1+2+3+4)+...+(1+2+3+...n)

void sumaGauss(int nr, int* s) {
	*s = (nr * (nr + 1)) / 2;
}

void rezolvare9(int n, int& suma) {
	suma = 1;
	for (int i = 2; i <= n; i++) {
		int s;
		sumaGauss(i, &s);
		suma += s;
	}
}

void problema9() {
	int n, suma;
	cout << "Introduceti n : ";
	cin >> n;

	rezolvare9(n, suma);
	cout << "Suma este : " << suma << endl;
}

// Problema 10
// Se dau n numere naturale, unde n este număr par. 
// Să se calculeze suma produselor dintre fiecare număr 
// din prima jumătate și fiecare număr din a doua 
// jumătate a șirului de numere date.

void rezolvare10(int x[], int n, int& suma) {
	suma = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = n / 2; j < n; j++) {
			suma += x[i] * x[j];
		}
	}
	
}

void citire(int x[], int* n) {
	ifstream f("input.txt");
	*n = 0;
	while (!f.eof()) {
		f >> x[*n];
		*n = *n + 1;
	}
	f.close();
}

void problema10() {
	int x[100], n, suma;
	citire(x, &n);
	
	rezolvare10(x, n, suma);
	cout << "Suma este : " << suma << endl;
}


