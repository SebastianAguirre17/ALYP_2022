#include <iostream>

using namespace std;

void Swap(bool* pA, bool* pB);
void Swap2(bool** pA, bool** pB);
void PruebaSwap();
void PruebaSwap2();

int main() {

    std::cout << "----------------------------------\n"; 
    std::cout << "\tRECURSIVIDAD 2\n"; 
    std::cout << "----------------------------------\n\n"; 


    // PruebaSwap();
    PruebaSwap2();

    std::cout << "\n----------------------------------\n"; 


    return EXIT_SUCCESS;
}

/**
 * OPERADOR * Indireccion
 * OPERADOR & Desreferenciacion
 * 
 */
void Swap(bool* pA, bool* pB) {
    bool aux = *pA;
    *pA = *pB;
    *pB = aux;
}

void Swap2(bool** pA, bool** pB) {
    bool* aux = *pA;
    *pA = *pB;
    *pB = aux;
}

void Swap3(bool* pA, bool* pB) {
    bool* aux = pA;
    pA = pB;
    pB = aux;
}

void PruebaSwap() {
    bool verdadero = true;
    bool falso = false;

    cout << "Verdadero: " << verdadero << endl;
    cout << "Falso: " << falso << endl;

    Swap(&verdadero, &falso);

    cout << "Verdadero: " << verdadero << endl;
    cout << "Falso: " << falso << endl;

}

void PruebaSwap2() {
    bool verdadero = true;
    bool falso = false;
    bool *pVerdadero = &verdadero;
    bool *pFalso = &falso;

    cout << "Verdadero: " << verdadero << " - Apunta a: " << pVerdadero << endl;
    cout << "Falso:" << falso << " - Apunta a: " << pFalso << endl;
    std::cout << "\n----------------------------------\n\n"; 

    Swap2(&pVerdadero, &pFalso);

    cout << "Verdadero: " << verdadero << " - Apunta a: " << pVerdadero << endl;
    cout << "Falso:" << falso << " - Apunta a: " << pFalso << endl;
 

}

