#include <iostream>
#include <iomanip>
using namespace std;

#define ANCHO 12
#define ULTIMODIA(m1, a1) (m1==2? a1: (m1 < 8? (!(m1%2)? 30: 31): ((m1%2)? 30: 31)))
#define BIS(anho) (!(anho % 4) && (anho % 100 || !(anho % 400)))? 29: 28

int m, a, d, n;

int ingreso();
void calculo();
int impresion();

int main()
{
    do
    {
        ingreso();
        if (m) {
            calculo();
            impresion();
        }
        else break;
    } while (true);
    cout << endl << "FIN del proceso mes == 0";
}

int ingreso() {
    cout << endl
        << "FIN --> mes == 0. ";
    cout << endl
        << "Ingresar mes(1-12): ", cin >> m;
    if (!m) return 0;
    cout << endl
        << "Ingresar anho: ", cin >> a;
    return 0;
}
void calculo() {
    int d = 1;
    n = ((m <= 2 ?
        (a + 31 * (m - 1) + d * int((a - 1) / 4) - 3 * int(int((a + 99) / 100) / 4)) : //esta formula al dividir /7 me da restos de 0-6
        (a + 31 * (m - 1) + d - int((4 * m + 23) / 10) + int(a / 4) - int((3 * int(a / 100) + 1) / 4))))//esta otra al dividir me da 1-7, por eso abajo verifico "n"
        %7; 
    n = (m <= 2) ? n : (n != 0 ? n - 1 : 6); //si no es enero o febrero, a n le resto 1 o si es n == 0 lo paso a n = 6, porque (0 -1) = -1 
}
int impresion() {
    int d = 1;
    int ultimoDia = ULTIMODIA(m, BIS(a));
    if (m < 1 || m > 12) {
        cout << endl << "EROR: " << m << " no es un mes valido";
        return 0;
    }
    //cabecera
    cout << endl << setw(ANCHO * 4) << "Calendario de ";
    switch (m)
    {
    case 1: {cout << "Enero"; break; }
    case 2: {cout << "Febrero"; break; }
    case 3: {cout << "Marzo"; break; }
    case 4: {cout << "Abril"; break; }
    case 5: {cout << "Mayo"; break; }
    case 6: {cout << "Junio"; break; }
    case 7: {cout << "Julio"; break; }
    case 8: {cout << "Agosto"; break; }
    case 9: {cout << "Septiembre"; break; }
    case 10: {cout << "Octubre"; break; }
    case 11: {cout << "Noviembre"; break; }
    case 12: {cout << "Diciembre"; break; }
    }
    cout << " " << a << endl << endl <<
        setw(ANCHO) << "Domingo" <<
        setw(ANCHO) << "Lunes" <<
        setw(ANCHO) << "Martes" <<
        setw(ANCHO) << "Miercoles" <<
        setw(ANCHO) << "Jueves" <<
        setw(ANCHO) << "Viernes" <<
        setw(ANCHO) << "Sabado" << endl;
    //cuadricula
    for (int f = 0; f < 6; f++) {
        for (int c = 0; c < 7; c++) {
            if (d > ultimoDia) break;
            if (f == 0 && n > c)
                cout << setw(ANCHO) << " ";
            else
                cout << setw(ANCHO) << d, d++;
        }
        cout << endl;
    }
    return 0;
}
