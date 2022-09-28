#include <iostream>
#include <random>
#include <ctime>

#define MAX 50

/*

2. Implementar las siguientes funciones, tenga en cuenta que no pudeutilizar
ninguna libreria auxiliar:
● bool SonIguales(char cadena1[], char cadena2[]); la cual devuelve true si dos
cadenas son iguales y los parametros cadena1 y cadena 2 son cadena de
caracteres
● bool ContieneSubTexto(char texto[], char subTexto); la cual devuelve true si
subTexto se encuentra dentro de texto*/

int ContarChars(char cadena[]);
int ObtenerNumeroAleatorioPar();
bool SonIguales(char cadena1[], char cadena2[]);
bool ContieneSubTexto(char texto[], char subTexto);

int main(int argc, char const *argv[]) {

    char cadena[] = "Esto es una cadena de texto";
    char buscado;

    std::cout << ContarChars(cadena);
/*
    do {
        std::cout << "Caracter: ";
        std::cin >> buscado;
        ContieneSubTexto(cadena, buscado) ? 
            std::cout << "True" << std::endl : 
            std::cout << "False" << std::endl;

    } while (buscado != '*');*/
        
    


    return 0;
}

int ContarChars(char cadena[]) {
    int i = 0;
    while (cadena[i] != '\n') {
        i++;
    }
    return i;
}

int ObtenerNumeroAleatorioPar() {
    std::srand(std::time(nullptr));
    int num = rand() % MAX;
    return num % 2 == 0 ? num : num - 1;
}

bool SonIguales(char cadena1[], char cadena2[]) {
    
}

bool ContieneSubTexto(char texto[], char subTexto) {
    int i = 0, len = ContarChars(texto);
    while (len > 0 and texto[i] != '\n' and texto[i] != subTexto and i < len) {
        i++;
    }
    return (len > 0 and len != i);
}