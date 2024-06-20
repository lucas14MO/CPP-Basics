#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

#define N 3
#define M 10
#define W 5

void cargarMat(int m[N][N]);
void imprimirMat_max_min(int m[N][N], int&, int&);
void rango(int m[N][N], int max, int min);

int main()
{
    int mat[N][N], max, min;
    srand(time(NULL));

	cargarMat(mat);
	imprimirMat_max_min(mat, max, min);
	rango(mat, max, min);
}

void cargarMat(int m[N][N]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			m[i][j] = rand() % M;
}

void imprimirMat_max_min(int m[N][N], int& max, int& min) {
	max = min = m[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(W) << m[i][j];
			max = (max < m[i][j] ? m[i][j] : max);
			min = (min > m[i][j] ? m[i][j] : min);
		}
		cout << endl;
	}
}

void rango(int m[N][N], int max, int min) {
	int rang = max - min;
	int mns = 0, mys = 0, igus = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n = m[i][j];
			(n < rang ? mns++ : (n > rang ? mys++ : igus++));
		}
	}
	cout << endl << endl
		<< "Mayor valor: " << max << "\nMenor valor: " << min <<endl
		<< "Rango: " << rang << endl
		<< "\nValores..." << endl
		<< "Mayores al rango: " << mys << endl
		<< "Menores al rango: " << mns << endl
		<< "Iguales al rango: " << igus << endl;
}
		
