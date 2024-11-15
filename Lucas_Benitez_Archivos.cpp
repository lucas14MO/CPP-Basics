#include <iostream>
#include <conio.h>
#pragma warning(disable:4996)
using namespace std;

struct Producto
{
	int id;
	char des[30];
	float can;
};

struct Precios
{
	int id;
	float pre;
};

struct Informe
{
	int id;
	char des[30];
	float can;
	float pre;
	float sv;
};

char archs[3][8] = {"pro.txt", "pre.txt", "inf.txt"};

void menu(int&);
void agregarPro();
void crearInfor();
void leerInform();
void reset();

int main()
{
	int m;
	do menu(m); while (m);
}

void menu(int& mode) {
	cout << "\nPulse cualquier tecla para continuar...", getch();
	cout << "\n\nSeleccionar modo\n (Agregar producto = 1, crear informe = 2, leer informe = 3, BORRAR TODO = 4, FIN == 0): ", cin>> mode;
	switch (mode)
	{
	case 0: cout << "\nFin del programa.\n"; break;
	case 1: agregarPro(); break;
	case 2: crearInfor(); break;
	case 3: leerInform(); break;
	case 4: reset(); break;
	default:
		cout << "\nModo no valido!\n";
		break;
	}
}

void agregarPro() {
	FILE* a1 = fopen(archs[0], "a");
	FILE* a2 = fopen(archs[1], "a");
	if (a1 == NULL || a2 == nullptr) { cout << "Error al abrir archivo/s"; return; }

	Producto pro; 
	Precios pre;
	cout << "Agregar nuevo producto\nId: ", cin>> pro.id, pre.id = pro.id;
	cout << "Descripcion breve: ", cin>>pro.des;
	cout << "Cantidad stock: ", cin>>pro.can;
	cout << "Precio: ", cin>>pre.pre;

	fprintf(a1, "%i %s %f\n", pro.id, pro.des, pro.can);
	fprintf(a2, "%i %f\n", pre.id, pre.pre);

	fclose(a1);
	fclose(a2);

	cout << "\nSe agrego correctamente!\n";
}

void crearInfor() {
	char c;
	cout << "\nEl anterior informe se eliminara, continuar? (y/n): ", cin>>c;
	if (c != 'y' && c != 'Y') return;
	
	FILE* a1 = fopen(archs[0], "r");
	FILE* a2 = fopen(archs[1], "r");
	FILE* a3 = fopen(archs[2], "w"); //Entiendo que el informe es "Temporal o del momento" por eso "w"

	if (a1 == nullptr || a2 == nullptr || a3 == NULL) { cout << "Error al abrir archivo/s"; return; }

	Producto pro;
	Precios pre;
	Informe inf;

	while (fscanf(a1, "%i %30s %f", &pro.id, pro.des, &pro.can) != EOF && fscanf(a2, "%i %f", &pre.id, &pre.pre) != EOF)
	{
		fprintf(a3, "%i %s %f %f %f\n", pro.id, pro.des, pro.can, pre.pre, (pro.can * pre.pre));
	}
	fclose(a1);
	fclose(a2);
	fclose(a3);

	cout << "\nSe creo correctamente!\nModo 3 para verlo";
}

void leerInform() {
	FILE* a1 = fopen(archs[2], "r");

	if (a1 == nullptr) { cout << "Error al abrir archivo"; return; }

	cout << "\nINFORME";
		
	Informe inf;
	while (fscanf(a1, "%i %30s %f %f %f", &inf.id, inf.des, &inf.can, &inf.pre, &inf.sv) != EOF)
	{
		cout << "\n" <<
				"Producto " << inf.id << endl <<
				"Descripcion: " << inf.des << endl <<
				"Stock: " << inf.can << endl << 
				"Precio: " << inf.pre << endl << 
				"Valor de Stock: " << inf.sv<< endl;
	}
	fclose(a1);
}

void reset() {
	char c;
	cout << "Seguro que quiere borrar todo?(y/n): ", cin >> c;
	if (c != 'y' && c != 'Y') return;

	FILE* a1 = fopen(archs[0], "w");
	FILE* a2 = fopen(archs[1], "w");
	FILE* a3 = fopen(archs[2], "w"); 

	fclose(a1);
	fclose(a2);
	fclose(a3);

	cout << "\nSe borraron todos los datos exitosamente\n";
}
