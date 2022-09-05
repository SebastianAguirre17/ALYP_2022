#include <iostream>

struct NumeroPar {
    int valor;
};

void Asignar(NumeroPar &numeroPar, int valor);

int obtenerSumatoriaV1(int desde, int hasta);


int main(int argc, char const *argv[]) {
    std::cout << "-------------------------\n"; 
    std::cout << "\tCLASE 1\n"; 
    std::cout << "-------------------------\n"; 




    return 0;
}

void Asignar(NumeroPar &numeroPar, int valor) {
    if (valor % 2 == 0 and valor != 0)
        numeroPar.valor += 2;
}
