#include <iostream>
using namespace std;

#define A(a1) (a1 ? true : false)

struct Ecu
{
    float a;
    float b;
    float c;
};

Ecu ecu;

Ecu ecuacion_gnrl(Ecu);

int main()
{
    do
    {
        cout << "\nIngrese valores para la ecuacion (Fin -> a == 0)\n"
            <<"a: ", cin>>ecu.a;

        if (!A(ecu.a)) {
            cout << "\n a == 0 , valor no valido!\n";
            break;
        }

        cout <<
            "b: ", cin>> ecu.b,cout<<
            "c: ", cin>> ecu.c;
        cout << endl;

        ecu = ecuacion_gnrl(ecu);

        if (!ecu.a) cout << "\n\nSoluciones no reales";
        else cout << "Soluciones reales:\n" <<
                     "x1 = " << ecu.b << endl <<
                     "x2 = " << ecu.c << endl;
        
    } while (true);

    cout << "\n\nFin del programa, a == 0" << endl;
}

Ecu ecuacion_gnrl(Ecu e) {
    // a == bandera real/imaginario
    // b == x1
    // c == x2

    float raiz = (powf(e.b, 2) - (4.0 * e.a * e.c));
    float div = e.a * 2.0;

    e.a = (raiz < 0 ? 0 : 1); //real == 1 / imaginario == 0
    if (e.a) {
        raiz = sqrtf(raiz);
        e.c = (- e.b + raiz) / div;
        e.b = (-e.b - raiz) / div;
    }

    return(e);
}
