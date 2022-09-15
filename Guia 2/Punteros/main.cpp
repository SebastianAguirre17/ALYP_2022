#include <iostream>

using namespace std;

int Sumar(int a, int b);

int main() {

    std::cout << "----------------------------------\n"; 
    std::cout << "\tPUNTEROS\n"; 
    std::cout << "----------------------------------\n\n"; 

    int a = 100;
    int b;
    b = 400;

    int r = Sumar(a, b);

    cout << "Valor a: " << a << endl;
    cout << "Valor &a: " << &a << endl;

    int* pEntero;
    cout << "Valor pEntero: " << pEntero << endl;
    pEntero = &a;
    cout << "Valor pEntero: " << pEntero << endl;


    int** pPuntero = &pEntero;
    cout << "Valor pPuntero: " << pPuntero << endl;


    std::cout << "\n----------------------------------\n"; 


    return EXIT_SUCCESS;
}

int Sumar(int a, int b) {
    return a + b;
}


/**
 * MEMORIA
 * 
 * Stack - Pila         -> Espacio de trabajo
 * Heap - Alacen libre  -> 
 * Segmento de Codigo   -> Instrucciones, contantes
 * 
 */

