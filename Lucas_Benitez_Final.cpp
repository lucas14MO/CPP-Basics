#include <iostream>
#include <math.h>
using namespace std;

bool con = true, real;

void menu();
float ecuacion(float a, float b);
float ecuacion(float& a, float b, float c);

int main()
{
    do
    {
        menu();
    } while (con);
}

void menu() {
    int mod;
    float x, a, b, c;
    cout << "Ingrese modo(0 = lineal / 1 = cuadratica / 2 = FIN): ";
    cin >> mod;
    switch (mod) {
        case 0: {
            cout << "Ingresar a: ", cin >> a;
            cout << "Ingresar b: ", cin >> b;
            x = ecuacion(a, b);
            break;
        }
        case 1: {
            cout << "Ingresar a: ", cin >> a;
            cout << "Ingresar b: ", cin >> b;
            cout << "Ingresar c: ", cin >> c;
            x = ecuacion(a, b, c);
            break;
        }
        case 2: {
            con = false;
            return;
        }
        default: {
            cout << "\nModo no valido\n\n";
            return;
        }
    }
    (real ? (mod == 1 ? cout << "\nSoluciones x1 = " << x << " x2 = " << a : cout << "\nSolucion x = " << x)
            :
            (mod == 1 ? cout << "\nSoluciones no reales o indetermindas( a == 0) " : cout << "\nSolucion indeterminada (a == 0)"));
    
    cout << endl << endl;
}

float ecuacion(float a, float b) {
    //division por 0 da resultado indeterminado
    (!a ? real = 0: real = 1);
    if (real) return(-b / a); else return 0;
}

float ecuacion(float& a, float b, float c) {
    float aux = powf(b, 2) - 4.0 * a * c;
    //division por 0 es indeterminado o raiz de numero negativo da resultados no reales(indeterminado)
    ((!a || aux < 0) ? real = 0 : real = 1);
    if (real) {
        aux = sqrtf(aux);
        float aux2 = 2 * a;
        a = (-b - aux)/ aux2;
        return((-b + aux) / aux2);
    }
}
