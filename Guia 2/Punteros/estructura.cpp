#include <iostream>

using namespace std;


const int TopeCartas = 48;

enum TipoPalo { COPA, BASTO, ORO, ESPADA };

struct Carta {
    int valor;
    TipoPalo palo;
};

struct Mazo {
    Carta cartas[TopeCartas];
    int cantidadCartas;
};

void MostrarCarta(const Carta* carta);


int main() {

    std::cout << "--------------------------------------------------\n";
    std::cout << "\n   PUNTEROS - CONSTANTES\n";
    std::cout << "--------------------------------------------------\n\n";

    Carta unoOro;
    unoOro.palo = ORO;
    unoOro.valor = 1;
    
    MostrarCarta(&unoOro);

    Carta* pCarta = &unoOro;
    pCarta->valor = 7;
    pCarta->palo = ESPADA;

    MostrarCarta(pCarta);



    std::cout << "\n--------------------------------------------------\n";




    return EXIT_SUCCESS;
}

void MostrarCarta(const Carta* carta) {
    cout << carta-> valor << " de ";
    switch (carta->palo)
    {
        case ESPADA: cout << "Espada" << endl;
            break;
        case ORO: cout << "Oro" << endl;
            break;
        case COPA: cout << "Copa" << endl;
            break;
        case BASTO: cout << "Basto" << endl;
            break;
    }
}
