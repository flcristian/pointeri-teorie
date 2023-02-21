#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Functie ce returneaza cel mai mare si cel mai mic element dintr-un vector.

void maxAndMinPrinReferinta(int x[], int n, int& max, int& min) {
	max = x[0], min = x[0];
	for (int i = 1; i < n; i++) {
		if (x[i] > max) {
			max = x[i];
		}
		if (x[i] < min) {
			min = x[i];
		}
	}
}

void maxAndMinPrinAdresa(int x[], int n, int* max, int* min) {
	*max = x[0], *min = x[0];
	for (int i = 1; i < n; i++) {
		if (x[i] > *max) {
			*max = x[i];
		}
		if (x[i] < *min) {
			*min = x[i];
		}
	}
}

// =-=-=-=-=-=-=-=-=-=
// Probleme cu vectori.
// =-=-=-=-=-=-=-=-=-=

// Problema 1
// Se dă un șir cu n elemente, numere naturale. 
// Determinați diferența în valoare absolută dintre 
// numărul de valori pare din șir și numărul 
// de valori impare din șir.

void rezolvareV1(int* dif, int* x, int d) {
	int impare, pare = 0;
	for (int* i = x; i < x + d; i++) {
		if (*i % 2 == 0) {
			pare++;
		}
	}
	impare = d - pare;

	if (pare > impare) {
		int r = impare;
		impare = pare;
		pare = r;
	}

	*dif = impare - pare;
}

void citireVector(int* p, int& d) {
	ifstream f("input.txt");
	d = 0;
	while (!f.eof()) {
		f >> *(p + d);
		d++;
	}
	f.close();
}

void problemaVectori1() {
	int x[100], d;
	citireVector(x, d);

	int dif;
	rezolvareV1(&dif, x, d);
	cout << "Diferenta este : " << dif << endl;
}

// Problema 2
// Se citește un vector cu n elemente, 
// numere naturale. Să se afișeze elementele din 
//vector care sunt multipli ai ultimului element.

void rezolvareV2(int* x, int d) {
	for (int* a = x; a < x + d; a++) {
		if (*a % *(x + (d - 1)) == 0) {
			cout << *a << " ";
		}
	}
	cout << endl;
}

void problemaVectori2() {
	int x[100], d;
	citireVector(x, d);

	rezolvareV2(x, d);
}

// Problema 3
// Se citește un vector cu n elemente, numere naturale. 
// Să se afișeze elementele cu indici pari în 
// ordinea crescătoare a indicilor, iar elementele 
// cu indici impari în ordinea descrescătoare a indicilor.

void rezolvareV3(int* x, int d) {
	for (int* a = x + 1; a < x + d; a += 2) {
		cout << *a << " ";
	}
	cout << endl;
	int i = 1;
	if (d % 2 == 0) {
		i++;
	}
	for (int* a = x + d - i; a > x - 1; a -= 2) {
		cout << *a << " ";
	}
}

void problemaVectori3() {
	int x[100], d;
	citireVector(x, d);

	rezolvareV3(x, d);
}

// Problema 4

void rezolvareV4(int* x, int d) {
	int* a = x;
	int* b = x + d - 1;
	for (int i = 0; i < d; i++) {
		if (i % 2 == 0) {
			cout << *a << " ";
			a++;
		}
		else {
			cout << *b << " ";
			b--;
		}
	}
}

void problemaVectori4() {
	int x[100], d;
	citireVector(x, d);

	rezolvareV4(x, d);
}

// Problema 5
// Să se determine maximul şi minimul 
// valorilor elementelor unui vector.

void rezolvareV5(int* x, int d, int* max, int* min) {
	*max = *x, * min = *x;
	for (int* a = x; a < x + d; a++) {
		if (*a > *max) {
			*max = *a;
		}
		if (*a < *min) {
			*min = *a;
		}
	}
}

void problemaVectori5() {
	int x[100], d;
	citireVector(x, d);

	int max, min;
	rezolvareV5(x, d, &max, &min);
	cout << "Max = " << max << "\nMin = " << min << endl;
}

// Problema 6
// Să se determine indicele maximului şi 
// cel al minimului valorilor elementelor unui vector.

void rezolvareV6(int* x, int d, int* pmax, int* pmin) {
	int max = *x, min = *x;
	for (int* a = x; a < x + d; a++) {
		if (*a > max) {
			max = *a;
			*pmax = a - x;
		}
		if (*a < min) {
			min = *a;
			*pmin = a - x;
		}
	}
}

void problemaVectori6() {
	int x[100], d;
	citireVector(x, d);

	int pmax, pmin;
	rezolvareV6(x, d, &pmax, &pmin);
	cout << "Pos max = " << pmax << "\nPos min = " << pmin << endl;
}

// Problema 7
// Se citește un vector cu n elemente, numere naturale. 
// Să se determine câte elemente ale vectorului sunt 
// egale cu diferența dintre cea mai mare și cea 
// mai mică valoare din vector.

void rezolvareV7(int* x, int d, int* count) {
	int max = *x, min = *x;
	*count = 0;
	for (int* a = x; a < x + d; a++) {
		if (*a > max) {
			max = *a;
		}
		if (*a < min) {
			min = *a;
		}
	}
	int dif = max - min;
	for (int* a = x; a < x + d; a++) {
		if (*a == dif) {
			*count = *count + 1;
		}
	}
}

void problemaVectori7() {
	int x[100], d;
	citireVector(x, d);

	int count;
	rezolvareV7(x, d, &count);
	cout << count << endl;
}

// Problema 8
// Se citește un vector cu n elemente, 
// numere naturale distincte. Să se afișeze 
// elementele cuprinse între elementul cu valoarea 
// minimă și cel cu valoare maximă din vector, 
// inclusiv acestea.

void rezolvareV8(int* x, int d) {
	int max = *x, min = *x;
	int pmax = 0, pmin = 0;
	for (int* a = x; a < x + d; a++) {
		if (*a > max) {
			max = *a;
			pmax = a - x;
		}
		if (*a < min) {
			min = *a;
			pmin = a - x;
		}
	}
	if (pmax > pmin) {
		int r = pmin;
		pmin = pmax;
		pmax = r;
	}

	for (int* a = x + pmax; a <= x + pmin; a++) {
		cout << *a << " ";
	}
	cout << endl;
}

void problemaVectori8() {
	int x[100], d;
	citireVector(x, d);

	rezolvareV8(x, d);
}

// Problema 9
// Se citește un vector cu n elemente, numere naturale. 
// Să se determine suma valorilor elementelor cuprinse 
// între primul și ultimul element par al vectorului, 
// inclusiv acestea.

int posPrimPar(int* x, int d) {
	for (int* a = x; a < x + d; a++) {
		if (*a % 2 == 0) {
			return a - x;
		}
	}
	return 0;
}

int posUltimPar(int* x, int d) {
	for (int* a = x + d - 1; a > x - 1; a--) {
		if (*a % 2 == 0) {
			return a - x;
		}
	}
	return 0;
}

void rezolvareV9(int* x, int d, int* suma) {
	int pPrimPar = posPrimPar(x, d);
	int pUltimPar = posUltimPar(x, d);
	*suma = 0;
	for (int* a = x + pPrimPar; a <= x + pUltimPar; a++) {
		*suma += *a;
	}
}

void problemaVectori9() {
	int x[100], d;
	citireVector(x, d);

	int suma;
	rezolvareV9(x, d, &suma);
	cout << suma << endl;
}

// Problema 10
// Se dă un vector cu n numere naturale. 
// Să se determine câte dintre elemente au valoarea 
// strict mai mare decât media aritmetică a 
// elementelor vectorului.

void rezolvareV10(int* x, int d, int* count) {
	int suma = 0;
	for (int* a = x; a < x + d; a++) {
		suma += *a;
	}
	int medie = suma / d;
	*count = 0;
	for (int* a = x; a < x + d; a++) {
		if (*a > medie) {
			*count = *count + 1;
		}
	}
}

void problemaVectori10() {
	int x[100], d;
	citireVector(x, d);

	int count;
	rezolvareV10(x, d, &count);
	cout << count << endl;
}

// Problema 11
// Se dă un vector cu n numere naturale.
// Să se determine câte dintre perechile de 
// elemente egal depărtate de capetele 
// vectorului sunt prime între ele.

int cmmdc(int a, int b) {
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	return a;
}

void rezolvareV11(int* x, int d, int* count) {
	*count = 0;
	int* a = x;
	int* b = x + d - 1;
	while (a < x + (d / 2)) {
		if (cmmdc(*a, *b) == 1) {
			*count = *count + 1;
		}
		a++, b--;
	}
}

void problemaVectori11() {
	int x[100], d;
	citireVector(x, d);

	int count;
	rezolvareV11(x, d, &count);
	cout << count << endl;
}

// Problema 12
// Se dă un șir cu n elemente, numere reale. 
// Să se determine câte dintre elemente se află 
// în afara intervalului închis determinat de 
// primul și ultimul element.

void rezolvareV12(double* x, int d, int* count) {
	double st = *x, dr = *(x + d - 1);
	if (st > dr) {
		double r = st;
		st = dr;
		dr = r;
	}
	*count = d;
	for (double* a = x; a < x + d; a++) {
		if (*a >= st && *a <= dr) {
			*count = *count - 1;
		}
	}
}

void citireVectorDouble(double* p, int& d) {
	ifstream f("input.txt");
	d = 0;
	while (!f.eof()) {
		f >> *(p + d);
		d++;
	}
	f.close();
}

void problemaVectori12() {
	double x[100];
	int d;
	citireVectorDouble(x, d);

	int count;
	rezolvareV12(x, d, &count);
	cout << count << endl;
}

// Problema 13
// Se dă un vector cu n numere naturale. 
// Să se determine câte dintre perechile de elemente 
// din vector sunt formate din valori cu 
// aceeași sumă a cifrelor.

void sumaCifre(int* suma, int n) {
	*suma = 0;
	while (n > 0) {
		*suma = *suma + (n % 10);
		n /= 10;
	}
}

void rezolvareV13(int* x, int d, int* count) {
	*count = 0;
	for (int* a = x; a < x + d; a++) {
		int sp;
		sumaCifre(&sp, *a);
		for (int* b = a + 1; b < x + d; b++) {
			int ss;
			sumaCifre(&ss, *b);
			if (ss == sp) {
				*count = *count + 1;
			}
		}
	}
}

void problemaVectori13() {
	int x[100], d;
	citireVector(x, d);

	int count;
	rezolvareV13(x, d, &count);
	cout << count << endl;
}

// Problema 14
// Se dă un vector x cu n elemente, numere naturale. 
// Să se construiască un alt vector, y, cu proprietatea 
// că y[i] este egal cu restul împărțirii lui x[i] 
// la suma cifrelor lui x[i].

void rezolvareV14(int* x, int d, int* y) {
	for (int* a = x; a < x + d; a++) {
		int* b = y + (a - x);
		int s;
		sumaCifre(&s, *a);
		*b = *a % s;
	}
}

void afisareV14(int* y, int d) {
	for (int* a = y; a < y + d; a++) {
		cout << *a << " ";
	}
	cout << endl;
}

void problemaVectori14() {
	int x[100], d;
	citireVector(x, d);

	int y[100];
	rezolvareV14(x, d, y);
	afisareV14(y, d);
}

// Problema 15
// Se dă un vector x cu n elemente, numere naturale.
// Să se construiască un alt vector, y, cu n elemente, 
// cu proprietatea că y[i] este egal cu suma 
// elementelor din x, cu excepția lui x[i].

void sumaElemente(int* x, int d, int p, int* suma) {
	*suma = 0;
	for (int* a = x; a < x + d; a++) {
		if (a - x != p) {
			*suma = *suma + *a;
		}
	}
}

void rezolvareV15(int* x, int d, int* y) {
	for (int* a = x; a < x + d; a++) {
		int* b = y + (a - x);
		sumaElemente(x, d, a - x, b);
	}
}

void problemaVectori15() {
	int x[100], d;
	citireVector(x, d);

	int y[100];
	rezolvareV15(x, d, y);
	for (int* a = y; a < y + d; a++) {
		cout << *a << " ";
	}
}

// Problema 16
// Se dă un vector x cu n elemente, numere naturale. 
// Să se construiască un alt vector, y, care 
//să conțină elementele impare din x, în ordine inversă.

void rezolvareV16(int* x, int d, int* y, int* n) {
	*n = 0;
	for (int* a = x + d - 1; a > x - 1; a--) {
		if (*a % 2 == 1) {
			*(y + *n) = *a;
			*n = *n + 1;
		}
	}
}

void problemaVectori16() {
	int x[100], d;
	citireVector(x, d);

	int y[100], n;
	rezolvareV16(x, d, y, &n);
	for (int* a = y; a < y + n; a++) {
		cout << *a << " ";
	}
}

// Problema 17
// Se dă un vector x cu n elemente, numere naturale. 
// Să se construiască un alt vector, y, care să conțină 
// elementele prime din x, în ordine inversă.

int countDiv(int x) {
	int c = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			c++;
		}
	}
	return c;
}

bool estePrim(int x) {
	if (countDiv(x) == 2) {
		return 1;
	}
	return 0;
}

void rezolvareV17(int* x, int d, int* y, int* n) {
	*n = 0;
	for (int* a = x + d - 1; a > x - 1; a--) {
		if (estePrim(*a)) {
			*(y + *n) = *a;
			*n = *n + 1;
		}
	}
}

void problemaVectori17() {
	int x[100], d;
	citireVector(x, d);

	int y[100], n;
	rezolvareV17(x, d, y, &n);
	for (int* a = y; a < y + n; a++) {
		cout << *a << " ";
	}
}

// Problema 18
// Se dă un vector cu n numere naturale. 
// Să se determine câte dintre elementele 
// vectorului sunt prime cu ultimul element.

void rezolvareV18(int* x, int d, int* count) {
	int* l = x + d - 1;
	*count = 0;
	for (int* a = x; a < x + d - 1; a++) {
		if (cmmdc(*a, *l) == 1) {
			*count = *count + 1;
		}
	}
}

void problemaVectori18() {
	int x[100], d;
	citireVector(x, d);

	int count;
	rezolvareV18(x, d, &count);
	cout << count << endl;
}

// Problema 19
// Să se înlocuiască toate elementele nule 
// dintr-un vector cu elemente numere naturale 
// cu partea întreagă a mediei aritmetice a 
// elementelor nenule din vector.

void rezolvareV19(int* x, int d) {
	int suma = 0, n = 0;
	for (int* a = x; a < x + d; a++) {
		if (*a != 0) {
			suma += *a;
			n++;
		}
	}
	int medie = suma / n;
	for (int* a = x; a < x + d; a++) {
		if (*a == 0) {
			*a = medie;
		}
	}
}

void problemaVectori19() {
	int x[100], d;
	citireVector(x, d);

	rezolvareV19(x, d);
	for (int* a = x; a < x + d; a++) {
		cout << *a << " ";
	}
}

// Problema 20
// Se dă un vector x cu n elemente numere întregi, 
// și un vector y cu m elemente, de asemenea numere întregi. 
// Să se afișeze toate elementele din vectorul x care sunt 
// mai mici decât toate elementele din vectorul y.

void rezolvareV20(int* x, int* y, int n, int m) {
	for (int* a = x; a < x + n; a++) {
		bool flag = true;
		for (int* b = y; b < y + m; b++) {
			if (*a > *b) {
				flag = false;
			}
		}
		if (flag) {
			cout << *a << " ";
		}
	}
}

void citireDoiVectori(int* x, int* y, int& n, int& m) {
	ifstream f("input.txt");
	f >> n;
	for (int* a = x; a < x + n; a++) {
		f >> *a;
	}
	f >> m;
	for (int* a = y; a < y + m; a++) {
		f >> *a;
	}
	f.close();
}

void problemaVectori20() {
	int x[100], y[100], n, m;
	citireDoiVectori(x, y, n, m);

	rezolvareV20(x, y, n, m);
}

// Problema 21
// Se dă un vector x cu n elemente numere întregi, 
// și un vector y cu m elemente, de asemenea numere întregi. 
// Să se afișeze toate elementele din vectorul x care sunt 
// mai mari decât toate elementele din vectorul y.

void rezolvareV21(int* x, int* y, int n, int m) {
	for (int* a = x; a < x + n; a++) {
		bool flag = true;
		for (int* b = y; b < y + m; b++) {
			if (*a < *b) {
				flag = false;
			}
		}
		if (flag) {
			cout << *a << " ";
		}
	}
}

void problemaVectori21() {
	int x[100], y[100], n, m;
	citireDoiVectori(x, y, n, m);

	rezolvareV21(x, y, n, m);
}

// Problema 22
// Se dă un număr natural nenul k și vector cu n numere naturale. 
// Să se înlocuiască fiecare element cu multiplul lui k cel mai
// apropiat de el și să se afișeze elementele astfel obținute 
// în ordine inversă.

void rezolvareV22(int* x, int d, int k) {
	for (int* a = x; a < x + d; a++) {
		int c = *a / k;
		int st = c * k, dr = (c + 1) * k;
		if (*a - st > dr - *a) {
			*a = dr;
		}
		else {
			*a = st;
		}
	}
}

void problemaVectori22() {
	int x[100], d, k;
	citireVector(x, d);
	cout << "Introduceti k : ";
	cin >> k;

	rezolvareV22(x, d, k);
	for (int* a = x + d - 1; a > x - 1; a--) {
		cout << *a << " ";
	}
}

// Problema 23
// Să se șteargă dintr-un șir 
// elementul aflat pe o poziție dată. 

void stergePos(int* x, int* d, int k) {
	for (int* a = x + k; a < x + *d - 1; a++) {
		*a = *(a + 1);
	}
	if (k < *d) {
		*d = *d - 1;
	}
}

void problemaVectori23() {
	int x[100], d, k;
	citireVector(x, d);
	cout << "Introduceti pozitia (0 = prima pozitie) : ";
	cin >> k;

	stergePos(x, &d, k);
	for (int* a = x; a < x + d; a++) {
		cout << *a << " ";
	}
}

// Problema 24
// Să se șteargă dintr-un vector toate 
// elementele care sunt numere prime.

void rezolvareV24(int* x, int* d) {
	for (int* a = x; a < x + *d; a++) {
		if (estePrim(*a)) {
			stergePos(x, d, a - x);
			a--;
		}
	}
}

void problemaVectori24() {
	int x[100], d;
	citireVector(x, d);

	rezolvareV24(x, &d);
	for (int* a = x; a < x + d; a++) {
		cout << *a << " ";
	}
}

// Problema 25
// Să se șteargă dintr-un 
// vector toate elementele pare.

void rezolvareV25(int* x, int* d) {
	for (int* a = x; a < x + *d; a++) {
		if (*a % 2 == 0) {
			stergePos(x, d, a - x);
			a--;
		}
	}
}

void problemaVectori25() {
	int x[100], d;
	citireVector(x, d);

	rezolvareV25(x, &d);
	for (int* a = x; a < x + d; a++) {
		cout << *a << " ";
	}
}

// Problema 26
// Se citește un șir cu n elemente, numere întregi. 
// Să se șteargă elementele care se repetă, 
// păstrându-se doar primul de la stânga la dreapta.

void rezolvareV26(int* x, int* d) {
	for (int* a = x; a < x + *d; a++) {
		for (int* b = a + 1; b < x + *d; b++) {
			if (*a == *b) {
				stergePos(x, d, b - x);
				b--;
			}
		}
	}
}

void problemaVectori26() {
	int x[100], d;
	citireVector(x, d);

	rezolvareV26(x, &d);
	for (int* a = x; a < x + d; a++) {
		cout << *a << " ";
	}
}

// Problema 27
// Să se insereze pe o poziție dată 
// într-un șir o valoare precizată.

void adaugareVal(int* x, int* d, int v, int k) {
	if (k < *d) {
		for (int* a = x + *d; a > x + k; a--) {
			*a = *(a - 1);
		}
		*(x + k) = v;
		*d = *d + 1;
	}
	else {
		*(x + *d) = v;
		*d = *d + 1;
	}
}

void problemaVectori27() {
	int x[100], d, v, k;
	citireVector(x, d);
	cout << "Introduceti valoarea : ";
	cin >> v;
	cout << "Introduceti pozitia (0 = prima pozitie) : ";
	cin >> k;

	adaugareVal(x, &d, v, k);
	for (int* a = x; a < x + d; a++) {
		cout << *a << " ";
	}
}

