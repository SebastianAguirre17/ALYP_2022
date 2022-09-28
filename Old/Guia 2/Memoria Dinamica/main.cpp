#include <iostream>

using namespace std;


const int TopeCartas = 48;
const int ValorComodin = -1;

enum TipoPalo { COPA, BASTO, ORO, ESPADA };

struct Carta {
    int valor;
    TipoPalo palo;
};

struct Mazo {
    Carta cartas[TopeCartas];
    int cantidadCartas;
};

Carta* CrearCarta(int valor, TipoPalo palo);
void MostrarCarta(const Carta* carta);

int main() {

    std::cout << "\tMEMORIA DINAMICA\n";

    Carta* unoOro = CrearCarta(1, ORO);
    MostrarCarta(unoOro);

    Carta* sieteEspada = CrearCarta(7, ESPADA);
    MostrarCarta(sieteEspada);

    return EXIT_SUCCESS;
}

/* 
    Patron de Diseno
    Nombre: Factory Method - Funcion Creacional
    Problema que resuelve: Crar instancias validas de un tipo de dato.
    Solucion: Centralizar la creacion en una funcion.
*/

// Precondicion: -
// Postcondicion: Devuelve una instancia valida del tipo de dato Carta
// Si el valor es invalido devuelve NULL.
Carta* CrearCarta(int valor, TipoPalo palo) {
    Carta* nuevaCarta = NULL; // nullptr
    if (valor >= 1 and valor <= 12) {
        nuevaCarta = new Carta;
        nuevaCarta->valor = valor;
        nuevaCarta->palo = palo;
    }
    return nuevaCarta;
}

Carta* CrerComidin() {
    Carta* comodin = new Carta;
    comodin->valor = ValorComodin;
    return comodin;
}

void EliminarCarta(Carta* carta) {
    delete carta;
}

void MostrarCarta(const Carta* carta) {
    cout << carta-> valor << " de ";
    switch (carta->palo) {
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
