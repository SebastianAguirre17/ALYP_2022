#include <iostream>

int obtenerSumatoriaEnRango(int desde, int hasta);
int obtenerSumatoriaEnRangoV2(int desde, int hasta);
int obtenerSumatoriaEnRangoV3(int comienzo, int final);

int main() {
    std::cout << "-------------------------\n"; 
    std::cout << "\tCLASE 1\n"; 
    std::cout << "-------------------------\n\n"; 

    int desde = 10;
    int hasta = 50;
    int resultado = obtenerSumatoriaEnRango(desde, hasta);
    std::cout << "Resultado: " << desde << " - " << hasta << " : " << resultado << std::endl;
    resultado = obtenerSumatoriaEnRangoV2(desde, hasta);
    std::cout << "Resultado v2: " << desde << " - " << hasta << " : " << resultado << std::endl;
    resultado = obtenerSumatoriaEnRangoV3(desde, hasta);
    std::cout << "Resultado v3: " << desde << " - " << hasta << " : " << resultado << std::endl;

    return EXIT_SUCCESS;
}

//Algoritmo de GAUSS

int obtenerSumatoriaEnRango(int desde, int hasta) {
    int i, result = 0;
    for (i = desde; i <= hasta; i++) {
        result += i;
    }
    return result;
}


int obtenerSumatoriaEnRangoV2(int desde, int hasta) {
    return ((desde + hasta) * (hasta - desde + 1) / 2);
}

int obtenerSumatoriaEnRangoV3(int comienzo, int final) {
    return ((comienzo + final) * (final / 2)); 
}