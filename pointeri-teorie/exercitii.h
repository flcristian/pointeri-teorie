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
