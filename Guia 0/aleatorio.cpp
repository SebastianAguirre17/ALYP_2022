#include <iostream>

#define MAX 100
/*
1. Implementar la funcion: int ObtenerNumeroAleatorioPar(). La cual no recibe
parametros y debe retornar un numero par aleatorio. Puede utilizar cualquier libreria
auxiliar.
2. Implementar las siguientes funciones, tenga en cuenta que no pudeutilizar
ninguna libreria auxiliar:
● bool SonIguales(char cadena1[], char cadena2[]); la cual devuelve true si dos
cadenas son iguales y los parametros cadena1 y cadena 2 son cadena de
caracteres
● bool ContieneSubTexto(char texto[], char subTexto); la cual devuelve true si
subTexto se encuentra dentro de texto*/

int ObtenerNumeroAleatorioPar() {
    int num = rand() % MAX;
    return num % 2 == 0 ? num : num - 1;
}

bool SonIguales(char cadena1[], char cadena2[]) {
    
}

int main(int argc, char const *argv[]) {
    

    return 0;
}
