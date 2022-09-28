#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int TopeCartas = 48;

enum TipoPalo { COPA, BASTO, ORO, ESPADA };

struct Carta {
    int numero;
    TipoPalo palo;
};

struct Mazo {
    Carta cartas[TopeCartas];
    int cantidadCartas;
};

void InicializarMazoVacio(Mazo& mazo);
void LlenarMazoNevo(Mazo& mazo);
void Ordenar(Mazo& mazo);
void Mezclar(Mazo& mazo);
void AgragarCarta(Mazo& mazo, Carta carta);
Carta QuitarCarta(Mazo& mazo);
void InicilizarNumeros(Mazo& mazo); 
void InicializarPalos(Mazo& mazo);
void MostrarMazo(Mazo& mazo);
bool EstaVacio(Mazo mazo);

int main() {
    Mazo mazo;
    LlenarMazoNevo(mazo);
    MostrarMazo(mazo);

    Carta carta = QuitarCarta(mazo);
    carta = QuitarCarta(mazo);
    carta = QuitarCarta(mazo);
    carta = QuitarCarta(mazo);
        MostrarMazo(mazo);

    return EXIT_SUCCESS;
}

void InicializarPalos(Mazo& mazo) {
    for (int i = 0; i <= TopeCartas; ++i) {
        if(i <= 11)
            mazo.cartas[i].palo = COPA;
        if(i > 11 and i <= 23)
            mazo.cartas[i].palo = BASTO;
        if(i > 23 and i <= 35)
            mazo.cartas[i].palo = ORO;
        if(i > 35)
            mazo.cartas[i].palo = ESPADA;
    }
}

void InicilizarNumeros(Mazo& mazo) {
    for (int i = 0, numeroCarta = 1; i < TopeCartas; i++, numeroCarta++) {
        mazo.cartas[i].numero = numeroCarta;
        if(i == 11 or i == 23 or i == 35) {
			numeroCarta = 0;
		}        
    }
}

void LlenarMazoNevo(Mazo& mazo) {
    InicializarPalos(mazo);
    InicilizarNumeros(mazo);
    mazo.cantidadCartas = TopeCartas;
}

Carta QuitarCarta(Mazo& mazo) {
    if (not EstaVacio(mazo)) {
        Carta retorno = mazo.cartas[0];
        mazo.cantidadCartas--; 
        for (int i = 0; i < mazo.cantidadCartas; i++) {
            mazo.cartas[i] = mazo.cartas[i + 1];
        }
        return retorno;
    }
}

void MostrarMazo(Mazo& mazo) {
    cout << "-----------------------------------------------" << endl;
    cout << "\t\tMazo de Cartas" << endl;
    cout << "-----------------------------------------------" << endl << endl;
    for (int i = 0; i < mazo.cantidadCartas; i++) {
        cout << "Numero: " << mazo.cartas[i].numero << " - Palo: " << mazo.cartas[i].palo << endl;
    }
}

bool EstaVacio(Mazo mazo) {
    return mazo.cantidadCartas == 0;
}