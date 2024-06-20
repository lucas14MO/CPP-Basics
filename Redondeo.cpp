#include <iostream>
using namespace std;

float redondeo(float n,  int deci);
float redondeo2(float n, int deci);

int main()
{
    float valor;
    int decimales;
    cout << "\nValor: ", cin>> valor;
    cout << "\nCantidad de decimales: ", cin>> decimales;
    cout<< "\n" << redondeo(valor, decimales);
    cout << "\n" << redondeo2(valor, decimales);
}

float redondeo(float n, int deci)
{
    float n1;
    int n2;
    deci = powf(10, deci + 1); //para verificar el redondeo se eleva a deci + 1
    n2 = n * deci, deci /= 10; //salvamos los decimales + 1 que queremos corriendo la coma
    n2 = n1 = (n2 / 10.0); //dividiendo entre 10 n2 trunca el decimal extra
    n2 = n1 - n2 >= 0.5? n2+1 : n2;// n2 y n1 tienen el mismo valor entero, n1 no trunco el decimal extra, si es >= 0.5 suma 1 a n2
    return(float(n2)/deci);// n2 tiene los decimales que salvamos, al dividir entre deci se regresa a n pero redondeado
}

float redondeo2(float n, int deci) {
    int can = pow(10, deci);
    int n1 = int(n * can);
    float d1 = n * can - n1;
    if (d1 >= 0.5) n1++;
    return(n1/float(can));
}
