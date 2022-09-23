#include <iostream>

using namespace std;

void MostrarReversa (char* texto);
int ObtenerFibonacci(int n);
int ObtenerFibonacci2(int n);
int ObtenerFibonacci3(int n);
void InicializarMemo();
void PruebaFibonacci(int tope);
void PruebaFibonacci2(int tope);
void PruebaFibonacci3(int tope);

const int Tope = 42;
const int NoCalculado = -1;
int FibonacciosCalculados[Tope];

int main() {

    std::cout << "----------------------------------\n";
    std::cout << "\tPUNTEROS\n";
    std::cout << "----------------------------------\n\n";

    char texto[] = "UNDAV";
    //MostrarReversa(texto);

    InicializarMemo();

    // PruebaFibonacci(Tope);
    std::cout << "\n----------------------------------\n";
    // PruebaFibonacci2(Tope);
    std::cout << "\n----------------------------------\n";
    PruebaFibonacci3(Tope);


    return EXIT_SUCCESS;
}

void MostrarReversa (char* texto) {
    if (*texto) {
        MostrarReversa(texto + 1);
        cout << *texto;
    }
}

void InicializarMemo() {
    FibonacciosCalculados[0] = 0;
    FibonacciosCalculados[1] = 1;
    for (int i = 2; i <= Tope; ++i) {
        FibonacciosCalculados[i] = NoCalculado;
    }
}

int ObtenerFibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return ObtenerFibonacci(n - 1) + ObtenerFibonacci(n - 2);
}


int ObtenerFibonacci2(int n) {
    if (n == 0 or n == 1) return n;

    if (FibonacciosCalculados[n - 1] == NoCalculado)
        FibonacciosCalculados[n - 1] = ObtenerFibonacci2(n - 1);
    
    if (FibonacciosCalculados[n - 2] == NoCalculado)
        FibonacciosCalculados[n - 2] = ObtenerFibonacci2(n - 2);

    return FibonacciosCalculados[n - 1] + FibonacciosCalculados[n - 2];
}

int ObtenerFibonacci3(int n) {
    if (FibonacciosCalculados[n] == NoCalculado)
        FibonacciosCalculados[n] = ObtenerFibonacci3(n - 2) + ObtenerFibonacci3(n - 1);

    return FibonacciosCalculados[n];
}

void PruebaFibonacci(int tope) {

    for (int i = 0; i <= tope; ++i) {
        cout << "Fib[" << i << "]: " << ObtenerFibonacci(i) << endl;
    }
}

void PruebaFibonacci2(int tope) {

    for (int i = 0; i <= tope; ++i) {
        cout << "Fib2[" << i << "]: " << ObtenerFibonacci2(i) << endl;
    }
}

void PruebaFibonacci3(int tope) {

    for (int i = 0; i <= tope; ++i) {
        cout << "Fib3[" << i << "]: " << ObtenerFibonacci3(i) << endl;
    }
}