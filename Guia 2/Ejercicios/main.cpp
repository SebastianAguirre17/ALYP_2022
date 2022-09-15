#include <iostream>
using namespace std;

// Punteros y vectores:
// - El nombre una variable que es un vector, tiene como valor la direccion de memoria del primer elemento del vector
// - Conocer las operaciones del tipo de dato punteros, conocidas como: aritmetica de punteros
void MostrarEnteros(int enteros[], int cantidad);
void MostrarEnterosP(int* enteros, int cantidad);
void Copiar(char* origen, char* destino);
int ContarCaracteres(char *cadena);
void Concatenar(char *cadena, char* subcadena);

int main(int argc, char const *argv[])
{
    std::cout << "----------------------------------\n"; 
    std::cout << "\tPUNTEROS\n"; 
    std::cout << "----------------------------------\n\n"; 

    char texto[] = "Hola";
    char texto2[] = " que tal";
    char copia[100];

    Copiar(texto, copia);
    cout << "Texto copiado: " << copia << endl << endl;
    cout << "Cantidad de caracteres: " <<  ContarCaracteres(copia) << endl << endl;
    Concatenar(texto, texto2);
    cout << "Concatenar: " << texto << endl << endl;

    /* int vector[] = { 1, 2, 3, 4, 5 };
    MostrarEnteros(vector, 5);
    cout << endl;
    MostrarEnterosP(vector, 5); */


    return 0;
}

void MostrarEnteros(int enteros[], int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        cout << &enteros[i] << " : " << enteros[i] << endl;
    }
}

void MostrarEnterosP(int* enteros, int cantidad) {
    for (int i = 0; i < cantidad; ++i, ++enteros) {
        cout << enteros << " : " << *enteros << endl;
    }
}

void Copiar(char *origen, char *destino) {
    while (*destino++ = *origen++);
}

int ContarCaracteres(char *cadena) {
    char* inicio = cadena;
	while (*cadena++);
	return cadena - inicio - 1;
}

void Concatenar(char *cadena, char* subcadena) {
    Copiar(subcadena, cadena + ContarCaracteres(cadena));
}