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
// Se dă un vector cu n numere naturale. 
// Să se determine câte dintre perechile de 
// elemente din vector sunt prime între ele.