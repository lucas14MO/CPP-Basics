#include <iostream>
#include <ctime>
using namespace std;

#define N 5
#define MAX 21
#define MIN 2


float randomNumbers(int min, int max);
float area_rectangulo(float, float);
void matrizRectangulos();

int main()
{

	srand(time(NULL));

	matrizRectangulos();
}

void matrizRectangulos() {
	float mat[N][2];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++) {
			*(mat[i] + j) = randomNumbers(MIN, MAX);//cin>>*(mat[i] + j);   v[5][4]; v[4] + 3
		}

	cout << "\nRectangulos" << endl
		<< "Base\tAltura\tArea" << endl; 

	for (int i = 0; i < N; i++){
		cout << *(mat[i] + 0) <<"\t"<< *(mat[i] + 1)<<"\t" << area_rectangulo(*(mat[i] + 0), *(mat[i] + 1)) <<endl;
	}
}

float area_rectangulo(float b, float h) {
	return b * h;
}

float randomNumbers(int min, int max) {
    return (rand() % (max - min) + min) * 0.75;
}